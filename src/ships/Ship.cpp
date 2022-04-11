//
// Created by Vincent on 31.03.2022.
//

#include <cmath>
#include <utility>
#include "../../headers/ships/Ship.h"

using namespace std;

Ship::Ship(unsigned int id) : ID(id) {
}

double Ship::getConsumption(unsigned speed, double distance) const {
   if (speed > getMaxSpeed())
      throw invalid_argument("Specified speed can not be reached by this plane");
   return cbrt(getTotalWeight()) * log10(getTotalWeight() * speed)  * log10(distance + 1) / 2;
}

ostream &Ship::toStream(ostream &os) const {
   if (!aka.empty())
      os << aka << " ";
   os << getModelId() << endl;
   os << " weight : " << getWeight() << " tons" << endl;
   os << " max speed : " << getMaxSpeed() << " MGLT" << endl;

   return os;
}

ostream& operator<<(ostream& os, const Ship& ship) {
   ship.toStream(os);
   return os;
}

void Ship::setNickname(std::string name) {
   aka = std::move(name);
}

std::string Ship::getModelId() const {
   return getModel() + " #" + to_string(ID);
}

double Ship::getTotalWeight() const{
   return getWeight();
}

std::string Ship::getNickname() const{
   return aka;
}

unsigned Ship::getId() const{
   return ID;
}






