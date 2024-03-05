basic test robot for the 2024 FRC game. drive motors must be can ID 2&3 for the right side as the robot would be driving away, and 4&5 for the left side. the mech motors are ID 16&15.
this is written to be used for cim motors in a West Coast configuration. using phenix V5 because our firmware won't update properly. 

If you use the Saitek X45 joysticks. the main stick is for single stick tank drive and the throttle controls speed. the buttons for the index finger are for the mech. Up to shoot and left for intake, right shoots at a lower speed for the amp. These speeds can be ajusted using the upper knob on the throttle.

there is also code for an Xbox controller that uses a dual-stick tank drive from the two sticks of the controller. the mech is run by the A, X, and Y buttons.
The A button controls the intake, X shoots for the amp at a lower speed, and Y shoots higher. The right bumper button on the controller changes the drive speed to about 1/4 of the normal drive speed.

We also have support for two pistons using double solanoids. support is only for the Xbox controller. press the B button to raise the pistons and release to lower them.

**Latest Updates**

Added joystick support for the pistons and made it possible to turn off the different mech functions

**To Do**

I am working on adding support for the Logitech X3D joystick, but that code currently doesn't work.

There is no auto.


**Can conventions**

below is a chart of the standard can numbering conventions that we have been using. It is a good idea to ty and follow this, as it means that one coadbase can work for many robots
| ID |    Swerve ( 1977 )    |    Swerve ( 1822 )   |       Westcoast      |
|:--:|:---------------------:|:--------------------:|:--------------------:|
|  0 | Roborio               | Roborio              | Roborio / CTRE PDP   |
|  1 | REV PDH               | REV PDH              | **---- Reserved ----**  |
|  2 | Front Right Drive     | Front Right Drive    | Right Front Drive    |
|  3 | Front Right Angle     | Front Right Angle    | Right Rear Drive     |
|  4 | Front Right Sensor    | Front Right Sensor   | Left Front Drive     |
|  5 | Rear Right Drive      | Rear Right Drive     | Left Rear Drive      |
|  6 | Rear Right Angle      | Rear Right Angle     | **---- Unassigned ----** |
|  7 | Rear Right Sensor     | Rear Right Sensor    | **---- Unassigned ----** |
|  8 | Rear Left Drive       | Rear Left Drive      | **---- Unassigned ----** |
|  9 | Rear Left Angle       | Rear Left Angle      | **---- Unassigned ----** |
| 10 | Rear Left Sensor      | Rear Left Sensor     | **---- Unassigned ----** |
| 11 | Front Left Drive      | Front Left Drive     | **---- Unassigned ----** |
| 12 | Front Left Angle      | Front Left Angle     | **---- Unassigned ----** |
| 13 | Front Left Sensor     | Front Left Sensor    | **---- Unassigned ----** |
| 14 | Intake                | Intake               | Intake               |
| 15 | Shooter Top           | Shooter Top          | Shooter Top          |
| 16 | Shooter Bottom        | Shooter Bottom       | Shooter Bottom       |
| 17 | Shooter Angle         | Shooter Angle        | Shooter Angle        |
| 18 | Climber               | Climber              | Climber              |
| 19 | Shooter Angle Encoder | **---- Unassigned ----** | **---- Unassigned ----** |
| 20 | **---- Unassigned ----** | **---- Unassigned ----** | **---- Unassigned ----** |
