//
// Created by dimde on 4/2/2022.
//

#include "Shuttle.h"
Shuttle::Shuttle(double load)
   : Carrier(WEIGHT, MAX_SPEED, load, MAX_LOAD, makeModelId(MODEL, getNum())) {
}

unsigned Shuttle::getNum() {
   static unsigned num;
   return ++num;
}
