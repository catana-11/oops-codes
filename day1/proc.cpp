// procedural method: normal functions

#include <iostream>
#include <cmath>

using namespace std;

double square_area(double s) {
    return s*s;
}

double rectangle_area(double l, double b) {
    return l*b;
}

double triangle_area(double b, double h) {
    return 0.5 * b*h;
}

double circle_area(double rad) {
    return M_PI * rad*rad;
}

double sphere_area(double r) {
    return 4*M_PI*r*r;
}

double cylinder_area(double r, double h) {
    return 2 * M_PI * r * (r+h);
}


int main() {

    int choice;
    double a, b;

    do {
        cout << "\n...menu...\n";
        cout << "1. square\n2. rectangle\n3. triangle\n4. circle\n5. sphere\n6. cylinder\n0. exit\n";

        cout << "enter your choice: "; cin >> choice;

        switch (choice) {

            case 1:
                cout << "enter side: "; cin >> a;
                cout << "area of square: " << square_area(a) << endl;
                break;

            case 2:
                cout << "enter length and breadth: ";  cin >> a >> b;
                cout << "area of rectangle: " << rectangle_area(a, b) << endl;
                break;

            case 3:
                cout << "enter base and height: "; cin >> a >> b;
                cout << "area of triangle: " << triangle_area(a, b) << endl;
                break;

            case 4:
                cout << "enter radius: "; cin >> a;
                cout << "area of circle: " << circle_area(a) << endl;
                break;

            case 5:
                cout << "enter radius: "; cin >> a;
                cout << "surface area of sphere: " << sphere_area(a) << endl;
                break;

            case 6:
                cout << "enter radius and height: ";  cin >> a >> b;
                cout << "surface ar of cylinder: " << cylinder_area(a, b) << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}


