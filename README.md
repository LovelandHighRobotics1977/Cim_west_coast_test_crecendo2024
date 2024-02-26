basic test robot for the 2024 FRC game. drive motors must be can ID 2&3 for the right side as the robot would be driving away, and 4&5 for the left side. the mech motors are ID 16&15.
this is written to be used for cim motors in a West Coast configuration. using phenix V5 because our firmware won't update properly. 

If you use the Saitek X45 joysticks. the main stick is for single stick tank drive and the throttle controls speed. the buttons for the index finger are for the mech. Up to shoot and left for intake, right shoots at a lower speed for the amp. These speeds can be ajusted using the upper knob on the throttle.

there is also code for an Xbox controller that uses a dual-stick tank drive from the two sticks of the controller. the mech is run by the A, X, and Y buttons.
The A button controls the intake, X shoots for the amp at a lower speed, and Y shoots higher. The right bumper button on the controller changes the drive speed to about 1/4 of the normal drive speed.

*Latest Updates*

I added support for a pnumatics system with one double solanoid and a single piston. this is currently made to work with the CTRE PCM, but can be easily changed to work with the REV PH. The pneumatics currently only have support with the Xbox controller, wich also has to be driving.

you can now use one controller for drive and another for mech. you can also still use one controller for both. see the comments in the header file for more info.

*To Do*

I am working on adding support for the Logitech X3D joystick, but that code currently doesn't work.
There is no auto.

