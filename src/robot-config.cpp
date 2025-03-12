#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor RightBackUp = motor(PORT15, ratio18_1, true);
motor LeftBackDown = motor(PORT14, ratio18_1, true);
motor LeftFrontUp = motor(PORT11, ratio18_1, false);
motor LeftFrontDown = motor(PORT12, ratio18_1, true);
motor LeftBackUp = motor(PORT13, ratio18_1, false);
motor RightBackDown = motor(PORT16, ratio18_1, false);
motor RightFrontDown = motor(PORT17, ratio18_1, false);
motor RightFrontUp = motor(PORT18, ratio18_1, true);
motor Intake = motor(PORT9, ratio18_1, false);
motor BeltIntake = motor(PORT5, ratio6_1, false);
digital_out Piston = digital_out(Brain.ThreeWirePort.C);
motor BeltIntake2 = motor(PORT21, ratio6_1, false);
optical OpticalSensor = optical(PORT7);
inertial Inertial10 = inertial(PORT10);
motor Goalrush = motor(PORT20, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}