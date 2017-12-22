//goto keyword works like a loop

/**
But goto will not work a code like this
for(...) {
   for(...) {
      while(...) {
         if(...) goto stop;
         .
         .
         .
      }
   }
}
stop:
cout << "Error in program.\n";
**/

#include <iostream>
using namespace std;

int main () {
   // Local variable declaration:
   int a = 10;

   // do loop execution
   LOOP:do {
      if( a == 15) {
         // skip the iteration.
         a = a + 1;
         goto LOOP;
      }
      cout << "value of a: " << a << endl;
      a = a + 1;
   }
   while( a < 20 );

   return 0;
}
