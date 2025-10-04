#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LF = motor(PORT12, ratio6_1, true);
motor LM = motor(PORT7, ratio6_1, true);
motor RF = motor(PORT8, ratio6_1, false);
motor RM = motor(PORT5, ratio6_1, false);
motor LB = motor(PORT3, ratio6_1, true);
motor RB = motor(PORT10, ratio6_1, false);
//motor Intake = motor(PORT9, ratio6_1, false);
motor SecondStage = motor(PORT6, ratio6_1, false);
motor BottomStage = motor(PORT4, ratio6_1, false);
digital_out Wings = digital_out(Brain.ThreeWirePort.D);
digital_out Scrapper = digital_out(Brain.ThreeWirePort.C);
digital_out Lift = digital_out(Brain.ThreeWirePort.B);
inertial Gyro = inertial(PORT1);
//Naming convention: 
// Important variables
const double wheelDiam = 2.75;
const double wheelToMotorRatio = 48.0/36;

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