#include "RunRollers.h"

RunRollers::RunRollers(bool direction)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	bool forward = direction;
}

// Called just before this Command runs the first time
void RunRollers::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RunRollers::Execute()
{
	CommandBase::roller->Roll(forward);

	
}

// Make this return true when this Command no longer needs to run execute()
bool RunRollers::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RunRollers::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunRollers::Interrupted()
{

}
