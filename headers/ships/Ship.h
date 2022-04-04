#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include <string>

class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship); //todo no usage

class Ship {
   const unsigned MAX_SPEED;
   std::string aka;
   std::string modelId;
   const double WEIGHT;

protected:

   /**
    * Concatenates the model name with an number to make unique ship id
    * @param model of the ship
    * @param num model number
    * @return string representing ship's name / id
    */
   static std::string makeModelId(const std::string& model, unsigned num);

   /**
     * Calculate the fuel consomption for a given distance and speed weight
     * @param distance
     * @param speed
     * @param weight
     * @return fuel consomption in tons
     */
   unsigned getConsumption(unsigned speed, unsigned distance, double weight) const;
   Ship(double weight, unsigned maxSpeed, std::string modelId);

public:

   virtual ~Ship() = default;
   virtual std::ostream& toStream(std::ostream& os) const; //todo virtual??
   unsigned getMaxSpeed() const;
   virtual double getTotalWeight() const;

   /**
    * Get ship's weight
    * @return weight in
    */
   double getWeight() const;

   /**
     * Calculate the fuel consomption for a given distance and speed weight
     * @param distance
     * @param speed
     * @return fuel consomption in tons
     */
   virtual unsigned getConsumption(unsigned speed, unsigned distance) const;
   void setNickname(std::string name);
};
#endif /* SHIP_HPP */