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

int bof = 1;
void arcDrive(){
    if(master.get_digital(E_CONTROLLER_DIGITAL_B)){
        bof = -1;
    }
    if(master.get_digital(E_CONTROLLER_DIGITAL_X)){
        bof = 1;
    }
    lf.move(bof*(master.get_analog(ANALOG_LEFT_Y) + bof * master.get_analog(ANALOG_LEFT_X)/2));
    lb.move(bof*(master.get_analog(ANALOG_LEFT_Y) + bof * master.get_analog(ANALOG_LEFT_X)/2));
    rf.move(bof*(master.get_analog(ANALOG_LEFT_Y) - bof * master.get_analog(ANALOG_LEFT_X)/2));
    rb.move(bof*(master.get_analog(ANALOG_LEFT_Y) - bof * master.get_analog(ANALOG_LEFT_X)/2));
    
    mt1.move_velocity(master.get_analog(ANALOG_RIGHT_Y));
    mt2.move_velocity(master.get_analog(ANALOG_RIGHT_Y));

    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)){
        piston.set_value(true);
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)){
        piston.set_value(false);
    }

    if(master.get_digital(E_CONTROLLER_DIGITAL_L1)){
        sml1.move_velocity(100);
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)){
        sml1.move_velocity(-100);
    }
    else if(!(master.get_digital(E_CONTROLLER_DIGITAL_L1)) && !(master.get_digital(E_CONTROLLER_DIGITAL_L2))){
        sml1.move_velocity(0);
    }
    
    if (master.get_digital(E_CONTROLLER_DIGITAL_X)){
        tGrabber.move_velocity(1000);
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_Y)){
        tGrabber.move_velocity(-1000);
    }
    else if (!(master.get_digital(E_CONTROLLER_DIGITAL_X)) && !(master.get_digital(E_CONTROLLER_DIGITAL_Y))){
        tGrabber.move_velocity(0);
    }
}


void tdrive(){    
    int lSpeed = master.get_analog(ANALOG_LEFT_Y) / slow;
    int rSpeed = master.get_analog(ANALOG_RIGHT_Y) / slow;

    lf.move(lSpeed);
    lb.move(lSpeed);
    rf.move(rSpeed);
    rb.move(rSpeed);

    tCont();

    // if (master.get_digital(E_CONTROLLER_DIGITAL_DOWN)){
    //     slow = 4;
    // }
    // else if (master.get_digital(E_CONTROLLER_DIGITAL_UP)){
    //     slow = 1;
    // }
    /*if (master.get_digital(E_CONTROLLER_DIGITAL_Y)){
        balance();
    }*/
}


void tCont(){
    int mtSpeed;
    int mfSpeed;
    if((master.get_digital(E_CONTROLLER_DIGITAL_R1)) == true){
        mtSpeed = 200;
    }
    else if((master.get_digital(E_CONTROLLER_DIGITAL_R2)) == true){
        mtSpeed = -200;
    }
    else if((master.get_digital(E_CONTROLLER_DIGITAL_R1) && master.get_digital(E_CONTROLLER_DIGITAL_R2)) == false){
        mtSpeed = 0;
    }


    if (master.get_digital(E_CONTROLLER_DIGITAL_L1)){
        piston.set_value(true);
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)){
        piston.set_value(false);
    }


    if(master.get_digital(E_CONTROLLER_DIGITAL_UP)){
        mfSpeed = 100;
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN)){
        mfSpeed = -100;
    }
    else if((master.get_digital(E_CONTROLLER_DIGITAL_UP) && master.get_digital(E_CONTROLLER_DIGITAL_DOWN)) == false){
        mfSpeed = 0;
    }
    mt1.move(mtSpeed);
    mt2.move(mtSpeed);
    sml1.move(mfSpeed);
}