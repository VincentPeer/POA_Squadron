//
// Created by dimde on 4/2/2022.
//

#include <Ship.h>
#include "Carrier.h"

Carrier::Carrier(unsigned int load) : load(load) {}

unsigned Carrier::getConsumption(unsigned int distance, unsigned int speed) {
   return Ship::getConsumption(distance, speed, getWeight() + load);
}

