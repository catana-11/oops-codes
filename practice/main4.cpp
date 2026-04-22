#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n = "", int i = 0) {
        name = n;
        id = i;
        cout << "\nEmployee Constructor";
    }

    virtual float calc_salary() = 0;

    virtual void display() {
        cout << "\nName: " << name << " | ID: " << id;
    }

    virtual ~Employee() {
        cout << "\nEmployee Destructor";
    }
};

class Commission {
protected:
    float sales, rate;

public:
    Commission(float s = 0, float r = 0) {
        sales = s;
        rate = r;
    }

    float get_commission() {
        return sales * rate;
    }
};

class SalariedEmployee : virtual public Employee {

protected:
    float weekly_salary;

public:
    SalariedEmployee(string n, int i, float w)
        : Employee(n, i), weekly_salary(w) {
        cout << "\nSalariedEmployee Constructor";
    }

    float calc_salary() {
        return weekly_salary * 4;
    }

    void display() {
        Employee::display();
        cout << " | Type: Salaried | Weekly: " << weekly_salary;
    }

   
    friend void increase_sal(SalariedEmployee &e, float inc);

    ~SalariedEmployee() {
        cout << "\nSalariedEmployee Destructor";
    }
};

class SalesEmployee : virtual public Employee, public Commission {

protected:
    float base_salary;

public:
    SalesEmployee(string n, int i, float base, float s, float r)
        : Employee(n, i), Commission(s, r), base_salary(base) {
        cout << "\nSalesEmployee Constructor";
    }

    float calc_salary() {
        return base_salary + get_commission();
    }

    void display() {
        Employee::display();
        cout << " | Type: Sales | Base: " << base_salary;
    }

    ~SalesEmployee() {
        cout << "\nSalesEmployee Destructor";
    }
};

class Manager : public SalariedEmployee {

    float bonus;

public:
    Manager(string n, int i, float w, float b)
        : SalariedEmployee(n, i, w), bonus(b) {
        cout << "\nManager Constructor";
    }

    float calc_salary() {
        return weekly_salary * 4 + bonus;
    }

    void display() {
        Employee::display();
        cout << " | Type: Manager | Bonus: " << bonus;
    }

    ~Manager() {
        cout << "\nManager Destructor";
    }
};

float calculate_bonus(float salary) {
    return salary * 0.1;
}

float calculate_bonus(float salary, float extra) {
    return salary * 0.1 + extra;
}

class Salary {
public:
    float amount;

    Salary(float a = 0) {
        amount = a;
    }

    Salary operator+(Salary s) {
        return Salary(amount + s.amount);
    }

    void display() {
        cout << "\nCombined Salary: " << amount;
    }
};

void increase_sal(SalariedEmployee &e, float inc) {
    e.weekly_salary += inc;   
    cout << "\nSalary increased by " << inc;
}

int main() {

    Employee* e1 = new SalariedEmployee("Alice", 1, 5000);
    Employee* e2 = new SalesEmployee("Bob", 2, 3000, 10000, 0.1);
    Employee* e3 = new Manager("Charlie", 3, 6000, 2000);

    cout << "\n\n--- Employee Details ---";
    e1->display();
    cout << "\nSalary: " << e1->calc_salary();

    e2->display();
    cout << "\nSalary: " << e2->calc_salary();

    e3->display();
    cout << "\nSalary: " << e3->calc_salary();

    cout << "\n\nBonus: " << calculate_bonus(e1->calc_salary());
    cout << "\nBonus with extra: " << calculate_bonus(e1->calc_salary(), 500);


    Salary s1(e1->calc_salary());
    Salary s2(e2->calc_salary());
    Salary total = s1 + s2;
    total.display();

    SalariedEmployee* se = dynamic_cast<SalariedEmployee*>(e1);
    if(se) increase_sal(*se, 1000);
    
    cout << "\nUpdated Salary (Alice): " << e1->calc_salary();

    delete e1;
    delete e2;
    delete e3;

    return 0;
}