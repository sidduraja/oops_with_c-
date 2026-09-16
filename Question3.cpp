#include <iostream>
#include <string>

using namespace std;

class Patient {
    int patientId;
    string patientName;
    static int activePatients;

public:
    Patient(int id, string name) {
        patientId = id;
        patientName = name;
        activePatients++;
    }

    ~Patient() {
        activePatients--;
    }

    static void showActivePatients() {
        cout << "Active patients: " << activePatients << endl;
    }
};

int Patient::activePatients = 0;

int main() {
    Patient::showActivePatients();

    Patient p1(101, "Aman");
    Patient p2(102, "Rohan");
    Patient::showActivePatients();

    {
        Patient p3(103, "Priya");
        Patient::showActivePatients();
    } // p3 goes out of scope and is destroyed here

    Patient::showActivePatients();

    return 0;
}
