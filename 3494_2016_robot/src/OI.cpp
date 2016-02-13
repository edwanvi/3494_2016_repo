#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	//Define controllers as Joystick objects
	controller = new Joystick(0);
	controller_2 = new Joystick(1);

	//Define all the buttons, all of them
	buttonA = new JoystickButton(controller, 1);
	buttonB = new JoystickButton(controller, 2);
	buttonX = new JoystickButton(controller, 3);
	buttonY = new JoystickButton(controller, 4);
	buttonLB = new JoystickButton(controller, 5);
	buttonRB = new JoystickButton(controller, 6);
	buttonStart = new JoystickButton(controller, 8);
	buttonSelect = new JoystickButton(controller, 7);

	buttonA_2 = new JoystickButton(controller_2, 2);//2  //  xbox or whats
	buttonB_2 = new JoystickButton(controller_2, 3);
	buttonX_2 = new JoystickButton(controller_2, 1);
	buttonY_2 = new JoystickButton(controller_2, 4);
	buttonLB_2 = new JoystickButton(controller_2, 5);
	buttonRB_2 = new JoystickButton(controller_2, 6);
	buttonStart_2 = new JoystickButton(controller_2, 8);
	buttonSelect_2 = new JoystickButton(controller_2, 7);

}
