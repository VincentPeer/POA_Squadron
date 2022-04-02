//
// Created by Vincent on 31.03.2022.
//

#include "../headers/Squadron.h"

#include <utility>

using namespace std;
Squadron::Squadron(std::string  name) : name(std::move(name)), ships(), chief(nullptr){}

Squadron::Squadron(const Squadron &squadron) :name(squadron.name), ships(squadron.ships), chief(nullptr){}

Squadron* Squadron::joinDynamic(const Ship& ship) {
   Squadron* newSquad = new Squadron(*this);
   newSquad->join(ship);
   return newSquad;
}

Squadron &Squadron::join(const Ship &ship) {
   ships.add(&ship);
   return *this;
}

Squadron *Squadron::leaveDynamic(const Ship &ship) {
   Squadron* newSquad = new Squadron(*this);
   newSquad->leave(ship);
   return newSquad;
}

Squadron &Squadron::leave(const Ship &ship) {
   ships.del(&ship);
   return *this;
}

Ship &Squadron::get(size_t i) {
   return *ships.get(i);
}

Squadron &Squadron::operator+=(const Ship &ship) {
   join(ship);
   return *this;
}

Squadron &Squadron::operator-=(const Ship &ship) {
   leave(ship);
   return *this;}

Ship &Squadron::operator[](size_t i) {
   return get(i);
}

unsigned Squadron::getConsumption(unsigned int distance, unsigned int speed) {
   unsigned consumed = 0;

   for (size_t i = 0; i < ships.size; ++i) {
      consumed += ships.get(i)->fuelConsumed(speed, distance); // todo pas efficace pour une linked list
   }
   return consumed;
}

std::ostream &Squadron::operator<<(std::ostream& os) {
   for (size_t i = 0; i < ships.size; ++i) {
     os << ships.get(i) << endl; // todo pas efficace pour une linked list
   }

   return os;
}




