/*
Problem Statement: Student Record Management using File Handling (OOP Based)

Design a class Student with the following:

Data Members:
roll_no
name
marks
Member Functions:
getData()
→ Accept student details from user
displayData()
→ Display student details
writeToFile()
→ Write object data to a file
readFromFile()
→ Read and display all student records from file
File Handling Requirements:
Use binary file handling
Store data in file "student.dat"
Use:
fstream
write() and read() functions
Use file modes:
ios::in | ios::out | ios::binary
Additional Requirements:
Create at least 3 student objects
Store all objects in file
Read and display all records from file
*/

#include <iostream>

#include <fstream>

using namespace std;

class student{

    private:
        int roll_no;
        char name[20];
        int marks;

    public:

        void get_data(){
            cout << "\nEnter Name: ";cin >> name;
            cout << "Enter Roll No: ";cin >> roll_no;
            cout << "Enter Marks: "; cin >> marks;
        }

        void display_data(){
            cout << "\nName: " << name;
            cout << "\nRoll No: " << roll_no;
            cout << "\nMarks: " << marks << endl;
        }

        void write_to_file(){
            ofstream file("student.txt", ios::binary | ios::app);
            file.write((char*)this, sizeof(*this));
            file.close();
        }

        void read_from_file(){
            ifstream file("student.txt", ios::binary);
            student temp;

            while(file.read((char*)&temp, sizeof(temp))){
                temp.display_data();
            }

            file.close();
        }
};

int main(){

    student s;

    for(int i = 0; i < 3; i++){
        s.get_data();
        s.write_to_file();
    }

    cout << "\n...Records \n";

    s.read_from_file();

    return 0;
}