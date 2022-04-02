#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include <string>

class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship);
class Ship {
   std::string aka;
   std::string id;

protected:
   unsigned getConsumption(unsigned speed, unsigned distance, unsigned weight) const;

public:
   virtual ~Ship();
   /* à compléter */
   virtual std::ostream& toStream(std::ostream& os) const;
   virtual unsigned getMaxSpeed() const = 0;
   virtual unsigned getWeight() const = 0;
   virtual unsigned getConsumption(unsigned speed, unsigned distance) const;

private:
   /* à compléter */
};
#endif /* SHIP_HPP */