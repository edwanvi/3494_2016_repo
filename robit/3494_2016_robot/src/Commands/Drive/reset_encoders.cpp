#include "reset_encoders.h"

reset_encoders::reset_encoders()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void reset_encoders::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void reset_encoders::Execute()
{
	driveTrain->ResetEncoders();
}

// Make this return true when this Command no longer needs to run execute()
bool reset_encoders::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void reset_encoders::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void reset_encoders::Interrupted()
{

}
