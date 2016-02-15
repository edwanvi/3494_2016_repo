#include "DriveTrain.h"
#include "../RobotMap.h"
#include "math.h"
#include "Commands/Drive/Drive.h"

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain")
{
////////////////////////////////////////////////////////////
	LeftTalonMaster = new CANTalon(LEFT_MOTOR_MASTER);			//	Left CANTalon motor subgroup
	LeftTalonFollower = new CANTalon(LEFT_MOTOR_FOLLOWER);		//	1 talon is assigned for each CIM
	LeftTalonFollower_2 = new CANTalon(LEFT_MOTOR_FOLLOWER_2);	//	3 CIM per gearbox
	LeftTalonMaster->EnableControl();
	LeftTalonMaster->SetSafetyEnabled(false);
	LeftTalonFollower->EnableControl();
	LeftTalonFollower->SetControlMode(CANSpeedController::kFollower);
	LeftTalonFollower->Set(LEFT_MOTOR_MASTER);
	LeftTalonFollower_2->EnableControl();
	LeftTalonFollower_2->SetControlMode(CANSpeedController::kFollower);
	LeftTalonFollower_2->Set(LEFT_MOTOR_MASTER);
////////////////////////////////////////////////////////////
	RightTalonMaster = new CANTalon (RIGHT_MOTOR_MASTER);		//	Right Talon motor subgroup
	RightTalonFollower = new CANTalon(RIGHT_MOTOR_FOLLOWER);	//	Same parameters as for the Left talons
	RightTalonFollower_2 = new CANTalon(RIGHT_MOTOR_FOLLOWER_2);
	RightTalonMaster->EnableControl();
	RightTalonMaster->SetSafetyEnabled(false);
	RightTalonFollower->EnableControl();
	RightTalonFollower->SetControlMode(CANSpeedController::kFollower);
	RightTalonFollower->Set(RIGHT_MOTOR_MASTER);
	RightTalonFollower_2->EnableControl();
	RightTalonFollower_2->SetControlMode(CANSpeedController::kFollower);
	RightTalonFollower_2->Set(RIGHT_MOTOR_MASTER);
////////////////////////////////////////////////////////////
	pdp = new PowerDistributionPanel();
////////////////////////////////////////////////////////////
	SmartDashboard::init();
////////////////////////////////////////////////////////////
}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void DriveTrain::TankDrive(float leftAxis, float rightAxis)
{
// Monitors the total current draw of the robot
	SmartDashboard::PutNumber("Current",PowerDistOutput() );

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
