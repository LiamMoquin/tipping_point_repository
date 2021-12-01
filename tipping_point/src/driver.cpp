#include "main.h"
int slow = 1;
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
    if (master.get_digital(E_CONTROLLER_DIGITAL_B)){
        slow = 4;
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_X)){
        slow = 1;
    }
    
    int lSpeed = master.get_analog(ANALOG_LEFT_Y) / slow;
    int rSpeed = master.get_analog(ANALOG_RIGHT_Y)/slow;

    lf.move(lSpeed);
    lb.move(lSpeed);
    rf.move(rSpeed);
    rb.move(rSpeed);

    tCont();
}

void tCont(){
    mt.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    mf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    int mtSpeed;
    if(master.get_digital(E_CONTROLLER_DIGITAL_L1)){
        mtSpeed = 150;
    }
    else if((master.get_digital(E_CONTROLLER_DIGITAL_L1) && master.get_digital(E_CONTROLLER_DIGITAL_L2)) == false){
        mtSpeed = 0;
    }
        int mtSpeed;

    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)){
        mtSpeed = -100;
    }
    mt.move(mtSpeed);
    mf.move(mfSpeed);
}