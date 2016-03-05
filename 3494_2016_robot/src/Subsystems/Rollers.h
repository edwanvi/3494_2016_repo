#ifndef Rollers_H
#define Rollers_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
#include <ctime>

class Rollers: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* talon_rollers;
	CANTalon* talon_rollers_2;
	double duration;

	std::clock_t start;
	double timeElapsed = 0.0;
	double speed = 0.0;
	PowerDistributionPanel* pdp;

	//No idea which is which please change
	double leftCurrent;
	double rightCurrent;

	bool bCheck;
public:
	Rollers();
	void InitDefaultCommand();
	void Roll(bool forward, double _speed);
	bool CheckRoll(double _duration);



};

#endif
