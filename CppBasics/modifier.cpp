/**
** A modifier is used to alter the meaning of the base type so that
   it more precisely fits the needs of various situations.
** The data type modifiers are listed here −
                   signed
                   unsigned
                   long
                   short
**Qualifier & Meaning
1
const
Objects of type const cannot be changed by your program during execution.
2
volatile
The modifier volatile tells the compiler that a variable's value may be changed
in ways not explicitly specified by the program.
3
restrict
A pointer qualified by restrict is initially the only means by which the
object it points to can be accessed. Only C99 adds a new type qualifier called restrict.

**/

#include <iostream>
using namespace std;

/* This program shows the difference between
   * signed and unsigned integers.
*/
int main() {
   short int i;           // a signed short integer
   short unsigned int j;  // an unsigned short integer

   j = 50000;

   i = j;
   cout << i << " " << j;

   return 0;
}
