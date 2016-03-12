#ifndef Climber_H
#define Climber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Climber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* WenchTalon_1; // She's got scuuuurvy!
	Talon* WenchTalon_2;
	PowerDistributionPanel* pdp;
	DoubleSolenoid* solenoid_climber_arm;
	DoubleSolenoid* shifter;
	DoubleSolenoid* camera;

//	bool currentGear;
public:
	Climber();
	void InitDefaultCommand();
	void Winch(bool _clockwise);
	void StopWinch();
	void Setter(bool forward);
	void ChangeGear(bool _gear);
	void Camera(bool up);
};

#endif
