//
// Created by dimde on 4/2/2022.
//

#ifndef POA_SQUADRON_CARRIER_H
#define POA_SQUADRON_CARRIER_H

#include "Ship.h"

class Carrier : public Ship {
   unsigned load;
public:

   Carrier(unsigned load);
   unsigned getConsumption(unsigned distance, unsigned speed);
};


#endif //POA_SQUADRON_CARRIER_H
