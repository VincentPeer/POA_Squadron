//
// Created by Vincent on 31.03.2022.
//
#ifndef SHIP_HPP
#define SHIP_HPP

#include "../../headers/ships/Ship.h"
#include <ostream>

class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship);
class Ship {
   public:
   virtual ~Ship();
   /* à compléter */
   virtual std::ostream& toStream(std::ostream& os) const;
   private:
   /* à compléter */
};
#endif /* SHIP_HPP */