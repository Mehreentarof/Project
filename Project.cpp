#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    string id;
    string father_name;
    string contact_number;
    string degree;
    vector<int> marks;
    double average_marks;

    Student(string name, string id, string father_name, string contact_number, string degree, vector<int> marks) {
        this->name = name;
        this->id = id;
        this->father_name = father_name;
        this->contact_number = contact_number;
        this->degree = degree;
        this->marks = marks;
        this->average_marks = 0;
        for (int mark : marks) {
            this->average_marks += mark;
        }
        this->average_marks /= marks.size();
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Father's Name: " << father_name << endl;
        cout << "Contact Number: " << contact_number << endl;
        cout << "Degree: " << degree << endl;
        cout << "Marks: ";
        for (int mark : marks) {
            cout << mark << " ";
        }
        cout << endl;
        cout << "Average Marks: " << average_marks << endl;
    }
};

vector<Student> students;

void add_student() {
    string name, id, father_name, contact_number, degree;
    vector<int> marks;

    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student ID: ";
    getline(cin, id);
    cout << "Enter father's name: ";
    getline(cin, father_name);
    cout << "Enter contact number: ";
    getline(cin, contact_number);
    cout << "Enter degree: ";
    getline(cin, degree);

    for (int i = 0; i < 5; i++) {
        int mark;
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> mark;
        marks.push_back(mark);
    }

    students.push_back(Student(name, id, father_name, contact_number, degree, marks));
    cout << "Student added successfully!" << endl;
}

void display_students() {
    if (students.empty()) {
        cout << "No students found." << endl;
    } else {
        for (Student student : students) {
            student.print();
            cout << endl;
        }
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}