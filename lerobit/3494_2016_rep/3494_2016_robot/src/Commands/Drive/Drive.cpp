#include "Drive.h"
#include "../../RobotMap.h"

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

	//dpad steering.

	if (dpad == 0){
		CommandBase::driveTrain->TankDrive(-DPAD, DPAD);
	}
	else if (dpad == 180){
		CommandBase::driveTrain->TankDrive(DPAD, -DPAD);
	}
	else if (dpad == 90){
		CommandBase::driveTrain->TankDrive(-DPAD, -DPAD);
	}
	else if (dpad == 270){
		CommandBase::driveTrain->TankDrive(DPAD, DPAD);
	}
	SmartDashboard::PutNumber("Encoder_Position", driveTrain->Encoder_Position());
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