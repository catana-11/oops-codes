// using class methods

#include <iostream>
using namespace std;

class Area {

public:

    float square() {
        float a;
        cout << "\nEnter the side of square: "; cin >> a;
        return a *a;
    }

    float circle() {
        float r;
        cout << "\nEnter radius of circle: "; cin >> r;
        return 3.14* r* r;
    }

    float rect() {
        float l, b;
        cout << "\nEnter length: "; cin >> l;
        cout << "\nEnter breadth: ";  cin >> b;
        return l*b;
    }

    float triangle() {

        float base, height;
        cout << "\nEnter base: ";  cin >> base;
        cout << "\nEnter height: ";  cin >> height;
        return 0.5* base *height;
    }

    float sphere() {
        float r;
        cout << "\nEnter radius: ";    cin >> r;
        return 4*3.14* r *r;
    }

    float cylinder() {
        float r, h;
        cout << "\nEnter radius: ";   cin >> r;
        cout << "\nEnter height: ";    cin >> h;
        return (2 *3.14 *r *h) +(2*3.14* r*r);
    }
};

int main() {

    Area obj;

    int cont = 1, choice = 0;
    float temp = 0;

    while (cont == 1) {

        cout << "\nMenu:";
        cout << "\n1. Square";
        cout << "\n2. Circle";
        cout << "\n3. Rectangle";
        cout << "\n4. Triangle";
        cout << "\n5. Sphere";
        cout << "\n6. Cylinder";

        cout << "\nEnter choice: ";   cin >> choice;

        switch (choice) {

            case 1:
                temp = obj.square();
                cout << "Area is: " << temp;
                break;

            case 2:
                temp = obj.circle();
                cout << "Area is: " << temp;
                break;

            case 3:
                temp = obj.rect();
                cout << "Area is: " << temp;
                break;

            case 4:
                temp = obj.triangle();
                cout << "Area is: " << temp;
                break;

            case 5:
                temp = obj.sphere();
                cout << "Area is: " << temp;
                break;

            case 6:
                temp = obj.cylinder();
                cout << "Area is: " << temp;
                break;

            default:
                cout << "Invalid choice!";
        }

        cout << "\nWant to continue? Enter 1: ";
        cin >> cont;
    }

    return 0;
}
