#include "Move_Check.h"
#include "../../Subsystems/DriveTrain.h"
#include "ctime"

Move_Check::Move_Check(float _time, bool _direction)
{
	duration = 0;
	start = std::clock();
	Requires(CommandBase::driveTrain);
	letime = _time;
	direction = _direction;
}

// Called just before this Command runs the first time
void Move_Check::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Move_Check::Execute()
{
	while()
	if (direction) {
		CommandBase::driveTrain->TankDrive(-.75, .75);
	} else {
		CommandBase::driveTrain->TankDrive(.75,-.75);
	}
	duration = (std::clock - start)/ CLOCKS_PER_SEC;

	if (duration >= time)
	{
		CommandBase::driveTrain->TankDrive(0,0);

	}


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
