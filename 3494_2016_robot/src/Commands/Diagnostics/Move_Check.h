#ifndef Move_Check_H
#define Move_Check_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Move_Check: public CommandBase
{
private:
	float letime;
	bool direction;
	std::clock_t start;
	float duration;
	bool time_loop;
	double leftCurrent;
	double rightCurrent;

public:
	Move_Check(float _time, bool _direction);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
