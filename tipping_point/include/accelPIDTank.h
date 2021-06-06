#pragma once
#include "main.h"

//makes these global functions
void sDSAccel(double dist, double startPower, double endPower, double rampUpValue);

void cDSAccel(double startPower, double endPower, double rampUpValue);

void DSDecel(double startPower, double endPower, double rampUpValue);