/*
AIM:
To develop a program that reads data (such as student information) from a text file, stores it in
objects using object-oriented programming concepts, and writes the data from objects back to a
text file.
Problem Statement:
Write a program that reads data (e.g., student information) from a text file and stores it in
objects.Implement functionality to write data from objects back to a text file.
*/


#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int marks;

    void display() {
        cout << id << " " << name << " " << marks << endl;
    }
};

int main() {

    ifstream infile("students.txt");

    if (!infile) {
        cout << "Error opening file.\n";
        return 1;
    }

    Student s[100];
    int count = 0;

    // reading data
    while (infile >> s[count].id >> s[count].name >> s[count].marks) {
        count++;
    }

    infile.close();

    cout << "Students read from file:\n";
    for (int i = 0; i < count; i++) {

        s[i].display();
    }

    //writing data
    ofstream outfile("output.txt");

    if (outfile.is_open()) {
        for (int i = 0; i < count; i++) {
            outfile << s[i].id << " "
                    << s[i].name << " "
                    << s[i].marks << endl;
        }
        outfile.close();
    } else {
        cout << "Error opening output file.\n";
        return 1;
    }

    cout << "Data written to output.txt\n";

    return 0;
}