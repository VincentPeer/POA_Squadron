//
// Created by Vincent on 31.03.2022.
//

#ifndef LABO02_SQUADRON_H
#define LABO02_SQUADRON_H

#include <string>
#include <ostream>
#include "Ship.h"

class Squadron {
    std::string name;
    Ship* chief;
    Ship* listHead;

    struct Maillon {
        Ship ship;
        Ship* next;
    };

public:
    Squadron(std::string name) {
        this->name = name;
    }

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

    std::ostream& operator<<(std::ostream os&, const Squadron& squadron);



};


#endif //LABO02_SQUADRON_H
