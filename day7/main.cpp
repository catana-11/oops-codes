/*
AIM: To use an STL vector container to store student grades and implement functions to
calculate the average, minimum, and maximum grades using iterators.
Problem Statement:
Utilize a vector container from the STL to store student grades. Implement functions to
calculate average, minimum, and maximum grades using iterators to access elements in the
vector.
*/


#include <iostream>
#include <vector>
using namespace std;


double calculate_avg(vector<int> &grades) {
    int sum = 0;

    for (vector<int>::iterator it = grades.begin(); it != grades.end(); it++) {
        sum += *it;
    }

    return sum / grades.size();
}


int find_min(vector<int> &grades) {
    int min = *grades.begin();

    for (vector<int>::iterator it = grades.begin(); it != grades.end(); it++) {
        if (*it < min) {
            min = *it;
        }
    }

    return min;
}


int find_max(vector<int> &grades) {
    int max = *grades.begin();

    for (vector<int>::iterator it = grades.begin(); it != grades.end(); it++) {
        if (*it > max) {
            max = *it;
        }
    }

    return max;
}

int main() {

    vector<int> grades;
    int n, value;

    cout << "Enter number of students: "; cin >> n;

   
    for (int i = 0; i < n; i++) {

        cout << "Enter grade " << i + 1 << ": ";
        cin >> value;
        grades.push_back(value);
    }

   
    cout << "\nAverage Grade: " << calculate_avg(grades) << endl;
    cout << "Minimum Grade: " << find_min(grades) << endl;
    cout << "Maximum Grade: " << find_max(grades) << endl;

    return 0;
}