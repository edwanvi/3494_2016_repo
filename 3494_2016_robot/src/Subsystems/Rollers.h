#ifndef Rollers_H
#define Rollers_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class Rollers: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* talon_rollers;
	CANTalon* talon_rollers_2;
public:
	Rollers();
	void InitDefaultCommand();
	void Roll(bool forward);
};

#endif
