#include <iostream>
#include <TIE.h>
#include <Shuttle.h>
#include <Squadron.h>

using namespace std;

int main() {
   TIE blackLeader;
   blackLeader.setNickname("Black leader");
   TIE blackTwo;
   Shuttle shuttle(23.4); // 23.4 tonnes de marchandises
   Squadron squad("Black Squadron");
   squad += blackLeader;
   squad += blackTwo;
   squad += shuttle;
   squad.setLeader(blackLeader);
   cout << squad << endl;

   cout << "test" << endl;
   return EXIT_SUCCESS;
}
