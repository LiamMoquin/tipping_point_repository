#include "main.h"

void accelCalc(){
    double absAllMotor = (abs(lf.get_position()) + abs(rf.get_position()) + abs(lb.get_position()) + abs(rb.get_position())) / 4;
    double accelCalcOutput = (endPower - startPower)*(absAllMotor / totalDegrees) + startPower;
}

void DSAccel(double dist, double startPower = 20, double endPower = 100, double rampUpValue = .2){
    double kP = 0.2;
    double kD = 0;
    double lastError;
    double error;

    double degToRotate = dist/(4*okapi::pi)*360;//distance in inches / by (the diameter of the wheels * pi) converted to degrees

    double totalDegrees = degToRotate * rampUpValue;
    
    while(true){
        
    }
}