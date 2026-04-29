#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Student;
void showGPA(Student s);

// Derived Class
class Student : public Person {
private:
    int id;
    float gpa;

public:
    void setStudent(int i, string n, int a, float g) {
        id = i;
        setPerson(n, a);
        gpa = g;
    }

    void displayStudent() {
        cout << "ID: " << id << ", ";
        displayPerson();
        cout << "GPA: " << gpa << endl;
    }

    int getID() {
        return id;
    }

  
    bool operator==(Student s) {
        return this->id == s.id;
    }

    friend void showGPA(Student s);
};

void showGPA(Student s) {
    cout << "Student GPA: " << s.gpa << endl;
}

class Course {
private:
    string courseName;

public:
    void setCourse(string name) {
        courseName = name;
    }

    void displayCourse() {
        cout << "Course: " << courseName << endl;
    }
};


int main() {
    Student students[100];  
    int count = 0;

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Show GPA\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name;
            float gpa;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter GPA: ";
            cin >> gpa;

            students[count].setStudent(id, name, age, gpa);
            count++;

            cout << "Student added!\n";
        }

        else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                students[i].displayStudent();
            }
        }

        else if (choice == 3) {
            int searchID;
            cout << "Enter ID to search: ";
            cin >> searchID;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i].getID() == searchID) {
                    students[i].displayStudent();
                    found = true;
                }
            }

            if (!found)
                cout << "Student not found!\n";
        }

        else if (choice == 4) {
            int index;
            cout << "Enter student index: ";
            cin >> index;

            if (index >= 0 && index < count) {
                showGPA(students[index]); 
            }
            else {
                cout << "Invalid index!\n";
            }
        }

    } while (choice != 5);

    return 0;
}
