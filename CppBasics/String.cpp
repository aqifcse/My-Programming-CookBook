/**
** This string is actually a one-dimensional array of characters which is terminated by a null character '\0'.
                char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
** or just      char greeting[] = "Hello";

**/
/**
#include <iostream>

using namespace std;

int main () {

   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

   cout << "Greeting message: ";
   cout << greeting << endl;

   return 0;
}
**/

/**

Function & Purpose
1
strcpy(s1, s2);
Copies string s2 into string s1.
2
strcat(s1, s2);
Concatenates string s2 onto the end of string s1.
3
strlen(s1);
Returns the length of string s1.
4
strcmp(s1, s2);
Returns 0 if s1 and s2 are the same; less than 0 if s1<s2; greater than 0 if s1>s2.
5
strchr(s1, ch);
Returns a pointer to the first occurrence of character ch in string s1.
6
strstr(s1, s2);
Returns a pointer to the first occurrence of string s2 in string s1.
**/
/**
#include <iostream>
#include <cstring>

using namespace std;

int main () {

   char str1[10] = "Hello";
   char str2[10] = "World";
   char str3[10];
   int  len ;

   // copy str1 into str3
   strcpy( str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;

   // concatenates str1 and str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;

   // total lenghth of str1 after concatenation
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;

   return 0;
}
**/

//The String Class in C++

#include <iostream>
#include <string>

using namespace std;

int main () {

   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;

   // total length of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;

   return 0;
}


