//
// Created by Vincent on 31.03.2022.
//

#include <cmath>
#include "../../headers/ships/Ship.h"

using namespace std;

unsigned Ship::getConsumption(unsigned speed, unsigned distance, unsigned weight) const {
   if (speed > getMaxSpeed())
      throw invalid_argument("Specified speed can not be reached by this plane");
   return unsigned (cbrt(weight * log10(weight * speed)  * log10(distance + 1) / 2));
}

unsigned Ship::getConsumption(unsigned speed, unsigned distance) const {
   return getConsumption(speed, distance, getWeight());
}

std::ostream &Ship::toStream(ostream &os) const {
   os << id;
   if (!aka.empty())
      os << " aka : " << aka;
   return os;
}
