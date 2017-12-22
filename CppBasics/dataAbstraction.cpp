/**
** Abstraction separates code into interface and implementation.
   So while designing your component, you must keep interface independent
   of the implementation so that if you change underlying implementation then interface would remain intact.
** In this case whatever programs are using these interfaces,
   they would not be impacted and would just need a recompilation with the latest implementation.
**/

#include <iostream>
using namespace std;

class Adder {
   public:
      // constructor
      Adder(int i = 0) {
         total = i;
      }

      // interface to outside world
      void addNum(int number) {
         total += number;
      }

      // interface to outside world
      int getTotal() {
         return total;
      };

   private:
      // hidden data from outside world
      int total;
};

int main() {
   Adder a;

   a.addNum(10);
   a.addNum(20);
   a.addNum(30);

   cout << "Total " << a.getTotal() <<endl;
   return 0;
}
