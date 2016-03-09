#include "CommandWinch.h"
#include "../../OI.h"

CommandWinch::CommandWinch()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::climber);
}

// Called just before this Command runs the first time
void CommandWinch::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CommandWinch::Execute()
{
	int dpad = oi->GetDPad_2();
	if (dpad == 0){
		climber->Winch(true);
	}
	else if (dpad == 180){
		climber->Winch(false);
	}
	else {
		climber->StopWinch();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CommandWinch::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CommandWinch::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CommandWinch::Interrupted()
{

}
