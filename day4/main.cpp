/*Create functions for arithmetic operations like addition, subtraction and multiplication
that work with both integers and user-defined classes (e.g., Point with X and Y coordinates) demonstrating function
overloading.
 */

#include <iostream>

using namespace std;


class Point {
public:
    int x, y;

    //const
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }


    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }

  
    Point operator-(const Point& p) {
        return Point(x - p.x, y - p.y);
    }


    Point operator*(const Point& p) {
        return Point(x * p.x, y * p.y);
    }
};

// int wale fns

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

// point wale fns for overloading

Point add(Point p1, Point p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point sub(Point p1, Point p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}

Point mul(Point p1, Point p2) {
    return Point(p1.x * p2.x, p1.y * p2.y);
}

void display(Point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}


int main() {

    int a = 10, b = 5;

    cout << "integer operations:\n";
    cout << "add: " << add(a, b) << endl;
    cout << "sub: " << sub(a, b) << endl;
    cout << "mul: " << mul(a, b) << endl;

    Point p1(3, 4);
    Point p2(1, 2);

    cout << "\npoint operations using function overloading:\n";
    cout << "add: ";
    display(add(p1, p2));

    cout << "sub: ";
    display(sub(p1, p2));

    cout << "mul: ";
    display(mul(p1, p2));

    cout << "\npoint operations using operator overloading:\n";

    cout << "add: ";
    display(p1 + p2);

    cout << "sub: ";
    display(p1 - p2);

    cout << "mul: ";
    display(p1 * p2);

    return 0;
}