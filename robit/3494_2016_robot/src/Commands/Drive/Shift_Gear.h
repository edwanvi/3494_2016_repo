#ifndef Shift_Gear_H
#define Shift_Gear_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Shift_Gear: public CommandBase
{
private:
	bool mode;
public:
	Shift_Gear(bool _mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
