#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

struct Student 
{
    string Name;
    string Id;
    string Fathername;
    string Contactnumber;
    string Degree;
    string Department;
    string semester;
    float Results[5];
    float Average;
};

void SaveFile(const Student &student); 

void AddStudent() 
{
    Student student;
    cin.ignore(); 
    cout << "Enter Student Name: ";
    getline(cin, student.Name);
    cout << "Enter Student ID: ";
    getline(cin, student.Id);
    cout << "Enter Father's Name: ";
    getline(cin, student.Fathername);
    cout << "Enter Contact Number: ";
    getline(cin, student.Contactnumber);
    cout << "Enter Degree Program: ";
    getline(cin, student.Degree);
    cout<<"Enter department:";
    getline(cin,student.Department);
    cout<<"Enter semester:";
    getline(cin,student.semester);
    cout << "Enter Marks for 5 Subjects:\n";
    float total = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "Subject " << (i + 1) << ": ";
        cin >> student.Results[i];
        total += student.Results[i];
    }
    student.Average = total / 5; 

    SaveFile(student); 
    cout << "Student information saved successfully!\n";
}

void SaveFile(const Student &student) 
{
    ofstream outFile("student_data.txt", ios::app | ios::out); 
    if (outFile.is_open())
    {
        outFile << "Student Details \n";
        outFile << "Name: " << student.Name << "\n";
        outFile << "ID: " << student.Id << "\n";
        outFile << "Father's Name: " << student.Fathername << "\n";
        outFile << "Contact Number: " << student.Contactnumber << "\n";
        outFile << "Degree Program: " << student.Degree << "\n";
        outFile <<"Department:"<<student.Department<<"\n";
        outFile <<"semester:"<<student.semester<<"\n";
        outFile << "Marks: ";
        for (int i = 0; i < 5; i++)
        {
            outFile << student.Results[i] << " ";
        }
        outFile << "\n";
        outFile << "Average Marks: " << student.Average << "\n";
        outFile.close();
    }
    else
    {
        cout << "Error opening file for writing!\n";
    }
}

void DisplayStudentsData()
{
    ifstream inFile("student_data.txt"); 
    if (inFile.is_open())
    {
        string line;
        cout << "\nAll Students Information:\n";
        while (getline(inFile, line))
        {
            cout << line << "\n";
        }
        inFile.close(); 
    }
    else
    {
        cout << "Error opening file for reading!\n";
    }
}

int main() 
{
    int choice;

    do 
    {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            DisplayStudentsData();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again later.\n";
        }
    } while (choice != 3);

    return 0;
}
