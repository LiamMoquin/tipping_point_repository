#include "main.h"

void trigCalc(double a = 54, double o = 27){
    
    double angle = tan(o/a);
    double dist = hypot(a, o);
    //turn to angle
    //move dist
}

void turn(double tAngle){
    double kP = 0.2; //tuning value
    double kD = 0; //tuning value
    double error = (tAngle - imu_sensor.get_heading()); //How far off from target angle
    double lastError = 0; //error at end of last loop
    double errorRange = 0.2; //maximum final error
    int rol = 1; //should the robot turn right or left -1 being left and 1 being right
    if(error >= 180){ 
        rol = -1; //sets rol to -1
    }
    else if(error < 180){
        rol = 1;
    }
    while(abs(error) > errorRange){ //while the absolute value of error is greater than errorRange
        error = (tAngle - imu_sensor.get_heading()); //error target angle - the current heading of the bot
        
        lb.move_velocity(((error * kP) + kD * (error - lastError)) * rol); //fancy math to move the motors
        lf.move_velocity(((error * kP) + kD * (error - lastError)) * rol);
        rb.move_velocity(((error * kP) + kD * (error - lastError)) * (rol * -1)); //fancy math to move the motors in reverse
        rf.move_velocity(((error * kP) + kD * (error - lastError)) * (rol * -1));
        
        lastError = error; //last error = error
    }
}

void drive(double speed){
    lf.move_velocity(speed);
    lb.move_velocity(speed);
    rf.move_velocity(speed);
    rb.move_velocity(speed);
    
}

void motorStop(){
    lf.move_velocity(0);
    lb.move_velocity(0);
    rf.move_velocity(0);
    rb.move_velocity(0);
}

void towerMove(double degrees, double speed = 75){
    mt1.move_relative(degrees, speed);
    mt2.move_relative(degrees, speed);
}


void driveStrt(double dist, double speed){
    double kp = 0;
    double kd = 0;

    lf.tare_position;
    lb.tare_position;
    rf.tare_position;
    rb.tare_position;

    double motorAvg
}