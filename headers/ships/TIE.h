//
// Created by dimde on 4/2/2022.
//

#ifndef POA_SQUADRON_TIE_H
#define POA_SQUADRON_TIE_H

#include "Ship.h"

#define WEIGHT 360
#define MAX_SPEED 54
#define MODEL "TIE/LN"
class TIE : public Ship {
   unsigned getNum();
public:
   TIE();
};


#endif //POA_SQUADRON_TIE_H
