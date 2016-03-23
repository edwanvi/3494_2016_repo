#include "Auto_Move_Tim.h"

Auto_Move_Tim::Auto_Move_Tim(float speed_, float time_)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(driveTrain);
	speed = speed_;
	time = time_;
}

// Called just before this Command runs the first time
void Auto_Move_Tim::Initialize()
{
	SmartDashboard::init();
}

// Called repeatedly when this Command is scheduled to run
void Auto_Move_Tim::Execute()
{
	CommandBase::driveTrain->TankDrive(speed, -speed);
	Wait(time);
	//driveTrain->TankDrive(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool Auto_Move_Tim::IsFinished()
{
	CommandBase::driveTrain->TankDrive(0,0);
	return true;
}

// Called once after isFinished returns true
void Auto_Move_Tim::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auto_Move_Tim::Interrupted()
{

}
