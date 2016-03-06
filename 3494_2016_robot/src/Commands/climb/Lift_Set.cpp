#include "Lift_Set.h"

Lift_Set::Lift_Set(bool _mode)
{
	mode = _mode;
	// Use Requires() here to declare subsystem dependencies
	Requires(climber);
	SmartDashboard::init();
}

// Called just before this Command runs the first time
void Lift_Set::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Lift_Set::Execute()
{
	CommandBase::climber->Setter(mode);
	SmartDashboard::PutBoolean("Set", mode);

}

// Make this return true when this Command no longer needs to run execute()
bool Lift_Set::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Lift_Set::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lift_Set::Interrupted()
{

}
