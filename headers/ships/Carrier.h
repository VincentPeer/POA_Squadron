//
// Created by dimde on 4/2/2022.
//

#ifndef POA_SQUADRON_CARRIER_H
#define POA_SQUADRON_CARRIER_H

#include "Ship.h"

/**
 *  Abstract class, adding loading capacity to Ship class
 * @author De Bleser Dimitri
 * @author Peer Vincent
 */
class Carrier : public Ship {
   double load;

protected:

   /**
    * Constructor with load, maxLoad, and ID specifier
    * @param load current load in metric tons
    * @param maxLoad load capacity in tons
    * @param num model ID number
    */
   explicit Carrier(double load, double maxLoad, unsigned num);

public:

   /**
    * Write into am output stream
    * @param os stream to write in
    * @return The given stream
    */
   std::ostream& toStream(std::ostream& os) const override;

   /**
    * Get to total weight of the plane including load
    * @return total weight in tons
    */
   double getTotalWeight() const override;

   /**
    * Get the ship's current load
    * @return The load in tons
    */
   double getLoad() const;

   /**
    * set the current load of the ship
    * @param load current load in metric tons
    * @return True if the load is smaller or equal to max load and has been set
    */
   bool setLoad(double load);

   /**
    * Get the ship's load capacity
    * @return load capacity in tons
    */
   virtual double getMaxLoad() const = 0;

};


#endif //POA_SQUADRON_CARRIER_H
