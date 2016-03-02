#include "DriveTrain.h"
#include "../RobotMap.h"
#include "math.h"
#include "Commands/Drive/Drive.h"
#include "ctime"

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain")
{
////////////////////////////////////////////////////////////
	LeftTalonMaster = new CANTalon(LEFT_MOTOR_MASTER);			//	Left CANTalon motor subgroup
	LeftTalonFollower = new CANTalon(LEFT_MOTOR_FOLLOWER);		//	1 talon is assigned for each CIM
	LeftTalonFollower_2 = new CANTalon(LEFT_MOTOR_FOLLOWER_2);	//	3 CIM per gearbox
	LeftTalonMaster->EnableControl();
	LeftTalonMaster->SetSafetyEnabled(false);
	LeftTalonMaster->SetVoltageRampRate(RAMP);
	LeftTalonFollower->EnableControl();
	LeftTalonFollower->SetControlMode(CANSpeedController::kFollower);
	LeftTalonFollower->Set(LEFT_MOTOR_MASTER);
	LeftTalonFollower_2->EnableControl();
	LeftTalonFollower_2->SetControlMode(CANSpeedController::kFollower);
	LeftTalonFollower_2->Set(LEFT_MOTOR_MASTER);
	LeftTalonFollower_2->SetFeedbackDevice(CANTalon::QuadEncoder);
////////////////////////////////////////////////////////////
	//encoder things
	static double WHEEL_DIAMETER =  3.939;
	static double GEAR_RATIO = 2.65;
	//may need to set to 360
	static double PULSE_PER_REVOLUTION = 256;
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
	RightTalonFollower->SetFeedbackDevice(CANTalon::QuadEncoder);
	RightTalonFollower_2->EnableControl();
	RightTalonFollower_2->SetControlMode(CANSpeedController::kFollower);
	RightTalonFollower_2->Set(RIGHT_MOTOR_MASTER);
	RightTalonMaster->SetVoltageRampRate(RAMP);
////////////////////////////////////////////////////////////
	pdp = new PowerDistributionPanel();
////////////////////////////////////////////////////////////
	SmartDashboard::init();
////////////////////////////////////////////////////////////
	solenoid_Shifter = new DoubleSolenoid(SOL_SHIFTER_1, SOL_SHIFTER_2);
	currentGear = false;
////////////////////////////////////////////////////////////
//for the system check
	bCheck = false;
	rightCurrent = 75.0f;
	leftCurrent = 0.0f;

}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void DriveTrain::TankDrive(float leftAxis, float rightAxis)
{
// Monitors the total current draw of the robot
	SmartDashboard::PutNumber("Current",PowerDistOutput() );

	SmartDashboard::PutNumber("Current_Chan left",PowerSide(0) );
	SmartDashboard::PutNumber("Current_Chan Right", PowerSide(1));
	SmartDashboard::PutNumber("Encoder_Position", Encoder_Position());
// establishes sign value when below zero
// the axis value, which is negative, is negated to be positive
// The value is then taken to a power and then multiplied by the sign value	
	int leftSign = 1;
	int rightSign = 1;
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
	//drive the master talons. the others /will/ follow.
	LeftTalonMaster->Set(leftValue);
	RightTalonMaster->Set(rightValue);
}

int DriveTrain::PowerDistOutput()
{
	return pdp->GetTotalCurrent();
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

	float right_side = pdp->GetCurrent(12) + pdp->GetCurrent(13) + pdp->GetCurrent(14);
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
void DriveTrain::ChangeGear(bool _gear) {
	if (currentGear != _gear)
	{
		if (_gear)
		{
			//shifts up
			solenoid_Shifter->Set(solenoid_Shifter->kReverse);
		}
		else if (!_gear)
		{
			// shifts down
			solenoid_Shifter->Set(solenoid_Shifter->kForward);
		}
		currentGear = _gear;
	}
}
double DriveTrain::GetPosition(){
	return (LeftTalonFollower_2->GetEncPosition() * Rpulse);
}

int DriveTrain::Encoder_Position()
{
	return (Rpulse * RightTalonFollower_2->GetEncPosition());
}
void DriveTrain::ResetEncoders(){
	LeftTalonFollower_2->SetPosition(0);
	RightTalonFollower_2->SetPosition(0);
}

bool DriveTrain::TestDriveTrain(float duration)
{
	for( int a = 0; a < 99; a++ )
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

		SmartDashboard::PutNumber("Right Current 1", pdp->GetCurrent(12));
		SmartDashboard::PutNumber("Right Current 2", pdp->GetCurrent(13));
		SmartDashboard::PutNumber("Right Current 3", pdp->GetCurrent(14));



	}

	if (abs(leftCurrent - rightCurrent) <= 5.0f)
			{
			bCheck = true;
			}
return bCheck;
}
