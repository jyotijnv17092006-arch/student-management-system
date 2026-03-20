#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    Student() {}

    Student(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }
};

vector<Student> students;

// Load data from file
void loadFromFile() {
    ifstream file("students.txt");
    if (!file) return;

    Student s;
    while (file >> s.id >> s.name >> s.age) {
        students.push_back(s);
    }
    file.close();
}

// Save data to file
void saveToFile() {
    ofstream file("students.txt");
    for (auto s : students) {
        file << s.id << " " << s.name << " " << s.age << endl;
    }
    file.close();
}

// Add student
void addStudent() {
    int id, age;
    string name;

    cout << "\nEnter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;

    students.push_back(Student(id, name, age));
    saveToFile();

    cout << "✅ Student added successfully!\n";
}

// Display all students
void displayStudents() {
    if (students.empty()) {
        cout << "\n⚠ No students found!\n";
        return;
    }

    cout << "\n===== Student List =====\n";
    for (auto s : students) {
        cout << "ID: " << s.id
             << " | Name: " << s.name
             << " | Age: " << s.age << endl;
    }
}

// Search student
void searchStudent() {
    int id;
    cout << "\nEnter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << "✅ Found: "
                 << s.name << ", Age: " << s.age << endl;
            return;
        }
    }
    cout << "❌ Student not found!\n";
}

// Update student
void updateStudent() {
    int id;
    cout << "\nEnter ID to update: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin >> s.name;
            cout << "Enter new age: ";
            cin >> s.age;

            saveToFile();
            cout << "✅ Student updated!\n";
            return;
        }
    }
    cout << "❌ Student not found!\n";
}

// Delete student
void deleteStudent() {
    int id;
    cout << "\nEnter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            saveToFile();

            cout << "✅ Student deleted!\n";
            return;
        }
    }
    cout << "❌ Student not found!\n";
}

// Menu UI
void menu() {
    cout << "\n==============================\n";
    cout << "   STUDENT MANAGEMENT SYSTEM  \n";
    cout << "==============================\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "==============================\n";
    cout << "Enter choice: ";
}

int main() {
    loadFromFile();

    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "👋 Exiting...\n"; break;
            default: cout << "❌ Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}