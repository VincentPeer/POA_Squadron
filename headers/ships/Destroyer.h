//
// Created by dimde on 4/4/2022.
//

#ifndef POA_SQUADRON_DESTROYER_H
#define POA_SQUADRON_DESTROYER_H

#include "Carrier.h"

/**
 * Class extending Carrier and representing a destroyer ship. storing model name, max speed, weight and load capacity
 * @author De Bleser Dimitri
 * @author Peer Vincent
 */
class Destroyer : public Carrier {
   static const double WEIGHT, MAX_LOAD;
   static const unsigned MAX_SPEED;
   static const std::string MODEL;
   static unsigned NUM;

public:

   /**
    * Constructor with actual load specifier, sets unique model ID
    * @param load current load
    */
   explicit Destroyer(double load = 0);

   /**
    * Get the load capacity
    * @return load capacity in tons
    */
   double getMaxLoad() const override;

   /**
    * Get ship's empty weight
    * @return ship's weight in tons
    */
   double getWeight() const override;

   /**
    * Get ship's max speed
    * @return max speed in MLGT
    */
   unsigned getMaxSpeed() const override;

   /**
    * Get the ship model
    * @return ships model name
    */
   std::string getModel() const override;
};



#endif //POA_SQUADRON_DESTROYER_H
