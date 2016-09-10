#include "Fail_NavX.h"

Fail_NavX::Fail_NavX(bool fail_)
{
	fail = fail_;
	// Use Requires() here to declare subsystem dependencies
	 Requires(driveTrain);
}

// Called just before this Command runs the first time
void Fail_NavX::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Fail_NavX::Execute()
{
	driveTrain->Fail_NavX(fail);
}

// Make this return true when this Command no longer needs to run execute()
bool Fail_NavX::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Fail_NavX::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fail_NavX::Interrupted()
{

}
