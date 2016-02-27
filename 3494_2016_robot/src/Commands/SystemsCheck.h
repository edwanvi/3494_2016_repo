#ifndef SystemsCheck_H
#define SystemsCheck_H

#include "../CommandBase.h"
#include "WPILib.h"

class SystemsCheck: public CommandBase
{
private:
	bool right;
	double leftCurrent;
	double rightCurrent;
public:
	SystemsCheck(bool _right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
