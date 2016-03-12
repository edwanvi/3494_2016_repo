#include "Shift_Gear.h"

Shift_Gear::Shift_Gear(bool _mode)
{
	mode = _mode;
	// Use Requires() here to declare subsystem dependencies
	Requires(driveTrain);
	SmartDashboard::init();
}

// Called just before this Command runs the first time
void Shift_Gear::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Shift_Gear::Execute()
{
	CommandBase::driveTrain->ChangeGear(mode);
	SmartDashboard::PutBoolean("High Gear", mode);
}

// Make this return true when this Command no longer needs to run execute()
bool Shift_Gear::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Shift_Gear::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shift_Gear::Interrupted()
{

}
