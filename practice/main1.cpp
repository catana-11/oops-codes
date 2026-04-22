/*
Problem 1: Student Result Management System

Design a class Student with the following:

Private members:
student_id, name
dynamically allocated array of marks (for N subjects)
Public members:
Parameterized constructor to initialize student details and allocate memory
Copy constructor to copy one student object to another
Destructor to deallocate memory
Function to calculate average marks
Function to display student details

Additional Requirements:

Use dynamic memory allocation (new / delete)
Maintain a static variable to count total number of students created
Use a reference parameter function to swap marks of two students
*/

#include <iostream>
#include <string>

using namespace std;

class Student{

    private:
        int student_id; string name;
        int sub_count;
        int *marks;
    
    public:

        static int stcount;

    
        Student(int id, string stname, int n){

            student_id = id;
            name = stname;
            sub_count = n;
            marks = new int[n];
            for(int i= 0; i<n; i++){
                cout<<"\nEnter marks of sub"<<i<<": "; cin>>marks[i];
            }
            stcount+=1;

        }

        Student(Student& s2){
            student_id = s2.student_id;
            name = s2.name;
            sub_count = s2.sub_count;

            marks = new int[sub_count];
            for(int i = 0; i < sub_count; i++){
                marks[i] = s2.marks[i];
            }

            stcount += 1;
        } // deep copy

        /*
        Student(Student& s2){
            student_id = s2.student_id;
            name = s2.name;
            sub_count = s2.sub_count;
            marks = s2.marks;   // SHALLOW COPY
        }*/

        ~Student(){
            cout<<"\ndestructor called";
            delete []marks;
            stcount-=1;
        }

        float avg_marks(){
            int sum = 0;
            for (int i =0; i<sub_count; i++){
                sum+=marks[i];
            }

            return (float)sum/sub_count;

        }

        void display(){

            cout<<"..."<<endl;
            cout<<"\nName: "<<name;
            cout<<"\nID: "<<student_id;
            cout<<"\nMarks in "<<sub_count<<" subjects: "<<endl<<"[";

            for(int i=0; i<sub_count; i++) cout<<marks[i]<<" ";

            cout<<"]"<<endl;
            cout<<"...";

        }

        void swap_marks(Student &s){

            int *temp = marks;
            marks = s.marks;
            s.marks = temp; 

            int c = sub_count;
            sub_count = s.sub_count;
            s.sub_count = c;

        }

};

int Student::stcount = 0;



int main(){

    Student s1(1, "ABC", 5);
    Student s2(2, "MEow", 6);
    Student s3(s1);

    s1.display();
    s2.display();
    s3.display();

    cout<<"\nAvg marks of s1: "<<s1.avg_marks()<<endl;
    cout<<"Avg marks of s2: "<<s2.avg_marks()<<endl;
    cout<<"Avg marks of s3: "<<s3.avg_marks()<<endl;

    s1.swap_marks(s2);

    s1.display(); s2.display();


    return 0;
}