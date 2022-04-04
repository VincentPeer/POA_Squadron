//
// Created by Vincent on 31.03.2022.
//

#include "../headers/Squadron.h"

using namespace std;

// Constructors / Destructor ------------
Squadron::Squadron(std::string name)
   : name(std::move(name)), ships (new Link{nullptr, nullptr}), leader(nullptr){
}

Squadron::Squadron(const Squadron &squadron) : Squadron(squadron.name){
   copyList(squadron.ships);
}

Squadron::~Squadron() {
   // Delete links of the list of ships
   Link* l = ships;
   while (l->next != nullptr) {
      Link* tmp = l;
      l = l->next;
      delete tmp;
   }
}

// Add ----------------------------------
Squadron* Squadron::addDynamic(const Ship& ship) const{
   Squadron* newSquad = new Squadron(*this);
   newSquad->add(ship);
   return newSquad;
}

Squadron &Squadron::add(const Ship& ship) {
   ships->next = new Link{(Ship*) &ship, ships->next};
   return *this;
}

Squadron Squadron::operator+(const Ship &ship) const{
   Squadron squad(*this);
   squad.add(ship);
   return squad;
}

Squadron &Squadron::operator+=(const Ship &ship) {
   add(ship);
   return *this;
}

// Remove -------------------------------
Squadron *Squadron::removeDynamic(const Ship& ship) const {
   Squadron* newSquad = new Squadron(*this);
   newSquad->remove(ship);
   return newSquad;
}

Squadron &Squadron::remove(const Ship& ship) {
   Link* l = ships;
   while (l->next != nullptr) {
      if (l->next->ship == &ship) {
         l->next = l->next-> next;
         break;
      }
      l = l->next;
   }
   return *this;
}

Squadron Squadron::operator-(const Ship &ship) const{
   Squadron squad(*this);
   squad.remove(ship);
   return squad;
}

Squadron &Squadron::operator-=(const Ship &ship) {
   remove(ship);
   return *this;
}

// Get ----------------------------------
Ship &Squadron::get(size_t i) const {
   const Link* l = ships;
   for (size_t j = 0; j <= i; ++j) {
      if (l->next == nullptr)
         throw std::runtime_error("Argument out of range");
      l = l->next;
   }
   return *l->ship;
}

Ship &Squadron::operator[](size_t i) const {
   return get(i);
}

unsigned Squadron::getConsumption(unsigned int distance, unsigned int speed) const {
   if (speed > getMaxSpeed())
      throw invalid_argument("Speed exceeds squad max speed");
   unsigned consumed = 0;
   for (Link* l = ships; l->next != nullptr; l = l->next)
      consumed += l->next->ship->getConsumption(speed, distance);
   return consumed;
}

unsigned Squadron::getMaxSpeed() const {
   unsigned min = (unsigned) -1;
   for (Link* l = ships; l->next != nullptr; l = l->next) {
      unsigned shipSpeed = l->next->ship->getMaxSpeed();
      min = min > shipSpeed ? shipSpeed : min;
   }
   return min;
}

double Squadron::getTotalWeight() const {
   double weight = 0;
   for (Link* l = ships; l->next != nullptr; l = l->next)
      weight += l->next->ship->getTotalWeight();
   return weight;
}

// Set -----------------------------------
void Squadron::setLeader(const Ship& leader) {
   if (!isInList(&leader))
      add(leader);
   this->leader = (Ship*) &leader;
}

void Squadron::removeLeader() {
   if (leader != nullptr) {
      remove(*leader);
      leader = nullptr;
   }
}

// Other ---------------------------------
std::ostream &operator<<(ostream &os, const Squadron& squad) {
   os << "Squadron: " << squad.name << endl;
   os << " max speed: " << squad.getMaxSpeed() << " MLGT" << endl;
   os << " total Weight: " << squad.getTotalWeight() << " tons" << endl << endl;
   if (squad.leader != nullptr)
      os << "-- Leader:" << endl << *squad.leader << endl;
   os << "-- Members:" << endl;
   for (Squadron::Link* l = squad.ships; l->next != nullptr; l = l->next) {
      if (squad.leader != l->next->ship)
         os << *l->next->ship << endl;
   }
   return os;
}

Squadron& Squadron::operator=(const Squadron &squad) {
   copyList(squad.ships);
   name = squad.name;
   leader = squad.leader;
   return *this;
}

// Private ------------------------------
void Squadron::copyList(Link* list) {
   while (list->next != nullptr) {
      list = list->next;
      add(*list->ship);
   }
}

bool Squadron::isInList(const Ship *ship) {
   for (Squadron::Link* l = ships; l->next != nullptr; l = l->next) {
      if (ship == l->next->ship)
         return true;
   }
   return false;
}











