#include "Lifting.h"
#include "OI.h"
Lifting::Lifting(bool _mode)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(lift);

	bool mode = _mode;
}

// Called just before this Command runs the first time
void Lifting::Initialize()
{


}

// Called repeatedly when this Command is scheduled to run
void Lifting::Execute()
{
	/*
	int dpad = oi->GetDPad();

	if (dpad == 0){
			CommandBase::lift->Lift(1);
		}
		else if (dpad == 180){
			CommandBase::driveTrain->TankDrive(0.5, -0.5);
		}
		else if (dpad == 90){
			CommandBase::driveTrain->TankDrive(-0.5, -0.5);
		}
		else if (dpad == 270){
			CommandBase::driveTrain->TankDrive(0.5, 0.5);
		}

*/
}

// Make this return true when this Command no longer needs to run execute()
bool Lifting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Lifting::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lifting::Interrupted()
{

}
