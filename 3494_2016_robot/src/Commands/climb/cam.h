#ifndef cam_H
#define cam_H

#include "../../CommandBase.h"
#include "../../Subsystems/Climber.h"
#include "WPILib.h"

class cam: public CommandBase
{
private:
	bool mode;
public:
	cam(bool _mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
