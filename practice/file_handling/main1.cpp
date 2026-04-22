

#include <iostream>
#include <ios>
#include <fstream>
#include <string>

using namespace std;


int main(){

    fstream file_var;

    file_var.open("main1.txt" , ios::out| ios::app);

    char str[30] = "hello this is input";
    file_var.write(str, sizeof(str));

    //////////

    ifstream file("main1.txt");

    string str2;

    getline(file, str2);

    cout<<"\nThe string is: "<<str2;


    
    return 0;
}