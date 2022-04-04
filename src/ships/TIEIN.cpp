//
// Created by dimde on 4/4/2022.
//

#include "TIEIN.h"

#define WEIGHT 5
#define MAX_SPEED 110
#define MODEL "TIE/IN"

static unsigned num = 0;
TIEIN::TIEIN() : Ship(WEIGHT, MAX_SPEED, makeModelId(MODEL, ++num)) {}
