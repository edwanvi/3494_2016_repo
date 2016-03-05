#include "Subsystems/Rollers.h"
#include "../src/Commands/RunRollers.h"
#include "../RobotMap.h"

Rollers::Rollers() :
		Subsystem("Rollers")
{
	//create a talon object to control the rollers
	talon_rollers = new CANTalon(ROLLERS_MOTOR);
	talon_rollers -> EnableControl();
	talon_rollers -> SetSafetyEnabled(false);

	talon_rollers_2 = new CANTalon(ROLLERS_MOTOR_2);
	talon_rollers_2 -> EnableControl();
	talon_rollers_2 -> SetSafetyEnabled(false);

	pdp = new PowerDistributionPanel();

	leftCurrent = 0.0;
	 rightCurrent = 0.0;
	 bCheck = false;
	 timeElapsed = 0.0;
}

void Rollers::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new RunRollers());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Rollers::Roll(bool forward, double _speed){
	speed = _speed;
	if (forward == true){
		talon_rollers->Set(speed);
		talon_rollers_2->Set(-speed);
	}
	else {
		talon_rollers->Set(-speed);
		talon_rollers_2->Set(speed);
	}
}

bool Rollers::CheckRoll(double _duration)
{
	duration = _duration;
	start = std::clock();
	while(timeElapsed <= _duration)
	  {

		Roll(true, 0.1);
		//again no idea which roller is which
		leftCurrent = pdp->GetCurrent(ROLLERS_MOTOR);
		rightCurrent = pdp->GetCurrent(ROLLERS_MOTOR_2);
		SmartDashboard::PutNumber("Roller_Current", leftCurrent);
		SmartDashboard::PutNumber("Roller_Current_2", rightCurrent);

timeElapsed = (std::clock() + start)/(double)CLOCKS_PER_SEC;
	}
//dont know proper current check
if (abs(leftCurrent- rightCurrent) <= 2.0f)
{
bCheck = true;
}

return bCheck;
}
