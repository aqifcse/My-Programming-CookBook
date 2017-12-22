/*<iostream>
This file defines the cin, cout, cerr and clog objects, which correspond to
the standard input stream, the standard output stream, the un-buffered standard error
stream and the buffered standard error stream, respectively.*/

/*
#include <iostream>

using namespace std;

int main() {
   char str[] = "Hello C++";

   cout << "Value of str is : " << str << endl;
}
*/

/*
#include <iostream>

using namespace std;

int main() {
   char name[50];
   char age[50];

   cout << "Please enter your name & age: ";
   cin >> name >> age;
   cout << "Your name is: " << name << " " << age << endl;

}
*/

/*The Standard Error Stream (cerr)
The predefined object cerr is an instance of ostream class.
 The cerr object is said to be attached to the standard error device,
which is also a display screen but the object cerr is un-buffered and each stream insertion to
cerr causes its output to appear immediately.
The cerr is also used in conjunction with the stream insertion operator as shown in the following example.
*/

/*
#include <iostream>

using namespace std;

int main() {
   char str[] = "Unable to read....";

   cerr << "Error message : " << str << endl;
}
*/

/*
The Standard Log Stream (clog)
The predefined object clog is an instance of ostream class. The clog object is said to be attached to
the standard error device, which is also a display screen but the object clog is buffered. This means that
each insertion to clog could cause its output to be held in a buffer until the buffer is filled or until
the buffer is flushed.
The clog is also used in conjunction with the stream insertion operator as shown in the following example.
*/

#include <iostream>

using namespace std;

int main() {
   char str[] = "Unable to read....";

   clog << "Error message : " << str << endl;
}

