#include <Commands/Roller/RunRollers.h>

RunRollers::RunRollers()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::roller);
	mode = 0;
}

// Called just before this Command runs the first time
void RunRollers::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RunRollers::Execute()
{

	if (oi->GetLeftBumper()){
			CommandBase::roller->Roll(true, 0.75);
			mode = 1;
		}
		else if (oi->GetRightBumper()){
			CommandBase::roller->Roll(false, 0.75);
			mode = 2;
		}

/*	if (CommandBase::oi->GetLeftJoystick() || CommandBase::oi->GetLeftJoystick())
		{
		new Rollers_lift();
		}

*/

	//CommandBase::roller->Roll(direction);
}

// Make this return true when this Command no longer needs to run execute()
bool RunRollers::IsFinished()
{
	if (!oi->GetLeftBumper() && mode == 1)
	{
		return true;
	}

	if (!oi->GetRightBumper() && mode == 2)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void RunRollers::End()
{
	mode = 0;
	CommandBase::roller->Roll(false, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunRollers::Interrupted()
{

}
