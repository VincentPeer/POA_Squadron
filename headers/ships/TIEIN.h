//
// Created by dimde on 4/4/2022.
//

#ifndef POA_SQUADRON_TIEIN_H
#define POA_SQUADRON_TIEIN_H

#include "Ship.h"

/**
 * Class extending Ship and representing a TIE/IN ship, storing model name, max speed and weight
 * @author De Bleser Dimitri
 * @author Peer Vincent
 */
class TIEIN : public Ship {
   static const double WEIGHT;
   static const unsigned MAX_SPEED;
   static const std::string MODEL;
   static unsigned NUM;

public:

   /**
    * TIEIN constructor, sets the unique model ID
    */
   TIEIN();

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

#endif //POA_SQUADRON_TIEIN_H
