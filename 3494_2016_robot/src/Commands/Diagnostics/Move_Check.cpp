#include "Move_Check.h"
#include "../../Subsystems/DriveTrain.h"
#include "ctime"

Move_Check::Move_Check(float _time)
{
	test_time = _time;
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void Move_Check::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Move_Check::Execute()
{
	driveTrain->TestDriveTrain(test_time);
}

// Make this return true when this Command no longer needs to run execute()
bool Move_Check::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Move_Check::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move_Check::Interrupted()
{

}
