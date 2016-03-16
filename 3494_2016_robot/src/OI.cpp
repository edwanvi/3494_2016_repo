#include "Commands/Roller/RunRollers.h"
#include "Commands/Roller/Roller_Lift_Mid.h"
#include "OI.h"
#include "Commands/Drive/Shift_Gear.h"
#include "Commands/Diagnostics/SystemsCheck.h"
#include "Commands/climb/Lift_Set.h"
#include "Commands/Utilities/cam.h"
#include "Commands/Drive/reset_encoders.h"
#include "Commands/Roller/Rollers_lift.h"

OI::OI()
{
	// Process operator interface input here.
	//Define controllers as Joystick objects
	controller = new Joystick(0);
	controller_2 = new Joystick(1);
	controller_3 = new Joystick(2);

	//Define all the buttons, all of them
	button1 = new JoystickButton(controller, 1);
	button2 = new JoystickButton(controller, 2);
	button3 = new JoystickButton(controller, 3);
	button4 = new JoystickButton(controller, 4);
	button5 = new JoystickButton(controller, 5);
	button6 = new JoystickButton(controller, 6);
	button7 = new JoystickButton(controller, 7);
	button8 = new JoystickButton(controller, 8);
	button9 = new JoystickButton(controller, 9);
	button10 = new JoystickButton(controller, 10);
	button11 = new JoystickButton(controller, 11);
	button12 = new JoystickButton(controller, 12);

	button1_2 = new JoystickButton(controller_2, 1);//2  //  xbox
	button2_2 = new JoystickButton(controller_2, 2);
	button3_2 = new JoystickButton(controller_2, 3);
	button4_2 = new JoystickButton(controller_2, 4);
	button5_2 = new JoystickButton(controller_2, 5);
	button6_2 = new JoystickButton(controller_2, 6);
	button7_2 = new JoystickButton(controller_2, 7);
	button8_2 = new JoystickButton(controller_2, 8);
	button9_2 = new JoystickButton(controller_2, 9);
	button10_2 = new JoystickButton(controller_2, 10);
	button11_2 = new JoystickButton(controller_2, 11);
	button12_2 = new JoystickButton(controller_2, 12);

	buttonA_3 = new JoystickButton(controller_3, 1);
	buttonB_3 = new JoystickButton(controller_3, 2);
	buttonX_3 = new JoystickButton(controller_3, 3);
	buttonY_3 = new JoystickButton(controller_3, 4);
	buttonLB_3 = new JoystickButton(controller_3, 5);
	buttonRB_3 = new JoystickButton(controller_3, 6);
	buttonSelect_3 = new JoystickButton(controller_3, 7);
	buttonStart_3 = new JoystickButton(controller_3, 8);



	button12->WhenPressed(new reset_encoders());

	button3->WhenPressed(new Shift_Gear(true));

	button4->WhenPressed(new Shift_Gear(false));

	//Run the system checks. Best done when driving

	button1->WhenPressed(new RunRollers());
	button1_2->WhenPressed(new RunRollers());

	button12->WhenPressed(new Roller_Lift_Mid);

///////////////////////////
	/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

	buttonB_3->WhenPressed(new Lift_Set(true));
	buttonX_3->WhenPressed(new Lift_Set(false));
	buttonY_3->WhenPressed(new cam(true));
	buttonA_3->WhenPressed(new cam(false));


	button7_2->WhenPressed(new SystemsCheck(true));
	button7->WhenPressed(new SystemsCheck(false));

}
//these methods all basically do what they say they do in their name so yeah
float OI::GetJoystickY() {
	return 1 * controller->GetRawAxis(1);
}

/*float OI::GetRightJoystick() {
	return -1 * controller->GetRawAxis(5);
}
*/
double OI::GetJoystick_2Y(){
	return -1 * controller_2->GetRawAxis(1);
}

/*
double OI::GetRightJoystick_2(){
	return -1 * controller_2->GetRawAxis(5);
}
*/

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

float OI::GetLeftBumper() {
	return controller->GetRawButton(5);
}

float OI::GetRightBumper() {
	return controller->GetRawButton(6);
}
float OI::GetSelect() {

	return controller->GetRawButton(7);
}

/* float OI::GetX() {

	return controller->GetRawButton(3);
}
float OI::GetB() {

	return controller->GetRawButton(2);
}
*/

