// devruz
// lab assignment 9
#include<iostream>
using namespace std;
int main() {
    int choice;
    const int MAX = 100;
    int students[MAX];
    int size = 0;
    do {
        
        // menu based program that can analyze and display student information.

        cout << "\n===== Student ID Manager =====\n\n";
        cout << "1. Add student\n";
        cout << "2. Insert student\n";
        cout << "3. Delete student\n";
        cout << "4. Search student\n";
        cout << "5. Sort student\n";
        cout << "6. Display all students\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:{

                if (size >= MAX) {
                    cout << "Array is full!\n";
                    
                } else {

                    int id;
                    cout << "Enter student id: ";
                    cin >> id;
                    students[size] = id;
                    size++;
                    cout << "Student added.\n";

                }
                break;
            }
            case 2:{
                if (size <  MAX){
                
                    int pos, id;
                    cout << "Enter position: ";
                    cin >> pos;
                    
                    if (pos > size || pos < 0){
                        cout << "Invalid postion.\n";
                    } else {
                        cout << "Enter a student id: ";
                        cin >> id;
                        for (int i = size; i > pos; i--){
                            students[i] = students [i - 1];
                        }

                        students[pos] = id;
                        size++;
                        cout << "Student inserted.\n";

                    }       
                } else {

                    cout << "Array is full.\n";
                } 
                break;  
            }
            case 3: {

                int index;
                cout << "Enter index to delete: ";
                cin >> index;

                if (index < 0 || index >= size) {
                    cout << "Invalid index.\n";
                } else {
                    for (int i = index; i < size - 1; i++) {
                        students[i] = students[i + 1];
                    }
                    size--;
                    cout << "Student deleted.\n";
                }
                break;
            }
            case 4: {

                int id;
                bool found = false;
                cout << "Enter ID to search: ";
                cin >> id;

                for (int i = 0; i < size; i++) {
                    if (students[i] == id) {
                        cout << "Student with ID " << id
                            << " was found at index " << i << ".\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student with ID " << id << " was not found.\n";
                }
                break;
            }
            case 5: {
        
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (students[j] > students[j + 1]) {
                            int temp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = temp;
                        }
                    }
                }
                cout << "Students sorted by ID in ascending order.\n";
                break;
            }
            case 6: {

                if (size == 0) {
                    cout << "No students to display.\n";
                } else {
                    for (int i = 0; i < size; i++) {
                        cout << "Index " << i << ": " << students[i] << endl;
                    }
                }
                break;
            }
            case 7:{

                cout << "Program ended. Thank you!\n";
                break;
            }
            default: {


                cout << "Invalid input! Please enter a number from 1 to 7.\n";
                break;
            }         
        }

    } while (choice != 7);
    
    return 0;

}
