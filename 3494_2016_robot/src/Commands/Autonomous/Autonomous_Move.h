#ifndef Autonomous_Move_H
#define Autonomous_Move_H

#include "../../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/DriveTrain.h"

class Autonomous_Move: public CommandBase
{
public:
	Autonomous_Move(float _distance, float _speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float distance;
	float speed;
	float target;
	bool back;
};

#endif
