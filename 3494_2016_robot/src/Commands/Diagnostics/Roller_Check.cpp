#include "Roller_Check.h"

Roller_Check::Roller_Check(float _time)
{
	// Use Requires() here to declare subsystem dependencies
	test_time = _time;
	Requires(roller);
}

// Called just before this Command runs the first time
void Roller_Check::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Roller_Check::Execute()
{
	roller->CheckRoll(test_time); // rolls for 1 second
}

// Make this return true when this Command no longer needs to run execute()
bool Roller_Check::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Roller_Check::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Roller_Check::Interrupted()
{

}
