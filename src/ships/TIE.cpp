//
// Created by dimde on 4/2/2022.
//
#include "TIE.h"

#define WEIGHT 6
#define MAX_SPEED 100
#define MODEL "TIE/LN"

static unsigned num = 0;
TIE::TIE() : Ship(WEIGHT, MAX_SPEED, makeModelId(MODEL, ++num)) {}

