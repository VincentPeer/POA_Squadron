//
// Created by Vincent on 31.03.2022.
//

#include <cmath>
#include <utility>
#include "../../headers/ships/Ship.h"

using namespace std;

Ship::Ship(double weight, unsigned int maxSpeed, string modelId)
   : WEIGHT(weight), MAX_SPEED(maxSpeed), modelId(std::move(modelId)) {
}


Ship::~Ship() {
// todo destroy
}

unsigned Ship::getConsumption(unsigned distance, unsigned speed, double weight) const {
   if (speed > getMaxSpeed())
      throw invalid_argument("Specified speed can not be reached by this plane");
   return unsigned (cbrt(weight * log10(weight * speed)  * log10(distance + 1) / 2));
}

unsigned Ship::getConsumption(unsigned speed, unsigned distance) const {
   return getConsumption(speed, distance, getWeight());
}

std::ostream &Ship::toStream(ostream &os) const {
   if (!aka.empty())
      os << aka << " ";
   os << modelId;
   return os;
}

void Ship::setNickname(std::string name) {
   aka = std::move(name);
}

unsigned Ship::getMaxSpeed() const {
   return MAX_SPEED;
}

double Ship::getWeight() const {
   return WEIGHT;
}

std::string Ship::makeModelId(const string& model, unsigned int id) {
   return model + " #" + to_string(id);
}



