#include <iostream>
using namespace std;

int add ( int x, int y ) {

   int sum = x + y;

    return sum;
}
// main() is where program execution begins.
int main() {
   cout << "Hello World"; // prints Hello World

   int a = 10;
   int b = 15;

   cout << " " << add( a, b ) << endl;
   return 0;
}


