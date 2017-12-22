/**
** C++ STL MAP and multiMAP:
** Description, use and examples of C++ STL "pair", "map" and "multimap" associative containers.
** The STL associative container class is a variable sized container which supports retrieval of an element value given a search key.
** STL pair: A container which holds two values. The data types may or may not be different.
** STL map: Associative key-value pair held in balanced binary tree structure. Each key is unique.
** STL multimap: Same as an STL map except that duplicate keys are allowed.
**/
/**
#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;
int main()
{
   map <int, string> Employees;
   // 1) Assignment using array index notation
   Employees[5234] = "Mike C.";
   Employees[3374] = "Charlie M.";
   Employees[1923] = "David D.";
   Employees[7582] = "John A.";
   Employees[5328] = "Peter Q.";
   cout << "Employees[3374]=" << Employees[3374] << endl << endl;
   cout << "Map size: " << Employees.size() << endl;
   cout << endl << "Natural Order:" << endl;
   for( map<int,string>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii
   {
        cout << (*ii).first << ": " << (*ii).second << endl;
   }
    cout << endl << "Reverse Order:" << endl;
    for( map<int,string>::reverse_iterator ii=Employees.rbegin(); ii!=Employees.rend(); ++ii)
   {
        cout << (*ii).first << ": " << (*ii).second << endl;
   }
}
**/

/**
//Example using a "string" as an array index:
#include <string.h>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
    map<string, int> Employees;
    // Examples of assigning Map container contents
    // 1) Assignment using array index notation
    Employees["Mike C."] = 5234;
    Employees["Charlie M."] = 3374; // 2) Assignment using member function insert() and STL pair
    Employees.insert(std::pair<string,int>("David D.",1923));
    // 3) Assignment using member function insert() and "value_type()"
    Employees.insert(map<string,int>::value_type("John A.",7582));
    // 4) Assignment using member function insert() and "make_pair()"
    Employees.insert(std::make_pair("Peter Q.",5328));
    cout << "Map size: " << Employees.size() << endl;

    for( map<string, int>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii) {
        cout << (*ii).first << ": " << (*ii).second << endl;
}
}
**/

/**
#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;
struct cmp_str

{
   bool operator()(char const *a, char const *b)
   {
      return std::strcmp(a, b) < 0;
   }
};
int main()
{
   map<char *, int, cmp_str> Employees;
   // Examples of assigning Map container contents
   // 1) Assignment using array index notation
   Employees["Mike C."] = 5234;
   Employees["Charlie M."] = 3374;
   // 2) Assignment using member function insert() and STL pair
   Employees.insert(std::pair<char *,int>("David D.",1923));
   // 3) Assignment using member function insert() and "value_type()"
   Employees.insert(map<char *,int>::value_type("John A.",7582));
   // 4) Assignment using member function insert() and "make_pair()"
   Employees.insert(std::make_pair((char *)"Peter Q.",5328));
   cout << "Map size: " << Employees.size() << endl;
   for( map<char *, int, cmp_str>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)
   {
       cout << (*ii).first << ": " << (*ii).second << endl;
   }
}
**/

#include <iostream>
#include <map>
using namespace std;
class AAA
{
   friend ostream &operator<<(ostream &, const AAA &);
   public:
      int x;
      int y;
      float z;
      AAA();
      AAA(const AAA &);
      ~AAA(){};
      AAA &operator=(const AAA &rhs);
      int operator==(const AAA &rhs) const;
      int operator<(const AAA &rhs) const;
};
 
AA
A::AAA()   // Constructor
{
   x = 0;
   y = 0;
   z = 0;
}
AAA::AAA(const AAA &copyin)   // Copy constructor to handle pass by value.
{                            
   x = copyin.x;
   y = copyin.y;
   z = copyin.z;
}
ostream &operator<<(ostream &output, const AAA &aaa)
{
   output << aaa.x << ' ' << aaa.y << ' ' << aaa.z << endl;
   return output;
}
 
AAA& AAA::operator=(const AAA &rhs)
{
   this->x = rhs.x;
   this->y = rhs.y;
   this->z = rhs.z;
   return *this;
}
int AAA::operator==(const AAA &rhs) const
{
   if( this->x != rhs.x) return 0;
   if( this->y != rhs.y) return 0;
   if( this->z != rhs.z) return 0;
   return 1;
}

 
int AAA::operator<(const AAA &rhs) const
{
   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;
   if( this->x == rhs.x && this->y < rhs.y) return 1;
   if( this->x < rhs.x ) return 1;
   return 0;
}
 
main()
{
   map<string, AAA> M;
   AAA Ablob ;
   Ablob.x=7;
   Ablob.y=2;
   Ablob.z=4.2355;
   M["C"] = Ablob;
   Ablob.x=5;
   M["B"] = Ablob;
   Ablob.z=3.2355;
   M["A"] = Ablob;
   Ablob.x=3;
   Ablob.y=7;
   Ablob.z=7.2355;
   M["D"] = Ablob;
   for( map<string, AAA>::iterator ii=M.begin(); ii!=M.end(); ++ii)
   {
       cout << (*ii).first << ": " << (*ii).second << endl;
   }
   return 0;
}
