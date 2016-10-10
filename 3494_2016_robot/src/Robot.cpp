#include "WPILib.h"
#include "AHRS.h"
#include "Commands/Command.h"
#include "Commands/Autonomous/Autonomous_Sequences.h"
#include "Commands/Autonomous/Auto_Score.h"
#include "CommandBase.h"
#include "OI.h"
#include "Subsystems/DriveTrain.h"


class Robot: public IterativeRobot {
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;
	Command * autonomousSequences;
	DriveTrain* drivetrain;

	AHRS *ahrs; /* Alternatives:  SPI::kMXP, I2C::kMXP or SerialPort::kUSB */
	bool bDrivetrain;
	void RobotInit() {
		SmartDashboard::init();
		CommandBase::init();
		// creat the auto sequence chooser
		chooser = new SendableChooser();
		// Auto 1 is the default
		chooser->AddDefault("Auto 1", new Autonomous_Sequences(1));
		chooser->AddObject("Auto 2", new Autonomous_Sequences(2));
		chooser->AddObject("Auto 3", new Autonomous_Sequences(3));
		chooser->AddObject("Auto 4", new Autonomous_Sequences(4));
		chooser->AddObject("Auto 5", new Autonomous_Sequences(5));
		//add the auto selector to the dashboard
		SmartDashboard::PutData("AutoMode", chooser);

		//chooser->AddObject("My Auto", new MyAutoCommand());
		//SmartDashboard::PutData("Auto Modes", chooser);
		//obstacle->AddObject("My Auto", new MyAutoCommand());
		//SmartDashboard::PutData("Auto Modes", obstacle);
		//SmartDashboard::PutData("Position", position);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit() {
	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() {
		autonomousSequences = (Command*)chooser->GetSelected();
		if (autonomousSequences != NULL){
			autonomousSequences->Start();
		}
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousSequences != NULL)
			autonomousSequences->Cancel();
	}

	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() {
		//LiveWindow::GetInstance()->Run();
		//bDrivetrain = drivetrain->TestDriveTrain(2.0f);
		//SmartDashboard::PutBoolean("DriveTrain_GO",bDrivetrain);
	}
};

START_ROBOT_CLASS(Robot)
