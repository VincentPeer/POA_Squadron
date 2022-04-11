//
// Created by dimde on 4/2/2022.
//

#include "Shuttle.h"

const double Shuttle::WEIGHT = 360;
const double Shuttle::MAX_LOAD = 80;
const unsigned Shuttle::MAX_SPEED = 54;
const std::string Shuttle::MODEL =  "Lambda-class shuttle";
unsigned Shuttle::NUM = 0;

Shuttle::Shuttle(double load) : Carrier(load, MAX_LOAD, ++NUM) {
}

double Shuttle::getMaxLoad() const {
   return MAX_LOAD;
}

double Shuttle::getWeight() const {
   return WEIGHT;
}

unsigned Shuttle::getMaxSpeed() const {
   return MAX_SPEED;
}

std::string Shuttle::getModel() const {
   return MODEL;
}

