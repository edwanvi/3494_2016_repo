#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* controller;
	Joystick* controller_2;
	Joystick* controller_3;
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

	JoystickButton*buttonA_3;
	JoystickButton*buttonB_3;
	JoystickButton*buttonX_3;
	JoystickButton*buttonY_3;
	JoystickButton*buttonRB_3;
	JoystickButton*buttonLB_3;
	JoystickButton*buttonSelect_3;
	JoystickButton*buttonStart_3;

	OI();
	float GetJoystickY();
	//float GetRightJoystick();
	double GetLeftTrigger();
	double GetRightTrigger();
	double GetJoystick_2Y();
	//double GetRightJoystick_2();
	int GetDPad();
	int GetDPad_2();
	double GetLeftTrigger_2();
	double GetRightTrigger_2();
	float GetLeftBumper();
	float GetRightBumper();
	double GetRightJoystickStrafe();
	float Get11();
	//float GetX();
	//float GetB();
};

#endif
