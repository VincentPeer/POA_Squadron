//
// Created by Vincent on 31.03.2022.
//

#include "../headers/Squadron.h"

#include <utility>

using namespace std;
Squadron::Squadron(std::string  name)
   : name(std::move(name)), ships(), leader(nullptr){
}

Squadron::Squadron(const Squadron &squadron)
   : name(squadron.name), ships(squadron.ships), leader(nullptr){
}

Squadron* Squadron::joinDynamic(const Ship& ship) {
   Squadron* newSquad = new Squadron(*this);
   newSquad->join(ship);
   return newSquad;
}

Squadron &Squadron::join(const Ship& ship) {
   ships.add((Ship*) &ship);
   return *this;
}

Squadron *Squadron::leaveDynamic(const Ship& ship) {
   Squadron* newSquad = new Squadron(*this);
   newSquad->leave(ship);
   return newSquad;
}

Squadron &Squadron::leave(const Ship& ship) {
   ships.del((Ship*) &ship);
   return *this;
}

Ship &Squadron::get(size_t i) {
   Link* l = &ships.beforeFirst;
   if (i >= ships.size)
      throw std::runtime_error("Argument out of range");

   for (size_t j = 0; j <= i; ++j)
      l = l->next;

   return *l->ship;
}


Squadron &Squadron::operator+=(const Ship &ship) {
   join(ship);
   return *this;
}

Squadron &Squadron::operator-=(const Ship &ship) {
   leave(ship);
   return *this;
}

Ship &Squadron::operator[](size_t i) {
   return get(i);
}

unsigned Squadron::getConsumption(unsigned int distance, unsigned int speed) {
   unsigned consumed = 0;
   Link* l = &ships.beforeFirst;

   for (size_t i = 0; i < ships.size; ++i) {
      l = l->next;
      consumed += l->ship->getConsumption(speed, distance); // todo pas efficace pour une linked list
   }
   return consumed;
}

void Squadron::setLeader(const Ship& leader) {
   this->leader = &leader;
}

std::ostream &operator<<(ostream &os, Squadron squad) {
   Squadron::Link* l = &squad.ships.beforeFirst;

   for (size_t i = 0; i < squad.ships.size; ++i) {
      l = l->next;
      l->ship->toStream(os) << endl; // todo pas efficace pour une linked list
   }
   return os;
}




