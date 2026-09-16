#include <iostream>
#include <string>

using namespace std;

class ResultAnalyzer;

class StudentResult {
    int rollNo;
    string name;
    float marks[3];
    static int totalStudents;

public:
    StudentResult(int r, string n, float m1, float m2, float m3) {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        totalStudents++;
    }

    ~StudentResult() {
        cout << "Record for " << name << " cleared from memory." << endl;
    }

    static void showTotal() {
        cout << "Total students enrolled: " << totalStudents << endl;
    }

    friend class ResultAnalyzer;
};

int StudentResult::totalStudents = 0;

class ResultAnalyzer {
public:
    void printReport(const StudentResult& s) {
        float total = s.marks[0] + s.marks[1] + s.marks[2];
        float percentage = (total / 300.0f) * 100;

        cout << "Roll: " << s.rollNo << " | Name: " << s.name << endl;
        cout << "Total: " << total << "/300 | Percentage: " << percentage << "%" << endl;

        if (s.marks[0] >= 40 && s.marks[1] >= 40 && s.marks[2] >= 40) {
            cout << "Status: Passed" << endl;
        } else {
            cout << "Status: Failed" << endl;
        }
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    StudentResult::showTotal();

    StudentResult s1(1, "Rohan Sharma", 78, 82, 69);
    StudentResult s2(2, "Ananya Verma", 34, 75, 80);

    StudentResult::showTotal();

    ResultAnalyzer report;
    report.printReport(s1);
    report.printReport(s2);

    return 0;
}
