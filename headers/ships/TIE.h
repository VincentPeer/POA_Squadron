//
// Created by dimde on 4/2/2022.
//

#ifndef POA_SQUADRON_TIE_H
#define POA_SQUADRON_TIE_H

#include "Ship.h"

/**
 * Class extending Ship and representing a TIE/LN ship, storing model name, max speed and weight
 * @author De Bleser Dimitri
 * @author Peer Vincent
 */

class TIE : public Ship {
   static const double WEIGHT;
   static const unsigned MAX_SPEED;
   static const std::string MODEL;
   static unsigned NUM;

public:

   /**
    * TIE constructor, sets the unique model ID
    */
   TIE();

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


#endif //POA_SQUADRON_TIE_H
