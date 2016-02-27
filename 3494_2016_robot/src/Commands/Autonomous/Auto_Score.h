#ifndef Auto_Score_H
#define Auto_Score_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Auto_Score: public CommandBase
{
public:

	void middle();
	void left();
	void right();
	Auto_Score(int position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
