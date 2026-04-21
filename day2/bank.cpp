

//design a class to represent a bank account with attributes (balance, account no)
// and methods (deposit, withdraw) with proper access control (public, private, protected) to demonstrate encapsulation

#include <iostream>
using namespace std;
class BankAccount {
private:
    int accNo;
    double balance;
    string name;

public:
    static int count;

    // Constructor
    BankAccount() {
        count++;
    }

    // Destructor
    ~BankAccount() {
        count--;
    }
};

int BankAccount::count = 0;
class bank {

    private:

        int acc_no;
        double balance;
        string name;

    protected:

        void update_bal(double amount) {
            balance += amount;
        }

    public:

        static int count;

        bank() {
            count++; cout<<"\ntotal count of accounts is "<<count<<endl;
        }

        void create_acc() {

            cout << "Enter account owner name: "; cin >> name;

            cout << "Enter account number: ";  cin >> acc_no;

            cout << "Enter initial balance: "; cin >> balance;

            if (balance < 0)     balance = 0;

            count++;
        }

        void deposit() {

            double amount;

            cout << "Enter amount to deposit: ";   cin >> amount;

            if (amount > 0) {

                update_bal(amount);
                cout << "Updated Balance: " << balance << endl;
            } 
            else  cout << "Invalid amount.\n";

        }

        void withdraw() {

            double amount;
            cout << "Enter amount to withdraw: "; cin >> amount;

            if (amount > 0 && amount <= balance) {

                update_bal(-amount);
                cout << "Updated Balance: " << balance << endl;
            } 
            else cout << "Invalid withdrawal.\n";
        }

        void show() {
            cout<<"................."<<endl;
            cout << "\nName: " << name;
            cout << "\nAccount No: " << acc_no;
            cout << "\nBalance: " << balance << endl;
            cout<<"................."<<endl;
        }

        ~bank() {
        count--; cout<<count<<" ";
        }
};

int bank::count = 0;

int main() {

    bank acc[20];
    int choice, id, n;

    cout<<"How many accounts?: "; cin>>n;

    for (int i = 0; i < n; i++) {

        cout << "\nCreate Account " << i << endl;
        acc[i].create_acc();
    }

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Details\n4. Exit\n";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {

            cout << "Enter account index (0-19): ";
            cin >> id;

        }

        switch (choice) {
            case 1: acc[id].deposit(); break;
            case 2: acc[id].withdraw(); break;
            case 3: acc[id].show(); break;
        }

    } while (choice != 4);

    return 0;
}