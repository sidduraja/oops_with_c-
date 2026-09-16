#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    int accountNumber;
    string customerName;
    double balance;

public:
    BankAccount(int accNum, string name, double bal) {
        accountNumber = accNum;
        customerName = name;
        balance = bal;
    }

    friend void compareBalance(const BankAccount &b1, const BankAccount &b2);
};

void compareBalance(const BankAccount &b1, const BankAccount &b2) {
    if (b1.balance > b2.balance) {
        cout << b1.customerName << " has a higher balance (" << b1.balance << ")" << endl;
    } else if (b2.balance > b1.balance) {
        cout << b2.customerName << " has a higher balance (" << b2.balance << ")" << endl;
    } else {
        cout << "Both have the same balance: " << b1.balance << endl;
    }
}

int main() {
    BankAccount user1(101, "Rahul", 15000);
    BankAccount user2(102, "Sneha", 22000);

    compareBalance(user1, user2);

    return 0;
}
