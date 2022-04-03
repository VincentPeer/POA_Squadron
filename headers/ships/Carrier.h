//
// Created by dimde on 4/2/2022.
//

#ifndef POA_SQUADRON_CARRIER_H
#define POA_SQUADRON_CARRIER_H

#include "Ship.h"

class Carrier : public Ship {
   double load;
   const double MAX_LOAD;

public:
   Carrier(double weight, unsigned maxSpeed, double load, double maxLoad, std::string modelId);
   unsigned getConsumption(unsigned speed, unsigned distance) const override;
   double getMaxLoad() const;
};


#endif //POA_SQUADRON_CARRIER_H
