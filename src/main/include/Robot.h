// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <ctre/phoenix.h>
#include <frc/XboxController.h>
#include <frc/PowerDistribution.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/DoubleSolenoid.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

  //speed variables for the arm
  double intakeSpeed = 0.2;
  double ampSpeed = 0.3;
  double shootSpeed = 1;

  //sets the robots max drive speed for the Xbox controller with dual stick
  double DriveSpeed = 0.6;

  //variables that tell the robot which controller your using
  bool Joystick = false;
  bool X45 = true;

  //the maximum amperadge the motors can draw before shutting off
  int currentLimit = 8;
  
  

  void JoystickDirection();
  void XboxDirection();

  void XboxArm();

void drive(double left, double right);

void JoystickArm();


  private:
  //drive motors
  TalonFX m_driveMotorRFront{2};
  TalonFX m_driveMotorRBack{3};
  TalonFX m_driveMotorLFront{4};
  TalonFX m_driveMotorLBack{5};
  //mech motors
  TalonFX m_intakeL{16};
  TalonFX m_intakeR{15};
  //controllers
  frc::Joystick m_joystick{0};
  frc::XboxController m_armControll{1};
  //pdh
  frc::PowerDistribution m_pdp{1, frc::PowerDistribution::ModuleType::kCTRE};
  //pneumatics
  frc::DoubleSolenoid m_doubleSolenoid{frc::PneumaticsModuleType::CTREPCM, 0, 1};
};
