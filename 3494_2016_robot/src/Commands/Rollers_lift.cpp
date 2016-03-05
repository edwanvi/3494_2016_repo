#include "Rollers_lift.h"

Rollers_lift::Rollers_lift()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::roller);
	roller_lift_magnitude = 0;
}

// Called just before this Command runs the first time
void Rollers_lift::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Rollers_lift::Execute()
{

	if(oi->GetRightTrigger > .25)
	{
		roller_lift_magnitude = oi->GetRightTrigger();
	}
	else if (oi->GetLeftTrigger() > .25)
	{
		roller_lift_magnitude = -oi->GetLeftTrigger();
	}
	else
	{
		roller_lift_magnitude = 0;
	}


}

// Make this return true when this Command no longer needs to run execute()
bool Rollers_lift::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Rollers_lift::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Rollers_lift::Interrupted()
{

}
