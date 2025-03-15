// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightBackUp          motor         15              
// LeftBackDown         motor         14              
// LeftFrontUp          motor         11              
// LeftFrontDown        motor         12              
// LeftBackUp           motor         13              
// RightBackDown        motor         16              
// RightFrontDown       motor         17              
// RightFrontUp         motor         18              
// Intake               motor         9               
// BeltIntake           motor         5               
// Piston               digital_out   C               
// BeltIntake2          motor         21              
// OpticalSensor        optical       7               
// Inertial10           inertial      10              
// Goalrush             motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightBackUp          motor         15              
// LeftBackDown         motor         14              
// LeftFrontUp          motor         11              
// LeftFrontDown        motor         12              
// LeftBackUp           motor         13              
// RightBackDown        motor         16              
// RightFrontDown       motor         17              
// RightFrontUp         motor         18              
// Intake               motor         9               
// BeltIntake           motor         5               
// Piston               digital_out   C               
// BeltIntake2          motor         21              
// OpticalSensor        optical       7               
// Inertial10           inertial      10              
// Goalrush             motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightBackUp          motor         15              
// LeftBackDown         motor         14              
// LeftFrontUp          motor         11              
// LeftFrontDown        motor         12              
// LeftBackUp           motor         13              
// RightBackDown        motor         16              
// RightFrontDown       motor         17              
// RightFrontUp         motor         18              
// Intake               motor         9               
// BeltIntake           motor         5               
// Piston               digital_out   C               
// BeltIntake2          motor         21              
// OpticalSensor        optical       7               
// Inertial10           inertial      10              
// Goalrush             motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightBackUp          motor         15              
// LeftBackDown         motor         14              
// LeftFrontUp          motor         11              
// LeftFrontDown        motor         12              
// LeftBackUp           motor         13              
// RightBackDown        motor         16              
// RightFrontDown       motor         17              
// RightFrontUp         motor         18              
// Intake               motor         19              
// BeltIntake           motor         8               
// Piston               digital_out   C               
// BeltIntake2          motor         21              
// OpticalSensor        optical       20              
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
// ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(
  LeftFrontUp,
  LeftFrontDown,
  LeftBackUp,
  LeftBackDown
),

//Right Motors:
motor_group(
  RightFrontUp,
  RightFrontDown,
  RightBackUp,
  RightBackDown
),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT10,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
4.125,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
1.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Auton 1");
        break;
      case 1:
        Brain.Screen.printAt(5, 140, "Auton 2");
        break;
      case 2:
        Brain.Screen.printAt(5, 140, "Auton 3");
        break;
      case 3:
        Brain.Screen.printAt(5, 140, "Auton 4");
        break;
      case 4:
        Brain.Screen.printAt(5, 140, "Auton 5");
        break;
      case 5:
        Brain.Screen.printAt(5, 140, "Auton 6");
        break;
      case 6:
        Brain.Screen.printAt(5, 140, "Auton 7");
        break;
      case 7:
        Brain.Screen.printAt(5, 140, "Auton 8");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  default_constants();
    chassis.set_coordinates(0, 0, 0);
  // Piston.set(true);
  // BeltIntake.spin(fwd, 50, percent);
  // BeltIntake2.spin(fwd, 50, percent);
  // wait(1000,  msec);
  // chassis.turn_to_angle(0);
  // chassis.drive_distance(-30, 0, 20, 0);
  // wait(1000,  msec);
  // chassis.turn_to_angle(180);
  // chassis.drive_distance(-60, 0, 20, 0);
  // wait(1000,  msec);
  // chassis.drive_distance(-20, 0, 10, 0);

    
    // Using the ODOM!
    // chassis.turn_kp = 0.4;
    // chassis.turn_to_angle(90);

  switch(current_auton_selection){ 
    case 0:
       skills_auto();
       break;
    case 1:         
      match_auto();
       break;
    case 2:
      skills_auto();
      break;
//     case 3:
//       swing_test();
//       break;
//     case 4:
//       full_test();
//       break;
//     case 5:
//       odom_test();
//       break;
//     case 6:
//       tank_odom_test();
//       break;
//     case 7:
//       holonomic_odom_test();
//       break;
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {

  Goalrush.spinToPosition(-1000, degrees, false);
  // Calibrate the sensor
  OpticalSensor.setLightPower(50, percent);
  bool PistonOpen = false;
  Piston.set(false);
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
            if(Brain.Timer >= 29500 && Brain.Timer <= 30000){
      Controller1.rumble("....");
    }
        if(Brain.Timer >= 44500 && Brain.Timer <= 45000){
      Controller1.rumble("...");
    }
        if(Brain.Timer >= 49500 && Brain.Timer <= 50000){
      Controller1.rumble("...");
    }
    if(Controller1.ButtonA.pressing()) {
      PistonOpen = !PistonOpen;
      Piston.set(PistonOpen);
      wait(300, msec);
    }



    if(Controller1.ButtonR2.pressing()){
        Intake.spin(reverse, 100, percent);
    } else if(Controller1.ButtonR1.pressing()){
        Intake.spin(fwd, 100, percent);
    } else {
        Intake.spin(fwd, 0, percent);
    }
    
    if(Controller1.ButtonR2.pressing()){
        BeltIntake2.spin(reverse, 100, percent);
        BeltIntake.spin(reverse, 100, percent);
      // Test.spin(fwd, 0, percent);
    } else if(Controller1.ButtonR1.pressing()){
      BeltIntake.spin(fwd, 50, percent);
      BeltIntake2.spin(fwd, 50, percent);
    } else {
      BeltIntake.spin(fwd, 0, percent);
      BeltIntake2.spin(reverse, 0, percent);
    }

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_arcade();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
