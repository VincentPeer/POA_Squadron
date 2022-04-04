//
// Created by dimde on 4/2/2022.
//

#include "Shuttle.h"

#define WEIGHT 360
#define MAX_LOAD 80
#define MAX_SPEED 54
#define MODEL "Lambda-class shuttle"

static unsigned num = 0;
Shuttle::Shuttle(double load)
   : Carrier(WEIGHT, MAX_SPEED, load, MAX_LOAD, makeModelId(MODEL, ++num)) {
}


