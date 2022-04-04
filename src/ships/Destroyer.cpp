//
// Created by dimde on 4/4/2022.
//

#include "Destroyer.h"

#define WEIGHT 9e9
#define MAX_LOAD 250e3
#define MAX_SPEED 40
#define MODEL "Super-class Star Destroyer"

static unsigned num = 0;
Destroyer::Destroyer(double load)
   : Carrier(WEIGHT, MAX_SPEED, load, MAX_LOAD, makeModelId(MODEL, ++num)) {
}