#ifndef Kompressor_2_H
#define Kompressor_2_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Kompressor_2: public Subsystem
{
private:
	Compressor* kompressor;
public:
	Kompressor_2();
	void InitDefaultCommand();
};

#endif
