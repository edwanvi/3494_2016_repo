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
	float GetLeftJoystick();
	float GetRightJoystick();
	float GetLeftTrigger();
	float GetRightTrigger();
	float GetLeftJoystick_2();
	float GetRightJoystick_2();
	int GetDPad();
	int GetDPad_2();
	float GetLeftTrigger_2();
	float GetRightTrigger_2();
	float GetLeftBumper();
	float GetRightBumper();
	float GetRightJoystickStrafe();

};

#endif
