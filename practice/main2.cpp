/*
Problem 2: Bank Account System with Friend Function

Create a class BankAccount:

Private:
account_number, balance
Public:
Constructor to initialize account
Function to deposit and withdraw money
Function to display balance

Now:

Create a friend function transferFunds(Account &a1, Account &a2, float amount)
Transfers money from a1 to a2
Should access private members directly

Extra Requirements:

Use default arguments in deposit/withdraw functions
Demonstrate call by reference
Show at least 2 objects interacting
*/

#include <iostream>

using namespace std;


class bank_account{

    private:
        int account_number; float balance;

    public:

        static int accs;

        bank_account(){
            account_number = accs;
            accs+=1;
            balance = 0;
        }

        void deposit(){
            float dep;
            cout<<"\nEnter the amount to deposit in bank: "; cin>>dep;
            balance +=dep;
            cout<<"\nMoney added";
        }

        void withdraw(){
            float wd;

            cout<<"\nEnter the amount to withdraw: "; cin>>wd;

            if (wd>balance)cout<<"Insufficient funds!";
            else{
                balance -= wd;
                cout<<"\nAmount has been withdrawn";
            }
        }

        void display(){
            cout<<"..."<<endl;
            cout<<"Account id: "<< account_number;
            cout<<"\nBalance: "<< balance;
            cout<<"\n...\n";
        }

        friend void transfer_funds(bank_account &a1, bank_account &a2);

};

void transfer_funds(bank_account &a1, bank_account &a2){
    float trans;
    cout<<"Enter the amount to transfer: "; cin>> trans;
            // from a1 to a2

    if (a1.balance<trans) cout<<"Insufficient";
    else{
    a1.balance -= trans;
    a2.balance += trans;
    }
 }

int bank_account::accs = 0;

int main(){

    bank_account a1, a2, a3;

    a1.deposit();
    a2.deposit();
    a3.deposit();

    a1.display();
    a2.display();
    a3.display();

    transfer_funds(a1, a2);
    cout<<"After transfers: ";
    a1.display();
    a2.display();

    return 0;
}