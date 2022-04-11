//
// Created by dimde on 4/4/2022.
//

#include "TIEIN.h"

const double TIEIN::WEIGHT = 5;
const unsigned TIEIN::MAX_SPEED = 110;
const std::string TIEIN::MODEL =  "TIE/IN";
unsigned TIEIN::NUM = 0;

TIEIN::TIEIN() : Ship(++NUM) {}

double TIEIN::getWeight() const {
   return WEIGHT;
}

unsigned TIEIN::getMaxSpeed() const {
   return MAX_SPEED;
}

std::string TIEIN::getModel() const {
   return MODEL;
}