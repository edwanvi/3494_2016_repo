#include "OI.h"
#include "Commands/Roller/RunRollers.h"
#include "Commands/Drive/Shift_Gear.h"
#include "Commands/Diagnostics/SystemsCheck.h"
#include "Commands/climb/Lift_Set.h"

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

	buttonA_2 = new JoystickButton(controller_2, 2);//2  //  xbox
	buttonB_2 = new JoystickButton(controller_2, 3);
	buttonX_2 = new JoystickButton(controller_2, 1);
	buttonY_2 = new JoystickButton(controller_2, 4);
	buttonLB_2 = new JoystickButton(controller_2, 5);
	buttonRB_2 = new JoystickButton(controller_2, 6);
	buttonStart_2 = new JoystickButton(controller_2, 8);
	buttonSelect_2 = new JoystickButton(controller_2, 7);

	//buttonLB->WhenPressed(new RunRollers(true));
	//buttonRB->WhenPressed(new RunRollers(false));
	//gear down
	buttonX->WhenPressed(new Shift_Gear(true));
	//gear up
	buttonB->WhenPressed(new Shift_Gear(false));

	buttonY->WhenPressed(new Lift_Set(true));

	buttonA->WhenPressed(new Lift_Set(false));

	//Run the system checks. Best done when driving
	buttonStart_2->WhenPressed(new SystemsCheck(true));
	buttonSelect_2->WhenPressed(new SystemsCheck(false));
}
//these methods all basically do what they say they do in their name so yeah
double OI::GetLeftJoystick() {
	return 1 * controller->GetRawAxis(1);
}

double OI::GetRightJoystick() {
	return -1 * controller->GetRawAxis(5);
}

double OI::GetLeftJoystick_2(){
	return -1 * controller_2->GetRawAxis(1);
}

double OI::GetRightJoystick_2(){
	return -1 * controller_2->GetRawAxis(5);
}

double OI::GetLeftTrigger() {
	return controller->GetRawAxis(2);
}

double OI::GetRightTrigger() {
	return controller->GetRawAxis(3);
}
int OI::GetDPad_2() {
	return controller_2->GetPOV();
}

int OI::GetDPad() {
	return controller->GetPOV();
}
double OI::GetLeftTrigger_2() {
	return controller_2->GetRawAxis(2);
}

double OI::GetRightTrigger_2() {
	return controller_2->GetRawAxis(3);
}

double OI::GetLeftBumper() {
	return controller->GetRawButton(5);
}

double OI::GetRightBumper() {
	return controller->GetRawButton(6);
}
