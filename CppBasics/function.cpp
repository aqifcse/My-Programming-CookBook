/**
//function returning the max between two numbers

int max(int num1, int num2) {
   // local variable declaration
   int result;

   if (num1 > num2)
      result = num1;
   else
      result = num2;

   return result;
}
**/

/**
#include <iostream>
using namespace std;

// function declaration
int max(int num1, int num2);

int main () {
   // local variable declaration:
   int a = 100;
   int b = 200;
   int ret;

   // calling a function to get max value.
   ret = max(a, b);
   cout << "Max value is : " << ret << endl;

   return 0;
}

// function returning the max between two numbers
int max(int num1, int num2) {
   // local variable declaration
   int result;

   if (num1 > num2)
      result = num1;
   else
      result = num2;

   return result;
}
**/

/**
Call Type & Description
1
Call by Value
This method copies the actual value of an argument into the formal parameter of the function.
In this case, changes made to the parameter inside the function have no effect on the argument.
2
Call by Pointer
This method copies the address of an argument into the formal parameter.
Inside the function, the address is used to access the actual argument used in the call.
This means that changes made to the parameter affect the argument.
3
Call by Reference
This method copies the reference of an argument into the formal parameter.
Inside the function, the reference is used to access the actual argument used in the call.
This means that changes made to the parameter affect the argument.
**/

#include <iostream>
using namespace std;

int sum(int a, int b = 20) {
   int result;
   result = a + b;

   return (result);
}
int main () {
   // local variable declaration:
   int a = 100;
   int b = 200;
   int result;

   // calling a function to add the values.
   result = sum(a, b);
   cout << "Total value is :" << result << endl;

   // calling a function again as follows.
   result = sum(a);
   cout << "Total value is :" << result << endl;

   return 0;
}
