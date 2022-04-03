#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include <string>

class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship);

class Ship {
   std::string aka;
   std::string modelId;
   const double WEIGHT;
   const unsigned MAX_SPEED;

protected:
   std::string makeModelId(const std::string& model, unsigned num);
   unsigned getConsumption(unsigned speed, unsigned distance, double weight) const;
   Ship(double weight, unsigned maxSpeed, std::string modelId);
public:

   virtual ~Ship();
   /* à compléter */
   virtual std::ostream& toStream(std::ostream& os) const;
   unsigned getMaxSpeed() const;
   double getWeight() const;
   virtual unsigned getConsumption(unsigned speed, unsigned distance) const;
   void setNickname(std::string name);
private:
   /* à compléter */
};
#endif /* SHIP_HPP */