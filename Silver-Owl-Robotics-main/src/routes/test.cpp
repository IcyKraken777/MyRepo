#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
// NOTICE, REORGANIZE THE CODE!!!


// Note for Coders: All intakes, positive is INTAKE/SCORE, Negative is OUTAKE
// Pnuematics are their given names... Eg. Wings are Wings 
void nineleft() {
    // declare initial conditions
    //9ball assumption LEFT
PIDDataSet TestPara={1.1,0.03,0.31};
PIDDataSet AngPara={1.5,0.1,0.13};
RunSecondStage(20);
RunBottom(100);
MoveEncoderPID(TestPara, 80,2.5, 0.4,0,false);
wait(200,msec);
MoveEncoderPID(TestPara, 100,67.5, 0.1,72,true);
wait(700,msec);
//Addcodehere

wait(200,msec);
MoveEncoderPID(TestPara, -100,1.5, 0.1,45,false);
Scrapper.set(false);
MoveEncoderPID(TestPara, -100,7.5, 0.1,0,false);
MoveEncoderPID(TestPara, -100,47, 0.1,-80,false);
TurnMaxTimePID(AngPara, 0,0.5, true);
Lift.set(true);
wait(400,msec);
MoveEncoderPID(TestPara, 100,14, 0.1,0,true);
RunSecondStage(100);

wait(1000,msec);
RunSecondStage(17);
RunBottom(100);
MoveEncoderPID(TestPara, -100,11, 0.1,0,true);

Scrapper.set(true);
TurnMaxTimePID(AngPara, -175,0.5, true);
MoveEncoderPID(TestPara, 70,18, 0.1,180,true);
wait(670,msec);
MoveEncoderPID(TestPara, -70,19, 0.1,180,true);
Scrapper.set(false);
TurnMaxTimePID(AngPara, 0,0.5, true);
MoveEncoderPID(TestPara, 70,9, 0.1,0,true);
wait(100,msec);
RunSecondStage(100);

}
void nineright(){
    //9 Ball Right (Get the OG to work first)
    PIDDataSet TestPara={1.1,0.03,0.31};
PIDDataSet AngPara={1.5,0.1,0.13};
RunSecondStage(20);
RunBottom(100);
MoveEncoderPID(TestPara, 80,4.5, 0.4,0,false);
wait(200,msec);
MoveEncoderPID(TestPara, 70,10, 0.1,70,true);
TurnMaxTimePID(AngPara, 30,0.5, true);

MoveEncoderPID(TestPara, 50,39, 0.1,30,true);

wait(900,msec);
//Addcodehere

wait(200,msec);
MoveEncoderPID(TestPara, -100,1.5, 0.1,45,false);
Scrapper.set(false);
MoveEncoderPID(TestPara, -100,7.5, 0.1,0,false);
MoveEncoderPID(TestPara, -100,35.5, 0.1,-80,false);
TurnMaxTimePID(AngPara, 0,0.5, true);
Lift.set(true);
wait(400,msec);
MoveEncoderPID(TestPara, 100,14.5, 0.1,0,true);
RunSecondStage(100);

wait(300,msec);
RunSecondStage(17);
RunBottom(100);
MoveEncoderPID(TestPara, -100,11, 0.1,0,true);

Scrapper.set(true);
TurnMaxTimePID(AngPara, -160,0.5, true);
MoveEncoderPID(TestPara, 60,20, 0.1,180,true);
wait(660,msec);
MoveEncoderPID(TestPara, -70,19, 0.1,180,true);
Scrapper.set(false);
TurnMaxTimePID(AngPara, 0,0.8, true);
MoveEncoderPID(TestPara, 70,7, 0.1,0,true);
wait(100,msec);
RunSecondStage(100);

}
void AWP(){
    // declare initial conditions
    //AWP
    //Solo AWP
    PIDDataSet TestPara={2.9,0.15,0.25};
    PIDDataSet AngPara={2.7,0.05,0.25};
    //Collect 3&score
    RunSecondStage(-50);
    RunBottom(100);
    //TurnMaxTimePID(AngPara, -30, 0.5, true);
    MoveEncoderPID(TestPara, 100,19, 0.5,-31,true);
    MoveEncoderPID(TestPara, 50,13, 0.5,-29,true);
    //RunRoller(90);
    TurnMaxTimePID(AngPara, 43,0.3, true);
    MoveEncoderPID(TestPara, 90,13, 0.5,45,true);
    IntakeBoth(-100);
    wait(2100,msec);
    IntakeBoth(0);
    MoveEncoderPID(TestPara, -80,13, 0.5,43,true);
    //Collect other 3&score
    RunBottom(100);
    //TurnMaxTimePID(AngPara, 90,0.3, true);
    MoveEncoderPID(TestPara, 100,50, 0.4,86,true);
    MoveEncoderPID(TestPara, 80,17, 0.5,87,true);
    TurnMaxTimePID(AngPara, -47,0.3, true);
    MoveEncoderPID(TestPara, 100,20, 0.3,-53,true);
    RunBottom(-80);
    //MoveEncoderPID(TestPara, 100,6, 0.2,-53,true);
    wait(200,msec);
    //MoveEncoderPID(TestPara, 100,11, 0.5,-55,true);
    //Collect match loader&score
    /*(TestPara, -100,67, 0.5,-45,true);
    Tilt.set(true);
    Clamp.set(true);
    TurnMaxTimePID(AngPara, 180,0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 80,36, 0.3,180,false);
    wait(200,msec);
    MoveEncoderPID(TestPara, -100,15, 0.5,180,true);
    Tilt.set(false);
    IntakeBoth(-60); 
    TurnMaxTimePID(AngPara, 0,0.4, true);
    MoveEncoderPID(TestPara, 100,13, 0.3,-2,true);
    IntakeBoth(-100);
    //
*/
    
}
void testskills(){
    //Skills
}
//Ignore all code after this point for now
void test4(){
    //Possible 6+3
}
void test5(){
// Use this to tune PID values
PIDDataSet TestPara={1.1,0.03,0.31};
PIDDataSet AngPara={1.5,0.1,0.13};
RunSecondStage(17);
RunBottom(100);
MoveEncoderPID(TestPara, 80,17, 0.4,31,true);
wait(200,msec);
Scrapper.set(true);
MoveEncoderPID(TestPara, 100,14, 0.1,29,true);
wait(100,msec);
TurnMaxTimePID(AngPara, 135,0.3, true);
MoveEncoderPID(TestPara, 100,39.5, 0.1,135,true);
wait(100,msec);
TurnMaxTimePID(AngPara, 180,0.5, true);
MoveEncoderPID(TestPara, 70,25, 0.1,180,true);
wait(670,msec);
MoveEncoderPID(TestPara, -70,19, 0.1,180,true);
Scrapper.set(false);
TurnMaxTimePID(AngPara, 0,0.5, true);
MoveEncoderPID(TestPara, 70,11, 0.1,0,true);
wait(100,msec);
RunSecondStage(100);

//MoveEncoderPID(TestPara, -100,24, 0.1,0,true);
//wait(500, msec);

}


void ninetest() {
    }
