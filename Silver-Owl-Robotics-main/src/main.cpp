/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

//#include "STDLib.cpp"
#include "vex.h"

#include "screen_gui.hpp"
#include "movement.hpp"
#include "routes/routes.hpp"


using namespace vex;

// A global instance of competition
competition Competition;


// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

bool SP;
bool EXIT;
void pre_auton(void) {
   EXIT=false;
  Scrapper.set(false);
  //Lift.set(false);
  PX=0;
  JX=0;
  AutoSelectorVal=0;
  SP=false;
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
Gyro.calibrate();

//Ensure Robot Launch Position is set before auto proceeds, once plugged into field control,
//start program and do not temper bot under all circumstances

//1. IF ANY ADJUSTMENT IS NEEDED, QUIT PROGRAM, THEN ADJUST, RESTART PROGRAM AFTER ADJUSTMENTS COMPLETED
//2. DO NOT START PROGRAM BEFORE PLUGGING IN FIELD CONTROL, THIS MAY DISABLE AUTO
//3. ONLY SIGNAL JUDGES TO BEGIN MATCH AFTER THE ZEROING PROMPT ON SCREEN HAS CLEARED

//Print precautionary message
Brain.Screen.drawRectangle(0,0,500,500);

Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(2,10);
Brain.Screen.print("FLIR TIMEOUT");


waitUntil(!Gyro.isCalibrating());


Zeroing(true,true);
DisplayAutoSelector();
DisplayWords();

//task AutoSelTask=task(ScreenSelMain);
  while(!EXIT)
{
if(Brain.Screen.xPosition()<100)
{
if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=1;
else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=3;
else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=5;
}
else if(Brain.Screen.xPosition()>375)
{
if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=2;
else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=4;
else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=6;
}

if(Brain.Screen.xPosition()>187&&Brain.Screen.xPosition()<287)
{
if(Brain.Screen.yPosition()<55&&Brain.Screen.yPosition()>5) EXIT=true;
else if(Brain.Screen.yPosition()>125&&Brain.Screen.yPosition()<225)AutoSelectorVal=7;
}

if(Brain.Screen.pressing()&&!SP) UpdateDynamic();

SP=Brain.Screen.pressing();

}

Brain.Screen.clearScreen();
if(AutoSelectorVal==1){
  Lift.set(true);
  Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("9Left");
Brain.Screen.setCursor(4,10);

Brain.Screen.setFont(monoM);
  Brain.Screen.setFillColor("#39FF14");

}

if(AutoSelectorVal==2){
Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("idk");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("6+3MAYNOTWORK");
Brain.Screen.setFont(monoM);
  Brain.Screen.setFillColor("#39FF14");
}

if(AutoSelectorVal==3){

Brain.Screen.setFillColor(black);

    Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("GOAL SIDE");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("7RIGHT");
Brain.Screen.setFont(monoM);  
  Brain.Screen.setFillColor("#39FF14");
}

if(AutoSelectorVal==4){

Brain.Screen.setFillColor(black);

  Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("9Ball");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("Right");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#39FF14");

}

if(AutoSelectorVal==5){

Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("GOAL SIDE");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("GS-AWP");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#39FF14");

}

if(AutoSelectorVal==6){
  
  Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("AWP");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("AWP");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#39FF14");

  }

if(AutoSelectorVal==7){

Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("SKILLS");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("SKILLS");
Brain.Screen.setFont(monoM); 
Brain.Screen.setFillColor("#39FF14");

}

Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#39FF14");
Brain.Screen.setCursor(5,10);
Brain.Screen.print("AUTO CONFIRMED");



  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  Zeroing(true,true);
  PIDDataSet TestPara={4,0.1,0.2};

  
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

//Do not change the below



    
//can start editing if nessary
//Put Auto route function into if statements to use autoselector
if(AutoSelectorVal==1)//9ball LEFT
{
  Lift.set(false);
  Lift.set(false);
  nineleft(); 
}

if(AutoSelectorVal==2) // If Time 6+3
{
  
}

if(AutoSelectorVal==3)//Unimportant
{
  
} 

if(AutoSelectorVal==4)//9ball RIGHT
{
  
  nineright();
  
}

if(AutoSelectorVal==5)//7Left
{
  //Lift.set(true);
  test5();

}


if(AutoSelectorVal==6)//AWP only
{
  AWP();
}


if(AutoSelectorVal==7)//Skills
{ 
Scrapper.set(false);
 testskills();

}
//MoveTimePID(TestPara, -100, 0.5,0.1,-40,true);//score 2nd triball
//(PID Parameters, motor speed -100 - 100, time for travel 0 - inf, time to accelerate to full speed, Absolute Heading, Braking?)

    // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
CStop();
}
int RV;
int LV;
int DriveTask(void){
  LF.setStopping(hold);
      LM.setStopping(hold);
      LB.setStopping(hold);
      RF.setStopping(hold);
      RM.setStopping(hold);
      RB.setStopping(hold);
  while(true)
  {
  
    EXIT=true;
    RV=Controller1.Axis3.position(percent)-Controller1.Axis1.position(percent);
    LV=Controller1.Axis3.position(percent)+Controller1.Axis1.position(percent);
    Move(LV,RV);
  }

return 0;
}
int V;
int ButtonPressingR,RTaskActiv;
int ButtonPressingR2,R2TaskActiv;
int ATask(void)
{
  double pow;
  
  //EditcodeLater
    while(true)
  {
    //pow=((Controller1.ButtonR2.pressing()-Controller1.ButtonR1.pressing())*100);//Calculate intake power, if button pressed, button.pressing returns 1
    if (Controller1.ButtonR1.pressing()==1)
    {
      IntakeBoth(100);
      
    
    }
    
    else if (Controller1.ButtonL1.pressing()==1)
    {
      IntakeBoth(-100);
    }
    else if (Controller1.ButtonR2.pressing()==1)
    {
      RunBottom(100);

    }
    else
    {
      IntakeBoth(0);

    }

    
  
  //RunPuncher((Controller1.ButtonB.pressing())*100);
  }
  
  return 0;
}

