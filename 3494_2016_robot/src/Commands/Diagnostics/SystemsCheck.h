#ifndef SystemsCheck_H
#define SystemsCheck_H

#include "../../CommandBase.h"
#include "WPILib.h"
#include "CommandBase.h"

class SystemsCheck: public CommandBase
{
private:
	bool right;
	double leftCurrent;
	double rightCurrent;
	DriveTrain* drivetrain;
	Rollers* rollers;
	bool bRollers;
	bool bDriveTrain;
public:
	SystemsCheck(bool _right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
