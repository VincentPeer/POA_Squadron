//
// Created by dimde on 4/2/2022.
//

#include <Ship.h>
#include "Carrier.h"

using namespace std;

Carrier::Carrier(double load, double maxload, unsigned num) : Ship(num){
   if (load > maxload)
      throw invalid_argument("Exceeding max load");
   this->load = load;
}

std::ostream &Carrier::toStream(ostream &os) const {
   Ship::toStream(os);
   os << " Cargo : " << load << " tons (max: " << getMaxLoad() << ")" << endl;
   return os;
}

double Carrier::getTotalWeight() const {
   return getWeight() + load;
}

bool Carrier::setLoad(double load) {
   if (load <= getMaxLoad()) {
      this->load = load;
      return true;
   }
   return false;
}

double Carrier::getLoad() const {
   return load;
}



