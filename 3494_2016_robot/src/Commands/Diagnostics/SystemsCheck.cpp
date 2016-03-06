#include "SystemsCheck.h"
#include "Move_Check.h"
#include "Roller_Check.h"


SystemsCheck::SystemsCheck(bool _right)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::driveTrain);
	right = _right;
	rightCurrent = 0;
	leftCurrent = 0;
	drivetrain = new DriveTrain();
	rollers = new Rollers();


}

// Called just before this Command runs the first time
void SystemsCheck::Initialize()
{
	SmartDashboard::init();

}


// Called repeatedly when this Command is scheduled to run
void SystemsCheck::Execute()
{
SmartDashboard::PutData("Test DriveTrain",new Move_Check(5.0f)) ; // drives for 5 seconds
SmartDashboard::PutData("Test Roller", new Roller_Check(1)); // rolls for 1 second
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
