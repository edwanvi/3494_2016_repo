#include "SystemsCheck.h"

SystemsCheck::SystemsCheck(bool _right)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	SmartDashboard::init();
	Requires(CommandBase::driveTrain);
	right = _right;
	rightCurrent = 0;
	leftCurrent = 0;
}

// Called just before this Command runs the first time
void SystemsCheck::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SystemsCheck::Execute()
{
	if (right){
		rightCurrent = driveTrain->PowerSide(1);
	}
	else {
		leftCurrent = driveTrain->PowerSide(0);
	}
	SmartDashboard::PutNumber("Left Current", leftCurrent);
	SmartDashboard::PutNumber("Right Current", rightCurrent);
}

// Make this return true when this Command no longer needs to run execute()
bool SystemsCheck::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SystemsCheck::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SystemsCheck::Interrupted()
{

}
