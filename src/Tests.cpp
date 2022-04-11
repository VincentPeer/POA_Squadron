//
// Created by dimde on 4/11/2022.
//

#include <TIE.h>
#include <TIEIN.h>
#include <Shuttle.h>
#include <Squadron.h>
#include <Destroyer.h>
#include <iostream>

using namespace  std;
int main() {
   const Shuttle S(10);
   TIE tie;
   TIEIN tieIn;
   Destroyer destroyer;
   Ship& ship = tie;

   Squadron squad("MySquad");
   cout << squad.getConsumption(1,1);
   cout << squad.getMaxSpeed();
   cout << squad.getTotalWeight();

   squad.add(S);
   squad += tie;
   squad -= S;
   Squadron* squad2 = squad.addDynamic(tieIn);

   Squadron* sqaud3 = squad.removeDynamic(tieIn);
   squad.remove(tieIn);

   // Methods
   cout << squad.getConsumption(1,1);
   cout << squad.getMaxSpeed();
   cout << squad.getTotalWeight();

   // delete non membre
   cout << squad.removeDynamic(tieIn);
   squad.remove(tieIn);

   cout << squad.get(0);
//   cout << squad.get(91); //out of range

   cout << squad[0];
//   cout << squad[91]; //out of range

   squad.setLeader(S);
   cout << squad.getLeader();
   // Set leader with already member ship
   squad.setLeader(S);
   squad.removeLeader();
}