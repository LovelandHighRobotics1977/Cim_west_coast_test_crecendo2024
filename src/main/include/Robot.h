// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <ctre/phoenix.h>
#include <frc/XboxController.h>

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

  double intakeSpeed = 1;
void direction();

void drive(double left, double right);

void arm();


  private:
  TalonFX m_driveMotorRFront{2};
  TalonFX m_driveMotorRBack{3};
  TalonFX m_driveMotorLFront{4};
  TalonFX m_driveMotorLBack{5};
  TalonFX m_intakeL{16};
  TalonFX m_intakeR{15};
  frc::Joystick m_joystick{0};
  //frc::XboxController m_armControll{1};
};
