#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include <string>

class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship);
class Ship {
   std::string aka;
   std::string id;


public:
   virtual ~Ship();
   /* à compléter */
   virtual std::ostream& toStream(std::ostream& os) const;
   virtual unsigned getMaxSpeed() const = 0;
   virtual unsigned getWeight() const = 0;
   virtual unsigned fuelConsumed(int speed, int distance) const;
private:
   /* à compléter */
};
#endif /* SHIP_HPP */