//
// Created by Vincent on 31.03.2022.
//

#ifndef LABO02_SQUADRON_H
#define LABO02_SQUADRON_H

#include <string>
#include <ostream>
#include "ships/Ship.h"

/**
 * This class represents a squad of ships
 */
class Squadron {
   // Quick structure to store ships in a linked list
   struct Link {
      Ship *ship;
      Link *next;
   };

   std::string name;
   Link* ships; // Before first
   Ship* leader;

   /**
    * Copy an other list of ships to this squad's list
    * @param list list of ships
    */
   void copyList(Link* list);

   /**
    * Checks if a ship is in the list of ships
    * @param ship The ship to check
    * @return True if the ship is in the list of ships
    */
   bool isInList(const Ship* ship);

public:

   /**
    * Constructor with naming
    * @param name name of the squadron
    */
    Squadron(std::string  name);

    /**
     * Copy constructor
     * @param squadron Squad to copy from
     */
    Squadron(const Squadron& squadron);

    /**
     * Destructor (destructing dynamic variables)
     */
    ~Squadron();

    /**
     * Create a new squadron dynamically and add a ship to it
     * @param ship to add
     * @return The dynamically created Squadron
     */
    Squadron* addDynamic(const Ship& ship) const;

    /**
     * Add a ship to the squadron
     * @param ship The ship to add
     * @return *this
     */
    Squadron& add(const Ship& ship);

    /**
     * Create a new squadron dynamically and remove a ship from it
     * @param ship to remove
     * @return The dynamically created Squadron
     */
    Squadron* removeDynamic(const Ship& ship) const;

    /**
     * Remove a ship to the squadron
     * @param ship to remove
     * @return *this
     */
    Squadron& remove(const Ship& ship);

    /**
     * Get the nth ship in our squadron
     * @param n the ship number to return
     * @return reference to a ship
     */
     Ship& get(size_t n) const; // todo get sans const?

    /**
     * Set a new squad leader
     * @param leader
     */
    void setLeader(const Ship& leader);

    /**
     * Remove the squad leader
     */
    void removeLeader();

    /**
     * Calculate the fuel consomption for a given distance and speed
     * @param distance
     * @param speed
     * @return fuel consomption in tons
     */
    unsigned getConsumption(unsigned distance, unsigned speed) const;

    /**
     * Get the max speed at witch the squad can go
     * (max speed of slowest ship in squad)
     * @return max speed in MGLT
     */
    unsigned getMaxSpeed() const;

    /**
     * Get total weight of the squadron
     * @return weight in tons
     */
    double getTotalWeight() const;

   /**
    * Add a ship to the squadron
    * @param ship The ship to add
    * @return Copy of the squad
    */
    Squadron operator+(const Ship& ship) const;

   /**
     * Add a ship to the squadron
     * @param ship The ship to add
     * @return *this
     */
    Squadron& operator+=(const Ship& ship);

   /**
    * Remove a ship to the squadron
    * @param ship The ship to add
    * @return Copy of the squad
    */
    Squadron operator-(const Ship& ship) const;

   /**
    * Remove a ship to the squadron
    * @param ship The ship to add
    * @return *this
    */
    Squadron& operator-=(const Ship& ship);

    /**
     * Assign the data of a squadron to this one
     * @param squad the data to assign from
     * @return *this
     */
    Squadron& operator=(const Squadron& squad);

   /**
     * Get the nth ship in our squadron
     * @param n the ship number to return
     * @return reference to a ship
     */
    Ship& operator[](size_t n) const;

    friend std::ostream& operator<<(std::ostream& os,const Squadron& squad);
};


#endif //LABO02_SQUADRON_H
