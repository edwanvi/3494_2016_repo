#include "../Commands/Roller/Rollers_lift.h"
#include "../Commands/Roller/RunRollers.h"
#include "../Subsystems/Rollers.h"
#include "../RobotMap.h"
#include "../OI.h"

Rollers::Rollers() :
		Subsystem("Rollers")
{
	//create a talon object to control the rollers lift
	talon_rollers_lift_left = new CANTalon(ROLLERS_MOTOR_LIFT_LEFT);
	//talon_rollers_lift_left -> EnableControl();
	talon_rollers_lift_left -> SetSafetyEnabled(false);

	talon_rollers_lift_right = new CANTalon(ROLLERS_MOTOR_LIFT_RIGHT);
	//talon_rollers_lift_right -> EnableControl();
	talon_rollers_lift_right -> SetSafetyEnabled(false);

	roller_left = new CANTalon(ROLLERS_MOTOR_LEFT);	// create talon rollers these are pwm
	roller_right = new CANTalon(ROLLERS_MOTOR_RIGHT);

	pdp = new PowerDistributionPanel(); // for current measuring

	down = 0;

	//make eclipse shut up about variables and constructors. code compiles fine w/out
	//this line
	duration = 0.0;

	leftCurrent = 0.0;
	rightCurrent = 0.0;
	bCheck = false;
	timeElapsed = 0.0;
	SmartDashboard::init();
}

void Rollers::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Rollers_lift());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
// run the rollers forward or back at the specified speed
void Rollers::Roll(bool forward, double _speed) {
	speed = _speed;

	if (forward == true) {
		roller_left->Set(speed);
		roller_right->Set(-speed);
	}
	else {
		roller_left->Set(-speed);
		roller_right->Set(speed);
	}
}
void Rollers::Roller_Lift(float magnitude) {
	// limit = limitSwitchUp
	talon_rollers_lift_left->Set(magnitude);
	talon_rollers_lift_right->Set(-magnitude);

	//down = roller_down->GetVoltage();
	SmartDashboard::PutNumber("Roller down", down);
}

bool Rollers::CheckRoll(double _duration) {
	//duration = _duration;
	//start = std::clock();
	//runs 99 times. hence "button 7" being a swear word.
	for(int a = 0; a < 99; a++) {
		Roll(true, 0.1);
		//again no idea which roller is which
		leftCurrent = pdp->GetCurrent(ROLLERS_MOTOR_LEFT_PDP); // all pwm motors dont have a matching pdp
		rightCurrent = pdp->GetCurrent(ROLLERS_MOTOR_RIGHT_PDP); // ill figure that out soon
		SmartDashboard::PutNumber("Roller_Current", leftCurrent);
		SmartDashboard::PutNumber("Roller_Current_2", rightCurrent);

		//timeElapsed = (std::clock() + start)/(double)CLOCKS_PER_SEC;
	}

	if (abs(leftCurrent- rightCurrent) <= 2.0f) {
		bCheck = true;
	}
	return bCheck;
}
