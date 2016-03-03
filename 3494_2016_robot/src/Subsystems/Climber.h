#ifndef Climber_H
#define Climber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Climber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* WinchTalon_1;
	CANTalon* WinchTalon_2;
public:
	Climber();
	void InitDefaultCommand();
	void Winch(bool _clockwise);
};

#endif
