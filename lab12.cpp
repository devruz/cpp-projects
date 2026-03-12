#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Student {
    int id;
    string name; 
    string faculty;
    double gpa;
    string contact; 
};

void addStudent(Student students[], int &studentCount);
void displayStudents(const Student students[], int studentCount);
void findStudent(const Student students[], int studentCount);
void updateStudent(Student students[], int studentCount);
void deleteStudent(Student students[], int &studentCount);


int main() {
    int choice;
    Student students[MAX];
    int studentCount = 0;
    do {
        cout << "===============================\n";
        cout << "     STUDENT DATABASE MENU\n";
        cout << "===============================\n";
        cout << "1. Add a new student\n";
        cout << "2. Display all students\n";
        cout << "3. Search for a student\n";
        cout << "4. Update student information\n";
        cout << "5. Delete a student record\n";
        cout << "6. Exit\n";
        cout << "-------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                addStudent(students, studentCount);
                break;
            }
            case 2: {
                displayStudents(students, studentCount);
                break;
            }
            case 3: {
                findStudent(students, studentCount);
                break;
            }
            case 4: {
                updateStudent(students, studentCount);
                break;
            }
            case 5: {
                deleteStudent(students, studentCount);
                break;
            }
            case 6: {
                cout << "Program ended. Thank you ended.\n";
                break;
            }
            default: {
                cout << "Invalid input!\n";
                break;
            }
        } 
    } while(choice != 6);
    
}

void addStudent(Student students[], int &studentCount){
    Student s;
    if (studentCount >= MAX) {
        cout << "Array is full!\n";
        return;
    }
    cout << "\n--- Add New Student ---\n";
    cout << "Enter student ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter full name: ";
    getline(cin, s.name);

    cout << "Enter faculty: ";
    getline(cin, s.faculty);

    cout << "Enter GPA(0.0 - 4.0): ";
    cin >> s.gpa;
    cin.ignore();
    if (s.gpa < 0 || s.gpa > 4) {
        cout << "Invalid input. Please try again.\n";
        return;
    }

    cout << "Enter contact (phone/email): ";
    getline(cin, s.contact);
    students[studentCount] = s;
    studentCount++;
    cout << "student added succesfully.\n";
 
}

void displayStudents(const Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students in database.\n";
        return;
    }

    cout << "--- Student List ---\n";
    cout << "ID          " << "Name                   "
    << "Faculty     " << "GPA     " << "Contact           " << endl;
    cout << "----------------------------------------------------------------------------------------\n";
    for (int i = 0; i < studentCount; i++) {
        cout << students[i].id << "     " 
             << students[i].name << "     "
             << students[i].faculty << "       " 
             << students[i].gpa << "       " 
             << students[i].contact << endl;   
    }
}

void findStudent(const Student students[], int studentCount) {
    int option;
    
        cout << "--- Search student ---\n";
        cout << "1. Search by id\n";
        cout << "2. Search by Name\n";
        cout << "Enter your option: ";
        cin >> option;
        bool found = false;

        if (option == 1) {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            for(int i = 0; i < studentCount; i++){
                if(id == students[i].id) {
                    cout << "Student found:\n";
                    cout << "ID: " << students[i].id << endl;
                    cout << "Name: " << students[i].name << endl;
                    cout << "Faculty: " << students[i].faculty << endl;
                    cout << "GPA: " << students[i].gpa << endl;    
                    cout << "Contact: " << students[i].contact << endl;

                    found = true;
                }
                
            }
        }
        else if (option == 2) {
            string name;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            for(int i = 0; i < studentCount; i++){
                if(name == students[i].name) {
                    cout << "Student found:\n";
                    cout << "ID: " << students[i].id << endl;
                    cout << "Name: " << students[i].name << endl;
                    cout << "Faculty: " << students[i].faculty << endl;
                    cout << "GPA: " << students[i].gpa << endl;    
                    cout << "Contact: " << students[i].contact << endl;

                    found = true;
                }
                
            }
        }
        if(!found)
        cout << "Student not found.\n";
    
}

void updateStudent(Student students[], int studentCount){
    int id;
    cout << "--- Update Student ---\n";
    cout << "Enter student ID to update: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < studentCount; i++){
        if (id == students[i].id){
            cout << "Current information:\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Faculty: " << students[i].faculty << endl;
            cout << "GPA: " << students[i].gpa << endl;
            cout << "Contact: " << students[i].contact << endl;

            found = true;

            int a;
        
            do {
                cout << "What do you want to update?\n";
                cout << "1. Name\n";
                cout << "2. Faculty\n";
                cout << "3. GPA\n";
                cout << "4. Contact\n";
                cout << "5. Finish updating\n";
                cout << "Enter your choice: ";
                cin >> a;
                switch(a) {
                    case 1:{
                        cout << "Enter a new name: ";
                        cin.ignore();
                        getline(cin, students[i].name);
                        break;
                    }
                    case 2:{
                        cout << "Enter a new faculty: ";
                        cin.ignore();
                        getline(cin, students[i].faculty);
                        break;
                    }
                    case 3:{
                        cout << "Enter a new GPA: ";
                        cin >> students[i].gpa;
                        break;
                    }
                    case 4:{
                        cout << "Enter a new contact: ";
                        cin.ignore();
                        getline(cin, students[i].contact);
                        break; 
                    }
                    case 5:{
                        
                        cout << "Finished updating.\n";
                        break;
                    }
                    default:{
                        cout << "Invalid input! Please try again.\n";
                        break;
                    }

                } 
            }while(a != 5);
        }
          
    }
    if (!found) {
        cout << "Student not found!\n";
    }
}

void deleteStudent(Student students[], int &studentCount){
    int id;
    cout << "--- Delete Student ---\n";
    cout << "Enter student ID to delete: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < studentCount; i++){
        if (id == students[i].id){
            
            found = true;

            for(int j = i; j < studentCount - 1; j++){
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student delete successfully.\n";
            break;

        }
    }
    if(!found){
        cout << "Student not found.\n";
    }
}

    
