#include "Kompressor_2.h"
#include "../RobotMap.h"

Kompressor_2::Kompressor_2() :
		Subsystem("Kompressor")
{
	// if there happens to be a compressor in the robot it will be ready
	kompressor = new Compressor(COMPRESSOR);
	//starts off false because it will be switched to true the first time called
	//On  = false;
	// if there happens to be a compressor in the robot then uncomment the code.
	kompressor->SetClosedLoopControl(true);

}

void Kompressor_2::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
