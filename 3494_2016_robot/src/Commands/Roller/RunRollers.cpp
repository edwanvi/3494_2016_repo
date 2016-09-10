#include "RunRollers.h"

RunRollers::RunRollers() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::roller);
	mode = 0;
}

// Called just before this Command runs the first time
void RunRollers::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void RunRollers::Execute() {
	if (oi->GetRightTrigger()){
		CommandBase::roller->Roll(true, .95);
		mode = 1;
	}
	else if (oi->GetRightTrigger_2()){
		CommandBase::roller->Roll(false, .95);
		mode = 2;
	}

	if (CommandBase::oi->GetDPad()) {
		new Rollers_lift();
	}
	//CommandBase::roller->Roll(direction);
}

// Make this return true when this Command no longer needs to run execute()
bool RunRollers::IsFinished() {
	if (!oi->GetRightTrigger() && mode == 1) {
		return true;
	} else if (!oi->GetRightTrigger_2() && mode == 2) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void RunRollers::End() {
	mode = 0;
	CommandBase::roller->Roll(false, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunRollers::Interrupted() {
}
