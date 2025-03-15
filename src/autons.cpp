#include "vex.h"
#include "cmath"
#include <stdio.h>

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * the autonomous to be run during skills
 */


int colorSortingTask() {
  bool blueRingSpotted = false;
  OpticalSensor.setLightPower(50);
  while(true) {
              if(OpticalSensor.isNearObject() && !blueRingSpotted){
        if(OpticalSensor.hue() <= 230 && OpticalSensor.hue() >= 100) {
        Controller1.rumble(".");
        wait(50, msec);
        Intake.spin(reverse, 0, percent);
        BeltIntake2.spin(reverse, 0, percent);
        BeltIntake.spin(reverse, 0, percent);
        wait(100, msec);

        Intake.spin(fwd, 100, percent);
        BeltIntake2.spin(fwd, 100, percent);
        BeltIntake.spin(fwd, 100, percent);
        blueRingSpotted = true;
        wait(200, msec);
        blueRingSpotted = false;
        }
              }
    wait(20, msec); // Small delay to prevent hogging CPU
  }
  return 0;
}


bool toSpin = false;
float speed = 100;
int ConveyorSpin() {
  while(1){
    
    if(toSpin){
      BeltIntake2.spin(fwd, speed, percent);
      BeltIntake.spin(fwd, speed, percent);

      //Controller1.Screen.setCursor(1, 1);
      //Controller1.Screen.print(std::abs(BeltIntake.velocity(percent)));
      wait(200, msec);
      printf("%f\n", BeltIntake.velocity(percent));
      if(std::abs(BeltIntake.velocity(percent)) == 0){
        printf("bruh");
        BeltIntake.spinFor(reverse, 80, degrees);
        BeltIntake2.spinFor(reverse, 80, degrees);
      }

    }else{
      printf("mini Exit");
      BeltIntake.stop();
      BeltIntake2.stop();
      wait(200, msec);
    }
  }
  printf("Exit");
  return 0;
}


/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * 
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declablue in autons.h.
 */
   

void skills_auto() {
 default_constants();
 vex::task sortTask(colorSortingTask);
 vex::task spinTask(ConveyorSpin);

 //toSpin = true;

 //get first ring
 Intake.spin(fwd, 100, percent);
 BeltIntake.stop();
 BeltIntake2.stop();
 chassis.drive_distance(-48, 0);

//get mogo
 chassis.turn_to_angle(90);
 chassis.drive_distance(30, 90, 6, 24);
  Piston.set(true);
 wait(350, msec);
 chassis.drive_distance(-8, 90);

  toSpin = true;
 wait(700, msec);
 chassis.turn_to_angle(180);
 chassis.drive_distance(-35, 180);

 chassis.turn_to_angle(-135);
 chassis.drive_distance(-16, -135);
 chassis.drive_distance(19, -135);
 chassis.turn_to_angle(45);

 //drive to middle
chassis.drive_distance(-50, 45);
chassis.drive_distance(-38, 45, 6, 6);
chassis.turn_to_angle(-20);
chassis.drive_distance(-8, -20, 6, 24);

//drop mogo in corner
chassis.drive_distance(6, -20, 6, 24);
chassis.turn_to_angle(45);
chassis.drive_distance(101, 45);
Piston.set(false);

}

/**
 * The autonomous to be ran in a match
 */

void match_auto(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * The default autonomous
 */

void default_auto(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}