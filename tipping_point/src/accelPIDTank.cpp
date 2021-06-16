#include "main.h"

//setting up variables
double totalDegrees;//how many degrees the wheels need to rotate in total
double lastError;//the error in the last run
double error;//the current error
double akP = 0.2;//kP tuning value
double akD = 0;//kD tuning value

//resets motor values
void mtrReset(){
    lf.tare_position();
    rf.tare_position();
    lb.tare_position();
    rb.tare_position();
}

//start drive straight acceleration program
void sDSAccel(double dist, double startPower, double endPower, double rampUpValue){//takes the distance, the startpower, the endpower and over what distance of the total to accelerate over
    double motoravg;//defines the variable for the motor avg
    error = 0;//sets the error to 0
    lastError = 0;//sets the last error to 0
    
    mtrReset();

    //calculates the degrees needed to move
    totalDegrees = dist/(4*okapi::pi)*360;//distance in inches / by (the diameter of the wheels * pi) converted to degrees

    //how many degrees to move in this function
    double degtoRotate = totalDegrees * rampUpValue;
    
    //while motor average is greater than or equal to total degrees
    while(motoravg >= degtoRotate){
        error = abs(lb.get_position()) - abs(rb.get_position());//sets the error to the absolute value of the back motors

        motoravg = (lb.get_position() + rb.get_position()) / 2;//sets the motor average to to the back motors /2
        double accelCalcOutput = (endPower - startPower)*(motoravg / degtoRotate) + startPower;//calculates the speed at which to accel
        
        //tells the motors to move at a speed
        lb.move_velocity(((error * akP) + akD * (error - lastError)) + accelCalcOutput);
        lf.move_velocity(((error * akP) + akD * (error - lastError)) + accelCalcOutput);
        rb.move_velocity(accelCalcOutput - ((error * akP) + akD * (error - lastError)));
        rf.move_velocity(accelCalcOutput - ((error * akP) + akD * (error - lastError)));

        lastError = error;//sets last error to whatever error was this run

        motoravg = ((lb.get_position() + rb.get_position()) / 2);//gets the average between the 2 back motors
    }
}


//continue drive straight acceleration code
//this code is different from sDSAccel because it doesn't calculate the distance or reset the errors
void cDSAccel(double startPower, double endPower, double rampUpValue){//missing the distance input from sDSAccel
    double motoravg;

    double degToRotate = totalDegrees * rampUpValue;
    
    while(motoravg >= degToRotate){
        error = abs(lb.get_position()) - abs(rb.get_position());

        motoravg = (lb.get_position() + rb.get_position()) / 2;
        double accelCalcOutput = (endPower - startPower)*(motoravg / degToRotate) + startPower;
        
        lb.move_velocity(((error * akP) + akD * (error - lastError)) + accelCalcOutput);
        lf.move_velocity(((error * akP) + akD * (error - lastError)) + accelCalcOutput);
        rb.move_velocity(accelCalcOutput - ((error * akP) + akD * (error - lastError)));
        rf.move_velocity(accelCalcOutput - ((error * akP) + akD * (error - lastError)));
        error = lastError;

        motoravg = ((lb.get_position() + rb.get_position()) / 2);
    }
}


//lowers the speed of the robot
void DSDecel(double startPower, double endPower, double rampDownValue){
    double motoravg;
    
    double degToRotate = totalDegrees * rampDownValue;

    while(motoravg >= degToRotate){
        error = abs(lb.get_position()) - abs(rb.get_position());

        motoravg = (lb.get_position() + (rb.get_position()) / 2;
        double decelCalcOutput = (endPower - startPower) * (motoravg / degToRotate) + startPower;

        lb.move_velocity(decelCalcOutput + ((error * akP) + akD * (error - lastError)));
        lf.move_velocity(decelCalcOutput + ((error * akP) + akD * (error - lastError)));
        rb.move_velocity(decelCalcOutput - ((error * akP) + akD * (error - lastError)));
        rf.move_velocity(decelCalcOutput - ((error * akP) + akD * (error - lastError)));
        error = lastError;

        motoravg = (lb.get_position() + rb.get_position()) / 2;
    }
}