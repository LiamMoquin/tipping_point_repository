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


void stupidUselessGarbageDrive(){
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_LEFT_X);
    int left = power + turn;
    int right = power - turn;

    lf.move(left);
    lb.move(left);
    rf.move(right);
    rb.move(right);

    tCont();
    if (master.get_digital(E_CONTROLLER_DIGITAL_Y)){
        balance();
    }
}


void tdrive(){    
    int lSpeed = master.get_analog(ANALOG_LEFT_Y) / slow;
    int rSpeed = master.get_analog(ANALOG_RIGHT_Y) / slow;

    lf.move(-lSpeed);
    lb.move(-lSpeed);
    rf.move(-rSpeed);
    rb.move(-rSpeed);

    tCont();

    if (master.get_digital(E_CONTROLLER_DIGITAL_B)){
        slow = 4;
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_X)){
        slow = 1;
    }
    if (master.get_digital(E_CONTROLLER_DIGITAL_Y)){
        balance();
    }
}


void tCont(){
    int mtSpeed;
    int mfSpeed;
    if((master.get_digital(E_CONTROLLER_DIGITAL_L1)) == true){
        mtSpeed = 200;
    }
    else if((master.get_digital(E_CONTROLLER_DIGITAL_L2)) == true){
        mtSpeed = -200;
    }
    else if((master.get_digital(E_CONTROLLER_DIGITAL_L1) && master.get_digital(E_CONTROLLER_DIGITAL_L2)) == false){
        mtSpeed = 0;
    }


    if (master.get_digital(E_CONTROLLER_DIGITAL_UP)){
        piston.set_value(true);
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN)){
        piston.set_value(false);
    }


    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)){
        mfSpeed = 100;
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)){
        mfSpeed = -100;
    }
    else if((master.get_digital(E_CONTROLLER_DIGITAL_R1) && master.get_digital(E_CONTROLLER_DIGITAL_R2)) == false){
        mfSpeed = 0;
    }
    mt1.move(mtSpeed);
    mt2.move(mtSpeed);
    mf.move(mfSpeed);
}