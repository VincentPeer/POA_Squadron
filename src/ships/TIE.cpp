//
// Created by dimde on 4/2/2022.
//
#include "TIE.h"

const double TIE::WEIGHT = 6;
const unsigned TIE::MAX_SPEED = 100;
const std::string TIE::MODEL =  "TIE/LN";
unsigned TIE::NUM = 0;

TIE::TIE() : Ship(++NUM) {}

double TIE::getWeight() const {
   return WEIGHT;
}

unsigned TIE::getMaxSpeed() const {
   return MAX_SPEED;
}

std::string TIE::getModel() const {
   return MODEL;
}

