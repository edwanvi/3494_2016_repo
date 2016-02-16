#include "Drive.h"

Drive::Drive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::driveTrain);
}

// Called just before this Command runs the first time
void Drive::Initialize()
{
	SmartDashboard::init();
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	int dpad = oi->GetDPad();
	float leftThrottle =oi->GetLeftJoystick();
	float rightThrottle =oi->GetRightJoystick();
	CommandBase::driveTrain->TankDrive(leftThrottle, rightThrottle);

	//dpad steering
	/*
	if (dpad == 0){
		CommandBase::driveTrain->TankDrive(-0.5, 0.5);
	}
	else if (dpad == 180){
		CommandBase::driveTrain->TankDrive(0.5, -0.5);
	}
	else if (dpad == 90){
		CommandBase::driveTrain->TankDrive(-0.5, -0.5);
	}
	else if (dpad == 270){
		CommandBase::driveTrain->TankDrive(0.5, 0.5);
	}
	*/
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}
