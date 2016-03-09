#ifndef Move_Check_H
#define Move_Check_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Move_Check: public CommandBase
{
private:
float test_time;
public:
	Move_Check(float _time);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
