//
// Created by Vincent on 31.03.2022.
//

#ifndef LABO02_SQUADRON_H
#define LABO02_SQUADRON_H

#include <string>
#include <ostream>
#include "ships/Ship.h"

class Squadron {

   class ShipList {

      struct Link {
         const Ship *ship;
         Link *next;
         Link *prev;
      };

   public:

      Link beforeFirst; // todo voir protegers variable
      size_t size;
      ShipList() : beforeFirst(), size(0){}

      ShipList(const ShipList& list) : ShipList() {
         const Link* L = &list.beforeFirst;
         while (L->next != nullptr)
            add(L->ship);
      }

      void add(const Ship* ship) {
         beforeFirst.next = new Link{ship, beforeFirst.next, nullptr};
         ++size;
      }

      void del(const Ship* ship) {
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

      Ship* get(size_t i) {
         Link* l = &beforeFirst;
         for (size_t j = 0; j <= i; ++j) {
            if (l->next == nullptr)
               throw std::runtime_error("Argument out of range");
            l = l->next;
         }
         return const_cast<Ship *>(l->ship);
      }
   };

   std::string name;
   ShipList ships;
   Ship* chief;


public:
    Squadron(std::string  name);
    Squadron(const Squadron& squadron);
    Squadron* joinDynamic(const Ship& ship);
    Squadron& join(const Ship& ship);
    Squadron* leaveDynamic(const Ship& ship);
    Squadron& leave(const Ship& ship);
    Ship& get(size_t i) const;
    Ship& get(size_t i);


    Squadron* operator+(const Ship& ship);
    Squadron& operator+=(const Ship& ship);
    Squadron* operator-(const Ship& ship);
    Squadron& operator-=(const Ship& ship);
    Ship& operator[](size_t i) const;
    Ship& operator[](size_t i);

    unsigned getConsumption(unsigned distance, unsigned speed);

    std::ostream& operator<<(std::ostream& os);



};


#endif //LABO02_SQUADRON_H
