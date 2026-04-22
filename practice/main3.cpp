/*
Problem 3: Shape Hierarchy with Constructor Overloading

Create a class hierarchy:

Base Class: Shape
Protected:
name
Public:
Constructor
Virtual function area()
Derived Classes:
Rectangle
Circle

Each should:

Use constructor overloading
Override area() function

Additional Requirements:

Maintain a static function to display number of shapes created
Use dynamic allocation of objects (Shape pointers)
Demonstrate runtime polymorphism
*/

#include <iostream>
#include <string>

using namespace std;

class Shape{

    protected:
        string name;

    public:
        
        Shape(){
            name = "meow";
            count++;
        }

        virtual float area() = 0;

        static int count;

        static void show_count(){
            cout << "\nTotal Shapes: " << count;
        }


};

int Shape::count = 0;

class Rectangle : public Shape{

    float l, b;

    public:

        Rectangle(){
            name = "rectangle";
            l = b = 0;
        }

        Rectangle(float length, float breadth){
            name = "rectangle";
            l = length;
            b = breadth;
        }

        float area(){
            return l * b;
        }
};

class Circle : public Shape{

    float r;

    public:

        Circle(){
            name = "circle";
            r = 0;
        }

        Circle(float r){
            this->r = r;

        }

        float area(){
            return r*3.14*r;
        }

};

int main(){

    Shape *s1 = new Rectangle(10,5);
  
    cout<<s1->area()<<"\n";

    Shape *s2 = new Circle(7);

    cout<<s2->area();


   Shape::show_count(); // static funcs can be called without object


    delete s1;
    delete s2;

    return 0;
}