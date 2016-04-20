#ifndef Auto_Move_Tim_H
#define Auto_Move_Tim_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Auto_Move_Tim: public CommandBase
{
private:
	//float speed;
	float right;
	float left;
	float time;
public:
	Auto_Move_Tim(float Left_speed_,float Right_speed_, float time_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
