#include "Auto_Roller_Lift.h"

Auto_Roller_Lift::Auto_Roller_Lift(float time_, float speed_)
{
	// Use Requires() here to declare subsystem dependencies
	 Requires(roller);
	// speed = speed_;
	 time = time_;
	roller_speed = speed_;
}

// Called just before this Command runs the first time
void Auto_Roller_Lift::Initialize()
{
	SmartDashboard::init();

}

// Called repeatedly when this Command is scheduled to run
void Auto_Roller_Lift::Execute()
{
	CommandBase::roller->Roller_Lift(roller_speed);
	Wait(time);
}

// Make this return true when this Command no longer needs to run execute()
bool Auto_Roller_Lift::IsFinished()
{
	CommandBase::roller->Roller_Lift(0);
	return true;;
}

// Called once after isFinished returns true
void Auto_Roller_Lift::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auto_Roller_Lift::Interrupted()
{

}
