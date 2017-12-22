/*********************************************************************************************
**Inheritance allows us to define a class in terms of another class, which makes it easier to
create and maintain an application.
**This also provides an opportunity to reuse the code
functionality and fast implementation time
**This existing class is called the base class, and the new class is referred to as the derived class.
**  class derived-class: access-specifier base-class
**********************************************************************************************/

//Consider a base class Shape and its derived class Rectangle as follows
#include <iostream>

using namespace std;

// Base class
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }

   protected:
      int width;
      int height;
};

// Derived class
class Rectangle: public Shape {
   public:
      int getArea() {
         return (width * height);
      }
};

int main(void) {
   Rectangle Rect;

   Rect.setWidth(5);
   Rect.setHeight(7);

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}
