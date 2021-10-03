#include "main.h"

//xdrive opcontroller function
void xdrive(){
    int power = master.get_analog(ANALOG_RIGHT_Y);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    int strafe = master.get_analog(ANALOG_LEFT_Y);

    int lfPower = power + turn + strafe;
    int rfPower = power - turn - strafe;
    int lbPower = power + turn - strafe;
    int rbPower = power - turn + strafe;
    
    lf.move(lfPower);
    rf.move(rfPower);
    lb.move(lbPower);
    rb.move(rbPower);
}

void tdrive(){
    int lSpeed = master.get_analog(ANALOG_LEFT_Y);
    int rSpeed = master.get_analog(ANALOG_RIGHT_Y);

    lf.move(lSpeed);
    lb.move(lSpeed);
    rf.move(rSpeed);
    rb.move(rSpeed);
}