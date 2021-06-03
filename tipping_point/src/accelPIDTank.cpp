#include "main.h"

double degToRotate;
double lastError;
double error;
double dsakP = 0.2;
double dsakD = 0;

void mtrReset(){
    lf.tare_position();
    rf.tare_position();
    lb.tare_position();
    rb.tare_position();
}

void sDSAccel(double dist, double startPower, double endPower, double rampUpValue){
    double motoravg;
    error = 0;
    lastError = 0;
    
    mtrReset();

    degToRotate = dist/(4*okapi::pi)*360;//distance in inches / by (the diameter of the wheels * pi) converted to degrees

    double totalDegrees = degToRotate * rampUpValue;
    
    while(motoravg >= totalDegrees){
        error = abs(lb.get_position()) - abs(rb.get_position());

        double motoravg = (lb.get_position() + rb.get_position()) / 2;
        double accelCalcOutput = (endPower - startPower)*(motoravg / totalDegrees) + startPower;
        
        lb.move_velocity(((error * dsakP) + dsakD * (error - lastError)) + accelCalcOutput);
        lf.move_velocity(((error * dsakP) + dsakD * (error - lastError)) + accelCalcOutput);
        rb.move_velocity(accelCalcOutput - ((error * dsakP) + dsakD * (error - lastError)));
        rf.move_velocity(accelCalcOutput - ((error * dsakP) + dsakD * (error - lastError)));

        error = lastError;

        motoravg = ((lb.get_position() + rb.get_position()) / 2);
    }
}




void cDSAccel(double startPower, double endPower, double rampUpValue){
    double motoravg;

    double totalDegrees = degToRotate * rampUpValue;
    
    while(motoravg >= totalDegrees){
        error = abs(lb.get_position()) - abs(rb.get_position());

        double motoravg = (lb.get_position() + rb.get_position()) / 2;
        double accelCalcOutput = (endPower - startPower)*(motoravg / totalDegrees) + startPower;
        
        lb.move_velocity(((error * dsakP) + dsakD * (error - lastError)) + accelCalcOutput);
        lf.move_velocity(((error * dsakP) + dsakD * (error - lastError)) + accelCalcOutput);
        rb.move_velocity(accelCalcOutput - ((error * dsakP) + dsakD * (error - lastError)));
        rf.move_velocity(accelCalcOutput - ((error * dsakP) + dsakD * (error - lastError)));
        error = lastError;

        motoravg = ((lb.get_position() + rb.get_position()) / 2);
    }
}