int ButtonPressingX,XTaskActiv;
int ButtonPressingY,YTaskActiv;
int ButtonPressingRight,RightTaskActiv;

int PTask(void)
{
    while(true)
    {
      //Toggles Tilt
    if(XTaskActiv==0&&Controller1.ButtonDown.pressing()&&ButtonPressingX==0)
    {
      ButtonPressingX=1;
      XTaskActiv=1;
      Scrapper.set(true);
    }

    else if(!Controller1.ButtonDown.pressing())ButtonPressingX=0;

    else if(XTaskActiv==1&&Controller1.ButtonDown.pressing()&&ButtonPressingX==0)
    {
      ButtonPressingX=1;
      XTaskActiv=0;
      Scrapper.set(false);
    }
    //----------------------
      //Toggles Clamp
    if(YTaskActiv==0&&Controller1.ButtonUp.pressing()&&ButtonPressingY==0)
    {
      ButtonPressingY=1;
      YTaskActiv=1;
      Lift.set(true);
    }

    else if(!Controller1.ButtonUp.pressing())ButtonPressingY=0;

    else if(YTaskActiv==1&&Controller1.ButtonUp.pressing()&&ButtonPressingY==0)
    {
      ButtonPressingY=1;
      YTaskActiv=0;
      Lift.set(false);
    }
    
      //Toggles Pusher
    if(RightTaskActiv==0&&Controller1.ButtonA.pressing()&&ButtonPressingRight==0)
    {
      ButtonPressingRight=1;
      RightTaskActiv=1;
      Wings.set(true);
    }

    else if(!Controller1.ButtonA.pressing())ButtonPressingRight=0;

    else if(RightTaskActiv==1&&Controller1.ButtonA.pressing()&&ButtonPressingRight==0)
    {
      ButtonPressingRight=1;
      RightTaskActiv=0;
      Wings.set(false);
    }
    //TOGGLES BOTH ENCASE NEEDED
    //if (R2TaskActiv==1&&RTaskActiv==1)
    //{
      //RTaskActiv=0;
    //}
    //if(RTaskActiv==0&&Controller1.ButtonR1.pressing()&&ButtonPressingR==0)
    //{
      //ButtonPressingR=1;
      //RTaskActiv=1;
      
    //}

    //else if(!Controller1.ButtonR1.pressing())
      //{ButtonPressingR=0;}
    //else if(!Controller1.ButtonR1.pressing()&&RTaskActiv==1)
    //{
      //IntakeBoth(100);
    //}
    //else if(RTaskActiv==1&&Controller1.ButtonR1.pressing()&&ButtonPressingR==0)
    //{
      //ButtonPressingR=1;
      //RTaskActiv=0;
      //IntakeBoth(0);
    //}
    //if(R2TaskActiv==0&&Controller1.ButtonR2.pressing()&&ButtonPressingR2==0)
    //{
      //ButtonPressingR2=1;
      //R2TaskActiv=1;
      
    //}

    //else if(!Controller1.ButtonR2.pressing())
    //{ButtonPressingR2=0;}
    //else if(!Controller1.ButtonR2.pressing()&&R2TaskActiv==1)
    //{
      //IntakeBoth(-100);
    //}

    //else if(R2TaskActiv==1&&Controller1.ButtonR2.pressing()&&ButtonPressingR2==0)
    //{
      //ButtonPressingR2=1;
      //R2TaskActiv=0;
      //IntakeBoth(0);
    //}
    
    
    



  }
  return 0;
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
  EXIT=true;//Force Exit Autosel once drivercontrol began.
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    
     
    
    task Dtask=task(DriveTask);
    task Atask=task(ATask);
    task Ptask=task(PTask);
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

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
    ShowDis();
  }
}
  