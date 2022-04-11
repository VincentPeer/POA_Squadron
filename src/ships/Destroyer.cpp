//
// Created by dimde on 4/4/2022.
//

#include "Destroyer.h"

const double Destroyer::WEIGHT = 9e9;
const double Destroyer::MAX_LOAD = 250e3;
const unsigned Destroyer::MAX_SPEED = 40;
const std::string Destroyer::MODEL =  "Super-class Star Destroyer";
unsigned Destroyer::NUM = 0;

Destroyer::Destroyer(double load) : Carrier(load, MAX_LOAD, ++NUM) {
}

double Destroyer::getMaxLoad() const {
   return MAX_LOAD;
}

double Destroyer::getWeight() const {
   return WEIGHT;
}

unsigned Destroyer::getMaxSpeed() const {
   return MAX_SPEED;
}

std::string Destroyer::getModel() const {
   return MODEL;
}
