#ifndef Climber_H
#define Climber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Climber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* WinchTalon_1;
	Talon* WinchTalon_2;
	PowerDistributionPanel* pdp;
public:
	Climber();
	void InitDefaultCommand();
	void Winch(bool _clockwise);
	void StopWinch();
};

#endif
