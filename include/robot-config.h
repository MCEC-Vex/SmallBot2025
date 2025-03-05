using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor RightBackUp;
extern motor LeftBackDown;
extern motor LeftFrontUp;
extern motor LeftFrontDown;
extern motor LeftBackUp;
extern motor RightBackDown;
extern motor RightFrontDown;
extern motor RightFrontUp;
extern motor Intake;
extern motor BeltIntake;
extern digital_out Piston;
extern motor BeltIntake2;
extern optical OpticalSensor;
extern inertial Inertial10;
extern motor Goalrush;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );