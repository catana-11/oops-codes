
#include <iostream>
using namespace std;

class circle {
    double radius;

public:
    // default 
    circle() {
        radius = 1;
        cout << "default circle constructor called\n";
    }

    // parametrized 
    circle(double r) {
        radius = r;
        cout << "parametrized circle constructor called\n";
    }

    // copy 
    circle(circle &c) {
        radius = c.radius;
        cout << "copy circle constructor called\n";
    }

    double area() {
        return 3.14 * radius * radius;
    }

    double perimeter() {
        return 2 * 3.14 * radius;
    }

    // destructor
    ~circle() {
        cout << "circle destructor called\n";
    }
};

class rectangle {
    double length, width;

public:
    rectangle() {
        length = 1;
        width = 1;
        cout << "default rect constructor called\n";
    }

    rectangle(double l, double w) {
        length = l;
        width = w;
        cout << "parametrized rect constructor called\n";
    }

    rectangle(rectangle &r) {
        length = r.length;
        width = r.width;
        cout << "copy rect constructor called\n";
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }

    // destructor
    ~rectangle() {
        cout << "rectangle destructor called\n";
    }
};

int main() {

    circle c1;
    circle c2(5);
    circle c3(c2);

    cout << "area of c2: " << c2.area() << endl;
    cout << "perimeter of c2: " << c2.perimeter() << endl;

 
    rectangle r1;
    rectangle r2(4, 6);
    rectangle r3(r2);

    cout << "area of r2: " << r2.area() << endl;
    cout << "perimeter of r2: " << r2.perimeter() << endl;

    return 0;
}
