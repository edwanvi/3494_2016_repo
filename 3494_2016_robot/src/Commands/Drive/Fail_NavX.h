#ifndef Fail_NavX_H
#define Fail_NavX_H

#include "../CommandBase.h"
#include "WPILib.h"

class Fail_NavX: public CommandBase
{
private:
	bool fail;
public:
	Fail_NavX(bool fail_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
