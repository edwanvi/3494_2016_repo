#include "Move_Check.h"
#include "../../Subsystems/DriveTrain.h"
#include "ctime"

Move_Check::Move_Check(float _time, bool _direction)
{
	time_loop = true;
	duration = 0;
	rightCurrent = 0;
	leftCurrent = 0;
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
	while(time_loop == true){
		if (direction){
			driveTrain->TankDrive(0.75, -0.75);
			rightCurrent = driveTrain->PowerSide(1);
			leftCurrent = driveTrain->PowerSide(0);
		}
		else {
			driveTrain->TankDrive(-0.75, 0.75);
			rightCurrent = driveTrain->PowerSide(1);
			leftCurrent = driveTrain->PowerSide(0);
		}
		SmartDashboard::PutNumber("Left Current", leftCurrent);
		SmartDashboard::PutNumber("Right Current", rightCurrent);
		//duration = (std::clock - start)/ CLOCKS_PER_SEC;
		if (duration >= time){
		CommandBase::driveTrain->TankDrive(0,0);
		}
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
