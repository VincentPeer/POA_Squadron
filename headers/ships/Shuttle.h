//
// Created by dimde on 4/2/2022.
//

#ifndef POA_SQUADRON_SHUTTLE_H
#define POA_SQUADRON_SHUTTLE_H

#include "Carrier.h"

#define WEIGHT 360
#define MAX_LOAD 80
#define MAX_SPEED 54
#define MODEL "Lambda-class shuttle"

class Shuttle : public Carrier {
   unsigned getNum();
public:
   explicit Shuttle(double load);
};


#endif //POA_SQUADRON_SHUTTLE_H
