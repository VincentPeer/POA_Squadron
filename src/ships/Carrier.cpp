//
// Created by dimde on 4/2/2022.
//

#include <Ship.h>
#include "Carrier.h"

using namespace std;

Carrier::Carrier(double weight, unsigned maxSpeed, double load, double maxLoad, string modelId) :
   Ship(weight, maxSpeed, modelId), load(load), MAX_LOAD(maxLoad) {

  if (load > maxLoad)
     throw invalid_argument("Exceeding max load");
  this->load = load;
}

unsigned Carrier::getConsumption(unsigned int distance, unsigned int speed) const {
   return Ship::getConsumption(speed,distance, getWeight() + load);
}

double Carrier::getMaxLoad() const {
   return MAX_LOAD;
}

