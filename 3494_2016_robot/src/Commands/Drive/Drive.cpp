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
	int dpad_2 = oi->GetDPad_2();
	float leftThrottle =oi->GetJoystickY();
	float rightThrottle =oi->GetJoystick_2Y();
	CommandBase::driveTrain->TankDrive(leftThrottle, rightThrottle);

	//DPAD_DRIVE steering.

	if (dpad_2 == 0){
		CommandBase::driveTrain->TankDrive(-DPAD_DRIVE, DPAD_DRIVE);
	}
	else if (dpad_2 == 180){
		CommandBase::driveTrain->TankDrive(DPAD_DRIVE, -DPAD_DRIVE);
	}
	else if (dpad_2 == 90){
		CommandBase::driveTrain->TankDrive(-DPAD_DRIVE, -DPAD_DRIVE);
	}
	else if (dpad_2 == 270){
		CommandBase::driveTrain->TankDrive(DPAD_DRIVE, DPAD_DRIVE);
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
