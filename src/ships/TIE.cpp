//
// Created by dimde on 4/2/2022.
//
#include "TIE.h"

TIE::TIE() : Ship(WEIGHT, MAX_SPEED, makeModelId(MODEL, getNum())) {}

unsigned TIE::getNum() {
   static unsigned num;
   return ++num;
}
