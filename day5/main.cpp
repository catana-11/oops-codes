/*Problem Statement: 
Develop a base Shape class with a virtual function for drawing. 
Create derived classes for Circle and Rectangle that override the draw function. 
Write a program that uses polymorphism to call the appropriate draw function for different shapes.
*/


#include <iostream>
using namespace std;

// abstract base class

class Shape {

    public:

        // pure virtual fn
        virtual void draw(){ // if i remove virtual here, program will print hehe thrice
            // because the compiler just looked at the pointer of base class and executed that
            // if "virtual" was there, it would wait and decide on runtime that which derived class should it execute
            cout<<"hehe";
        };

        //virtual void draw() = 0;

        // this is not pure virtual
        // pure virtual would be: virtual void draw() = 0

        // there can be multiple virtual functions in a class
        // class remains abstract even if one of them is a proper function, as long as there is atleast one virtual function
};

// derived cls: circle
class Circle : public Shape {

    public:

        void draw() {
            cout << "Drawing Circle" << endl;
        }
};

// derived cls: rect
class Rectangle : public Shape {

    public:

        void draw() {

            cout << "Drawing Rectangle" << endl;
        }
};


int main() {

  
    Circle c;
    Rectangle r;

    // base class ptrs
    Shape* s1;
    Shape* s2;
    Shape* s3;

    // assigning derived objs to base ptrs
    s1 = &c;
    s2 = &r;

    // runtime polymorphism
    s1->draw();   // circle draw()
    s2->draw();   // rectangle draw()
    s3->draw(); // nothing prints

    return 0;
}