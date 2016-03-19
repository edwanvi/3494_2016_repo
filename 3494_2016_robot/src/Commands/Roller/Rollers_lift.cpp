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
int dpad = oi->GetDPad();

if (dpad == 0){
	CommandBase::roller->Roller_Lift(1);

}
else if (dpad == 90){
	CommandBase::roller->Roller_Lift(-1);
}
else {
	CommandBase::roller->Roller_Lift(0);
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
