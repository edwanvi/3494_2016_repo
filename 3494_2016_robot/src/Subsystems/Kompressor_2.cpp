#include "Kompressor_2.h"
#include "../RobotMap.h"

Kompressor_2::Kompressor_2() :
		Subsystem("Kompressor")
{
	// TODO: Make this something we can toggle at will
	// if there happens to be a compressor in the robot it will be ready
	if (DO_WE_HAVE_A_COMPRESSOR) {
		kompressor = new Compressor(COMPRESSOR);
		//starts off false because it will be switched to true the first time called
		//On  = false;
		kompressor->SetClosedLoopControl(true);
	}
}

void Kompressor_2::InitDefaultCommand() {
	// compressor does not have any commands
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
