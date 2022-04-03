//
// Created by Vincent on 31.03.2022.
//

#ifndef LABO02_SQUADRON_H
#define LABO02_SQUADRON_H

#include <string>
#include <ostream>
#include "ships/Ship.h"

class Squadron {

   struct Link {
      Ship *ship;
      Link *next;
      Link *prev;
   };

   class ShipList {
   public:
      Link beforeFirst; // todo voir protegers variable
      size_t size;
      ShipList() : beforeFirst{nullptr, nullptr, nullptr}, size(0){}

      ShipList(const ShipList& list) : ShipList() {
         const Link* L = &list.beforeFirst;
         while (L->next != nullptr) {
            L = L->next;
            add(L->ship);
         }
      }

      void add(Ship* ship) {
         beforeFirst.next = new Link{ship, beforeFirst.next, nullptr};
         ++size;
      }

      void del(Ship* ship) {
         Link* l = &beforeFirst;
         while (l->next != nullptr) {
            if (l->next->ship == ship) {
               del(l->next);
               break;
            }
               l = l->next;
         }
      }

      void del(Link* m) {
         // Linking prev and next Link
         m->prev->next = m-> next;
         delete m;
         --size;
      }
   };

   std::string name;
   ShipList ships;
   const Ship* leader; // todo const?


public:
    Squadron(std::string  name);
    Squadron(const Squadron& squadron);
    Squadron* joinDynamic(const Ship& ship);
    Squadron& join(const Ship& ship);
    Squadron* leaveDynamic(const Ship& ship);
    Squadron& leave(const Ship& ship);
    Ship& get(size_t i) const;
    Ship& get(size_t i);

    void setLeader(const Ship& leader);

    Squadron* operator+(const Ship& ship);
    Squadron& operator+=(const Ship& ship);
    Squadron* operator-(const Ship& ship);
    Squadron& operator-=(const Ship& ship);
    Ship& operator[](size_t i) const;
    Ship& operator[](size_t i);

    unsigned getConsumption(unsigned distance, unsigned speed);

    friend std::ostream& operator<<(std::ostream& os, Squadron squad);

};


#endif //LABO02_SQUADRON_H
