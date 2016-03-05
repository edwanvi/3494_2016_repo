#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* controller;
	Joystick* controller_2;
public:
	JoystickButton* buttonA;
	JoystickButton* buttonB;
	JoystickButton* buttonX;
	JoystickButton* buttonY;
	JoystickButton* buttonLB;
	JoystickButton* buttonRB;
	JoystickButton* buttonStart;
	JoystickButton* buttonSelect;

	JoystickButton* buttonA_2;
	JoystickButton* buttonB_2;
	JoystickButton* buttonX_2;
	JoystickButton* buttonY_2;
	JoystickButton* buttonLB_2;
	JoystickButton* buttonRB_2;
	JoystickButton* buttonStart_2;
	JoystickButton* buttonSelect_2;
	OI();
	double GetLeftJoystick();
	double GetRightJoystick();
	double GetLeftTrigger();
	double GetRightTrigger();
	double GetLeftJoystick_2();
	double GetRightJoystick_2();
	int GetDPad();
	int GetDPad_2();
	double GetLeftTrigger_2();
	double GetRightTrigger_2();
	double GetLeftBumper();
	double GetRightBumper();
	double GetRightJoystickStrafe();

};

#endif
