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
RunSecondStage(10);
RunBottom(100);
MoveEncoderPID(TestPara, 100,4.5, 0.4,0,false);//go toward 3 balls
wait(200,msec);
MoveEncoderPID(TestPara, 80,55, 0.1,80,false);//curve towards long goal

MoveEncoderPID(TestPara, 24,20, 0.1,-5,true);//curve towards 2 balls
wait(900,msec);

//Addcodehere

wait(200,msec);
TurnMaxTimePID(AngPara, 24,0.5, true);//turn to goal

MoveEncoderPID(TestPara, -100,9.5, 0.1,70,false);//back up from center
Scrapper.set(false);
MoveEncoderPID(TestPara, -100,7.5, 0.1,0,false);//back up towards scoring area
MoveEncoderPID(TestPara, -100,35.5, 0.1,-90,false);//curve around goal
TurnMaxTimePID(AngPara, 0,0.7, true);//turn to goal
Lift.set(true);
wait(400,msec);
MoveEncoderPID(TestPara, 80,21.5, 0.1,0,true);//go toward goal for scoring
RunSecondStage(100);

wait(1300,msec);
RunSecondStage(17);
RunBottom(100);
wait(300,msec);
MoveEncoderPID(TestPara, -100,11, 0.1,0,true);//back up from goal

Scrapper.set(true);
TurnMaxTimePID(AngPara, -160,0.5, true);//turn to match load
MoveEncoderPID(TestPara, 60,20, 0.1,180,true);//match load
wait(660,msec);
MoveEncoderPID(TestPara, -70,19, 0.1,180,true);//back up from match load
Scrapper.set(false);
TurnMaxTimePID(AngPara, 0,0.8, true);//turn toward long goal
MoveEncoderPID(TestPara, 70,7, 0.1,0,true);//
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
    PIDDataSet TestPara={1.1,0.02,0.31};
    PIDDataSet AngPara={1.4,0.03,0.13};
    Lift.set(true);
    RunBottom(100);
    Scrapper.set(true);
    MoveEncoderPID(TestPara, 70,38, 0.6,0,true);
    wait(100,msec);
    TurnMaxTimePID(AngPara, 90,0.7, true);
    wait(100,msec);
    //Matchload
    MoveEncoderPID(TestPara, 80,25, 0.3,87,false);
    wait(200,msec);
    RunSecondStage(17);
    MoveEncoderPID(TestPara, 40,8, 0.2,87,false);
    RunSecondStage(100);
    MoveEncoderPID(TestPara, 40,2.5, 0.2,87,false);
    RunSecondStage(12);
    MoveEncoderPID(TestPara, 40,6,0.4,87,false);
    RunSecondStage(0);
    MoveEncoderPID(TestPara, -80,12, 0.4,87,true);
    RunBottom(0);
    Scrapper.set(false);
    TurnMaxTimePID(AngPara, -88,1, true);
    MoveEncoderPID(TestPara, 70,14, 0.4,-88,true);
    RunSecondStage(100);
    RunBottom(100);
    wait(1700,msec);
    MoveEncoderPID(TestPara, -80,12, 0.4,-90,true);
    TurnMaxTimePID(AngPara, -140,0.5, true);
    RunSecondStage(17);
    MoveEncoderPID(TestPara, 45,33, 0.4,-135,true);
    wait(300,msec);
    //Scrapper.set(true);
    MoveEncoderPID(TestPara, 25,15, 0.1,-140,true);
    wait(200,msec);
    MoveEncoderPID(TestPara, -80,43, 0.4,-140,true);
    wait(100,msec);
    //Scrapper.set(false);
    TurnMaxTimePID(AngPara, -89,0.7, true);
    MoveEncoderPID(TestPara, 80,16, 0.1,-90,true);
    RunSecondStage(100);
    wait(700,msec);
    //Next side 
    RunSecondStage(-17);
    MoveEncoderPID(TestPara, -80,12, 0.1,-90,true);
    RunSecondStage(0);
    TurnMaxTimePID(AngPara, -45,0.5, true);
    MoveEncoderPID(TestPara, 80,18, 0.4,-45,true);
    TurnMaxTimePID(AngPara, -90,0.7, true);
    MoveEncoderPID(TestPara, 100,100, 0.1,-90,true);
    Scrapper.set(true);
    //Tuning
    MoveEncoderPID(TestPara, 50,23, 0.1,-145,true);
    TurnMaxTimePID(AngPara, -90,0.7, true);
    MoveEncoderPID(TestPara, 70,20, 0.1,-90,true);
    MoveEncoderPID(TestPara, 100,25, 0.3,-87,false);
    wait(200,msec);
    RunSecondStage(17);
    MoveEncoderPID(TestPara, 40,8, 0.2,-87,false);
    RunSecondStage(100);
    MoveEncoderPID(TestPara, 40,2.5, 0.2,-87,false);
    RunSecondStage(17);
    MoveEncoderPID(TestPara, 40,6,0.7,-87,false);
    RunSecondStage(0);
    MoveEncoderPID(TestPara, -100,12, 0.4,-87,true);
    RunBottom(0);
    Scrapper.set(false);
    TurnMaxTimePID(AngPara, 90,0.7, true);
    MoveEncoderPID(TestPara, 70,14, 0.4,90,true);
    RunSecondStage(100);
    RunBottom(100);
    wait(1700,msec);
    MoveEncoderPID(TestPara, -100,42, 0.4,90,true);
    TurnMaxTimePID(AngPara, 180,0.7, true);
    MoveEncoderPID(TestPara, 100,36, 0.4,180,true);
    MoveEncoderPID(TestPara, 40,24, 0.4,180,true);
    MoveEncoderPID(TestPara, 40,12, 0.1,180,true);
    TurnMaxTimePID(AngPara, 140,0.7, true);
    MoveEncoderPID(TestPara, 40,24, 0.1,140,true);
    
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
