#include "Roller_Lift_Mid.h"
#include "../../Subsystems/Rollers.h"

Roller_Lift_Mid::Roller_Lift_Mid()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(roller);
	roller_down_sensor = new AnalogInput(ROLLER_DOWN);
	down_voltage = 0;
}

// Called just before this Command runs the first time
void Roller_Lift_Mid::Initialize()
{
	SmartDashboard::init();
}

// Called repeatedly when this Command is scheduled to run
void Roller_Lift_Mid::Execute()
{

	SmartDashboard::PutNumber("RollerDown", roller_down_sensor->GetVoltage());
	down_voltage = roller_down_sensor->GetVoltage(); // grabbing the sensor voltage and establishing an analog
	roller->Roller_Lift(-0.75); // run rollers back; this is meant to establish the rollers at a set position without constant driver input

}

// Make this return true when this Command no longer needs to run execute()
bool Roller_Lift_Mid::IsFinished()
{

/*	if ( down_voltage >= 4.9 || oi->Get11() ) // if the sensor is tripped or stopped by button 11 then the command no longer runs
	{
	roller->Roller_Lift(0); // stop rollers
	return true; // stop command
	}
	else
	{

		return false;
	}
*/
	return false;
}

// Called once after isFinished returns true
void Roller_Lift_Mid::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Roller_Lift_Mid::Interrupted()
{

}
