#include "Turn.h"

Turn::Turn(float _target)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::driveTrain);
	ahrs = new AHRS(SPI::Port::kMXP);
	angle = 0;
	ahrs->Reset();
	speed = .60;
	target = _target;
}

// Called just before this Command runs the first time
void Turn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute()
{
	angle = ahrs->GetAngle();

	SmartDashboard::PutNumber("Angle measure", angle );

	if((angle - target) > 0) // if the angle is past the point or for auto could use the reference angle for switching clockwise or counter clockwise
	{
		driveTrain->TankDrive(speed, - speed);
	}
	else if((angle - target) < 0)
	{
		driveTrain->TankDrive(-speed, speed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished()
{
	if (abs(abs(angle) - abs(target)) >= 5)
	{
		driveTrain->TankDrive(0,0);
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void Turn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted()
{

}
