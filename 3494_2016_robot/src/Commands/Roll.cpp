#include "Roll.h"

Roll::Roll()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::rollers);
}

// Called just before this Command runs the first time
void Roll::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Roll::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Roll::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Roll::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Roll::Interrupted()
{

}
