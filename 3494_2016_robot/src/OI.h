#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* controller;
	Joystick* controller_2;
public:
	JoystickButton* button1;
	JoystickButton* button2;
	JoystickButton* button3;
	JoystickButton* button4;
	JoystickButton* button5;
	JoystickButton* button6;
	JoystickButton* button7;
	JoystickButton* button8;
	JoystickButton* button9;
	JoystickButton* button10;
	JoystickButton* button11;
	JoystickButton* button12;

	JoystickButton* button1_2;
	JoystickButton* button2_2;
	JoystickButton* button3_2;
	JoystickButton* button4_2;
	JoystickButton* button5_2;
	JoystickButton* button6_2;
	JoystickButton* button7_2;
	JoystickButton* button8_2;
	JoystickButton* button9_2;
	JoystickButton* button10_2;
	JoystickButton* button11_2;
	JoystickButton* button12_2;

	OI();
	float GetLeftJoystick();
	float GetRightJoystick();
	double GetLeftTrigger();
	double GetRightTrigger();
	double GetLeftJoystick_2();
	double GetRightJoystick_2();
	int GetDPad();
	int GetDPad_2();
	double GetLeftTrigger_2();
	double GetRightTrigger_2();
	float GetLeftBumper();
	float GetRightBumper();
	double GetRightJoystickStrafe();
	float GetSelect();
	float GetX();
	float GetB();
};

#endif
