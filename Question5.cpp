#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int employeeId;
    string name;
    double salary;

public:
    Employee() {
        employeeId = 0;
        name = "Unknown";
        salary = 0.0;
    }

    Employee(int id, string empName, double sal) {
        employeeId = id;
        name = empName;
        salary = sal;
    }

    Employee(const Employee& other) {
        employeeId = other.employeeId;
        name = other.name;
        salary = other.salary;
    }

    void display() const {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }

    void updateSalary(double newSalary) {
        salary = newSalary;
    }
};

int main() {
    const Employee emp1(101, "Aarav", 75000.0);

    emp1.display();

    Employee emp2 = emp1;

    emp2.display();

    emp2.updateSalary(82000.0);
    emp2.display();

    return 0;
}
