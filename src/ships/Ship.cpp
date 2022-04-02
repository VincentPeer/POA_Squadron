//
// Created by Vincent on 31.03.2022.
//

#include <cmath>
#include "../../headers/ships/Ship.h"

using namespace std;

unsigned Ship::fuelConsumed(int speed, int distance) const {
   if (speed > getMaxSpeed())
      throw invalid_argument("Specified speed can not be reached by this plane");
   return int (cbrt(getWeight()) * log10(getWeight() * speed)  * log10(distance + 1) / 2);
}

std::ostream &Ship::toStream(ostream &os) const {
   os << id;
   if (!aka.empty())
      os << " aka : " << aka;
   return os;
}
