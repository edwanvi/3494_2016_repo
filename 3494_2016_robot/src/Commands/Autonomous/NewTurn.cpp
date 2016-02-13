#include "NewTurn.h"

NewTurn::NewTurn(bool _left, double time, float _speed){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::driveTrain);
	//true is left
	left = _left;
	//time to spend turning, in seconds.
	letime = time;
	//Speed at which to turn. Make sure this is > 0.
	speed = _speed;
}

// Called just before this Command runs the first time
void NewTurn::Initialize()
{
	CommandBase::driveTrain->ResetEncoders();
	if (speed < 0) {
		speed = speed * -1;
	}
}

// Called repeatedly when this Command is scheduled to run
void NewTurn::Execute()
{
	if (left) {
		CommandBase::driveTrain->TankDrive(0, speed * -1);
	}
	else {
		CommandBase::driveTrain->TankDrive(0, speed);
	}
	Wait(letime);
	CommandBase::driveTrain->TankDrive(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool NewTurn::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void NewTurn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NewTurn::Interrupted()
{

}
