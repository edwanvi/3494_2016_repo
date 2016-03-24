#include "DriveTrain.h"
#include "../RobotMap.h"
#include "math.h"
#include "../Commands/Drive/Drive.h"
#include "ctime"
#include "math.h"
DriveTrain::DriveTrain() :
		Subsystem("DriveTrain")
{
	NavXFail = false;
	//ramp = 0;
	timeElapsed = 0.0;
	duration = 0.0;
////////////////////////////////////////////////////////////
	LeftTalonMaster = new CANTalon(LEFT_MOTOR_MASTER);			//	Left CANTalon motor subgroup
	LeftTalonFollower = new CANTalon(LEFT_MOTOR_FOLLOWER);		//	1 talon is assigned for each CIM
	LeftTalonFollower_2 = new CANTalon(LEFT_MOTOR_FOLLOWER_2);	//	3 CIM per gearbox

	LeftTalonMaster->EnableControl();
	LeftTalonMaster->SetSafetyEnabled(false);
	LeftTalonMaster->SetPosition(0);
	LeftTalonFollower->EnableControl();
	LeftTalonFollower->SetControlMode(CANSpeedController::kFollower);
	LeftTalonFollower->Set(LEFT_MOTOR_MASTER);
	LeftTalonFollower_2->EnableControl();
	LeftTalonFollower_2->SetControlMode(CANSpeedController::kFollower);
	LeftTalonFollower_2->Set(LEFT_MOTOR_MASTER);
	LeftTalonMaster->SetFeedbackDevice(CANTalon::QuadEncoder);
////////////////////////////////////////////////////////////
	//encoder things
	static double WHEEL_DIAMETER =  3.939;
	static double GEAR_RATIO = 2.65;
	//may need to set to 360
	static double PULSE_PER_REVOLUTION = 360;
	Rpulse = ((3.14 * (WHEEL_DIAMETER/GEAR_RATIO)) / PULSE_PER_REVOLUTION);
	Lpulse = ((3.14 * (WHEEL_DIAMETER/GEAR_RATIO)) / PULSE_PER_REVOLUTION);
////////////////////////////////////////////////////////////
/*
	LeftTalonMaster->SetVoltageRampRate(RAMP);
	LeftTalonFollower->SetVoltageRampRate(RAMP);
	LeftTalonFollower_2->SetVoltageRampRate(RAMP);
	RightTalonMaster->SetVoltageRampRate(RAMP);
	RightTalonFollower->SetVoltageRampRate(RAMP);
	RightTalonFollower_2->SetVoltageRampRate(RAMP);
*/
////////////////////////////////////////////////////////////
	RightTalonMaster = new CANTalon (RIGHT_MOTOR_MASTER);		//	Right Talon motor subgroup
	RightTalonFollower = new CANTalon(RIGHT_MOTOR_FOLLOWER);	//	Same parameters as for the Left talons
	RightTalonFollower_2 = new CANTalon(RIGHT_MOTOR_FOLLOWER_2);
	RightTalonMaster->EnableControl();
	RightTalonMaster->SetSafetyEnabled(false);
	RightTalonFollower->EnableControl();
	RightTalonFollower->SetControlMode(CANSpeedController::kFollower);
	RightTalonFollower->Set(RIGHT_MOTOR_MASTER);
	RightTalonMaster->SetFeedbackDevice(CANTalon::QuadEncoder);
	RightTalonMaster->SetPosition(0);
	RightTalonFollower_2->EnableControl();
	RightTalonFollower_2->SetControlMode(CANSpeedController::kFollower);
	RightTalonFollower_2->Set(RIGHT_MOTOR_MASTER);
////////////////////////////////////////////////////////////
	pdp = new PowerDistributionPanel();

	//gyro = new AnalogGyro(2);
	//gyro->Reset();
////////////////////////////////////////////////////////////
	SmartDashboard::init();
////////////////////////////////////////////////////////////
//for the system check
	bCheck = false;
	rightCurrent = 75.0f;
	leftCurrent = 0.0f;
	//until we know for sure
	//currentGear = false;

	ahrs = new AHRS(SerialPort::Port::kMXP);
	angle = 0;
	ramp = 0;
	//ahrs->Reset();
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::TankDrive(float leftAxis, float rightAxis)
{
// Monitors the total current draw of the robot use it when needed
	SmartDashboard::PutNumber("Current",PowerDistOutput() );
	SmartDashboard::PutNumber("Encoder", GetPosition());
	SmartDashboard::PutNumber("Current_Chan left",PowerSide(0) );
	SmartDashboard::PutNumber("Current_Chan Right", PowerSide(1));
	SmartDashboard::PutNumber("Encoder_Position", Encoder_Position());
/////////////////////////////////////////////////////////////////////
	angle = ahrs->GetRoll();
	SmartDashboard::PutNumber("Angle measure", angle);
	//LeftTalonMaster->SetVoltageRampRate(ramp);
	//RightTalonMaster->SetVoltageRampRate(ramp);
	//SmartDashboard::PutNumber("angle", gyro->GetAngle());
	SmartDashboard::PutBoolean("NavX Fail", NavXFail);
	// added a prototype that will limit the amount of
	// acceleration depending on the dipping angle of the robot
	// This will defiantly will need tweaked values
	if (!NavXFail)
	{
		if (angle < -7)
		{
			ramp = (25 + (angle)); // the ramp rate will slow down even more if the robot dips more
		}
		else if (angle > 7)
		{
			ramp = (25 - angle); // if the robot dips backwards then this will compensate
		}
		else
		{
			ramp = 0; // if the robot is just fine then there is no ramp rate
		}
	}
	LeftTalonMaster->Set(leftAxis);
	RightTalonMaster->Set(rightAxis);
}

int DriveTrain::PowerDistOutput()
{
	return pdp->GetCurrent(LEFT_MOTOR_FOLLOWER); // displays total pdp current for documenting total draw and brownouts
}

/*int DriveTrain::IndPowerOutput(int PDP_Channel)
{

//Gathers the individual channel
	return pdp->GetCurrent(PDP_Channel);
}
*/

//checks
float DriveTrain::PowerSide(int value)
{
	int value_ = value;
	float left_side = pdp->GetCurrent(LEFT_MOTOR_MASTER) + pdp->GetCurrent(LEFT_MOTOR_FOLLOWER) + pdp->GetCurrent(LEFT_MOTOR_FOLLOWER_2);

	float right_side = pdp->GetCurrent(RIGHT_MOTOR_MASTER) + pdp->GetCurrent(RIGHT_MOTOR_FOLLOWER) + pdp->GetCurrent(RIGHT_MOTOR_FOLLOWER_2);
		// 13 14 15// 0 1 2
	if (value_ == 0)
	{
		return (left_side);
	}
	if (value_ == 1)
	{
		return (right_side);
	}
	else
	{
		return (0);
	}
}


double DriveTrain::GetPosition(){
	return ((-1 * LeftTalonMaster->GetEncPosition() * Rpulse) + (RightTalonMaster->GetEncPosition() * Rpulse));
	//  this will be uncommented when the measurements are correct
}

int DriveTrain::Encoder_Position()
{
	return (LeftTalonMaster->GetEncPosition() * Rpulse);
}
void DriveTrain::ResetEncoders(){
	LeftTalonMaster->SetPosition(0);	// RESET ENCODERS
	RightTalonFollower_2->SetPosition(0);
}

bool DriveTrain::TestDriveTrain(float _duration)
{
	//float duration = _duration;
	//start = std::clock();
	for(int a = 0; a < 99;a++)
	{
		TankDrive(-0.75,0.75);
		rightCurrent = PowerSide(1);
		leftCurrent = PowerSide(0);

		//total motors
		SmartDashboard::PutNumber("Left Current", leftCurrent);
		SmartDashboard::PutNumber("Right Current", rightCurrent);
		//induviddual motors
		SmartDashboard::PutNumber("Left Current 1", pdp->GetCurrent(LEFT_MOTOR_MASTER));
		SmartDashboard::PutNumber("Left Current 2", pdp->GetCurrent(LEFT_MOTOR_FOLLOWER));
		SmartDashboard::PutNumber("Left Current 3", pdp->GetCurrent(LEFT_MOTOR_FOLLOWER_2));

		SmartDashboard::PutNumber("Right Current 1", pdp->GetCurrent(RIGHT_MOTOR_MASTER));
		SmartDashboard::PutNumber("Right Current 2", pdp->GetCurrent(RIGHT_MOTOR_FOLLOWER));
		SmartDashboard::PutNumber("Right Current 3", pdp->GetCurrent(RIGHT_MOTOR_FOLLOWER_2));

		//timeElapsed = (std::clock() + start)/(double)CLOCKS_PER_SEC;
	}

	if (abs(leftCurrent - rightCurrent) <= 5.0f)
	{
		bCheck = true;
	}
	return bCheck;
}
// Put this in the drivetrian function if the robot is running a power of 2
// establishes sign value when below zero
// the axis value, which is negative, is negated to be positive
// The value is then taken to a power and then multiplied by the sign value
/*
	if (leftAxis < 0) {
		leftSign = -1;
		leftAxis = leftAxis * -1;
	}

	if (rightAxis < 0) {
		rightSign = -1;
		rightAxis = rightAxis * -1;
	}

	float leftValue = leftSign * pow(leftAxis, power);

	float rightValue = rightSign * pow(rightAxis, power);
	*/
	//drive the master talons. the others /will/ follow.

void DriveTrain::Fail_NavX(bool fail)
{
	NavXFail = fail;
}
