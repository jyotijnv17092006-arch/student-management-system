#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    Student(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }
};

vector<Student> students;

// Add student
void addStudent() {
    int id, age;
    string name;

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;

    students.push_back(Student(id, name, age));
    cout << "Student added successfully!\n";
}

// Display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }

    cout << "\nStudent List:\n";
    for (auto s : students) {
        cout << "ID: " << s.id
             << ", Name: " << s.name
             << ", Age: " << s.age << endl;
    }
}

// Search student by ID
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << "Student Found:\n";
            cout << "ID: " << s.id
                 << ", Name: " << s.name
                 << ", Age: " << s.age << endl;
            return;
        }
    }
    cout << "Student not found!\n";
}

// Delete student by ID
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}