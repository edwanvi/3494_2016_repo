#include "cam.h"

cam::cam(bool _mode)
{
	mode = _mode;
	// Use Requires() here to declare subsystem dependencies
	Requires(climber);
	SmartDashboard::init();
	camera = new DoubleSolenoid(CAM_1, CAM_2);
}

// Called just before this Command runs the first time
void cam::Initialize()
{
	SmartDashboard::init();
}

// Called repeatedly when this Command is scheduled to run
void cam::Execute()
{
	if (mode){
		camera->Set(camera->kForward);
		SmartDashboard::PutBoolean("Camera Up", true);
	}
	else if (!mode) {
		camera->Set(camera->kReverse);
		SmartDashboard::PutBoolean("Camera Up", false);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool cam::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void cam::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cam::Interrupted()
{

}
