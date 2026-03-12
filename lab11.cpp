// In this code we will build library managment system that can make easy to use by Menu
// By using this program you can add new book with its information 
// Also you can delete info that you added before
// As well as programm allows you to search the book by its author

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
  int option = 0;
  int num = 0;


  string* titles = nullptr;
  string* authors = nullptr;
  int* years = nullptr;
  char* availability = nullptr;
  
  do {

    cout << "\n===== LIBRARY MANAGEMENT MENU =====\n";
    cout << "1. Add book\n";
    cout << "2. Display all records\n";
    cout << "3. Delete book\n";
    cout << "4. Search Book by Author\n";
    cout << "5. Exit\n";
    cout << "Choose an option (1-5): ";
    cin >> option;
    
    switch(option) {
      case 1: {

        delete[] titles;
        delete[] authors;
        delete[] years;
        delete[] availability;

        cout << "Enter number of books you have: ";
        cin >> num;
        titles = new string[num];
        authors = new string[num];
        years = new int[num];
        availability = new char[num];

        for (int i = 0; i < num; i++) {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Enter book title: ";
          getline(cin, titles[i]);
          cout << "Enter author: ";
          getline(cin, authors[i]);
          cout << "Enter publication year: ";
          cin >> years[i];
          cout << "Enter availability status (Y/N); ";
          cin >> availability[i];
          cout << "-----------------------------------------\n";
        }
        cout << "Added succesfully.\n";  
        break;
      }
      case 2: {
        if (titles == nullptr) {
          cout << "No records to display!\n";
        } else {
          cout << "\n===== ALL BOOKS RECORDS =====\n";
          for (int i = 0; i < num; i++) {
            cout << "Index: " << i << "\n"
            << "Title: " << titles[i] << "\n"
            << "Author: " << authors[i] << "\n"
            << "Year: " << years[i] << "\n"
            << "Available: " << availability[i] << "\n"
            << "-----------------------------\n";
          }
        }
        break;
      }        
      case 3: {

        if (titles == nullptr || num == 0) {
            cout << "No books to delete!\n";
            break;
        }

        int index;
        cout << "Enter index of book to delete: ";
        cin >> index;

        if (index < 0 || index >= num) {
            cout << "Invalid index!\n";
            break;
        }
        for (int i = index; i < num - 1; i++) {
            titles[i] = titles[i + 1];
            authors[i] = authors[i + 1];
            years[i] = years[i + 1];
            availability[i] = availability[i + 1];
        }

        num--;

        cout << "Book deleted successfully!\n";

        break;
       }
      case 4: {

        if (titles == nullptr || num == 0) {
            cout << "No books available to search!\n";
            break;
        }

        string searchAuthor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter author name to search: ";
        getline(cin, searchAuthor);

        bool found = false;

        for (int i = 0; i < num; i++) {
          if (authors[i] == searchAuthor) {

            cout << "\nBook Found!\n";
            cout << "Index: " << i << endl;
            cout << "Title: " << titles[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Year: " << years[i] << endl;
            cout << "Available: " << availability[i] << endl;
            cout << "-----------------------------\n";
            
            found = true;
          }
        }
        if (!found) {
            cout << "No book found by this author.\n";
        }
          break;
      } 
      case 5: {
        cout << "Program ended! Thank you\n";
        break;
      }
      default: {
        cout << "Invalid input!\n";
        break;
      }
    }
  } while(option != 5);
  delete[] titles;
  delete[] authors;
  delete[] years;
  delete[] availability;
  return 0;
}