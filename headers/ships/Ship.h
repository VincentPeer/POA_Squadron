#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include <string>

class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship); //todo no usage

/**
 * Abstract class representing an undefined ship
 * @author De Bleser Dimitri
 * @author Peer Vincent
 */
class Ship {
   std::string aka;
   const unsigned ID;

protected:

   /**
    * Constructor with model ID
    * @param id
    */
   Ship(unsigned id);


public:

   /**
    * default virtual destructor
    */
   virtual ~Ship() = default;

   /**
    * Affectation operation
    * @param ship
    * @return reference to the modified ship
    */
//   virtual Ship& operator=(const Ship& ship) = 0;

   /**
    * Writes details of the ship to a given stream
    * @param os
    * @return the stream
    */
   virtual std::ostream& toStream(std::ostream& os) const;

   /**
    * returns the max speed of the ship
    * @return speed in MGLT
    */
   virtual unsigned getMaxSpeed() const = 0;

   /**
    * Get ship's weight
    * @return weight in tons
    */
   virtual double getWeight() const = 0;

   /**
    * get model name
    * @return string representing model name
    */
   virtual std::string getModel() const = 0;

   /**
    * Get the ships model ID
    * @return unsigned model ID
    */
   unsigned getId() const;

   /**
    * Total weight of the ship including cargo if any
    * @return weight in tons
    */
   virtual double getTotalWeight() const;

   /**
     * Calculate the fuel consomption for a given distance and speed
     * @param distance
     * @param speed
     * @return fuel consomption in tons
     */
   virtual double getConsumption(unsigned speed, double distance) const;

   /**
    * Concatenates the model name with an number to make unique ship ID
    * @return string representing ship's name / ID
    */
   std::string getModelId() const;

   /**
    * Get the ship's nickname
    * @return ship's nickname as string
    */
   std::string getNickname() const;

   /**
    * Sets the nickname of the ship
    * @param name
    */
   void setNickname(std::string name);
};
#endif /* SHIP_HPP */