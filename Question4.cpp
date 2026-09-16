#include <iostream>
#include <string>

using namespace std;

class University {
private:
    string universityName;

public:
    University(string uname) : universityName(uname) {}

    class Department {
    private:
        string departmentName;
        int studentCount;

    public:
        Department(string dname, int count) : departmentName(dname), studentCount(count) {}

        void display(const University& u) const {
            cout << "University Name: " << u.universityName << endl;
            cout << "Department Name: " << departmentName << endl;
            cout << "Student Count:   " << studentCount << endl;
        }
    };
};

int main() {
    University uni("Stanford University");
    
    University::Department dept("Computer Science", 450);

    dept.display(uni);

    return 0;
}
