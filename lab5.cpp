// devruz
// lab assignment 5

#include<iostream>
using namespace std;
int main(){

    // The program asks the user to enter a positive is integer
    // then it can reverses the digits of that number using a do while loop
    int num, n, reverse = 0, remain;
    
    do {

        cout << "\n----- Task 1 -----\n\n";
        cout << "Enter a positive integer: ";
        cin >> num;
        if (num < 0) {
            cout << "Invalid! Please enter a positive integer.\n";
            
        } else {
            n = num;
            do {
                remain = n % 10;
                reverse = reverse * 10 + remain;
                n = n / 10;
            } while (n > 0);
            cout << " Reverse number of " << num << " is: " << reverse << endl;
        }

    } while (num < 0);

    // This menu based program that allows the user to enter and analyze student marks.
    int choice, count = 0, sum = 0, highest = 0;
    do {
        cout << "\n----- Task 2 -----\n\n";
        cout << "MENU\n";
        cout << "1. Add mark\n";
        cout << "2. Show avarage\n";
        cout << "3. Find highest mark\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            
            case 1:{
                char again;
                int mark;
                do {
                    cout << "Enter a student's mark: ";
                    cin >> mark;

                    if (mark <= 0){
                        cout << "Invalid mark!\n";
                    } else {
                        
                        sum += mark;
                        count++;
                        if (mark > highest)
                        highest = mark;
                        cout << "Mark added succesfully.\n";
                    }

                    cout << "Add another mark? (y/n): ";
                    cin >> again;

                }while (again == 'y' || again == 'Y');
            }
            break;
            case 2:{
                if (count > 0){
                    int average = (float)sum / count;
                    cout << "Average mark = " << average << endl;
                } else{
                    cout << "No marks added yet.\n";
                }
                break;
                
            }
            case 3:{
                if (count > 0)
                cout << "Highest mark = " << highest << endl;
                else 
                cout << "No marks added yet.\n";
                break;

            }
            case 4:{
                cout << "Your program ended! Thank you.\n";
                break;
            }
            default:{
                cout << "Invalid input. Please enter a number from 1 to 4.\n";
                break;
            }
        }
    }while (choice != 4);

    // Program that helps a cinema record and calculate
    // how many tickets were sold across all shows in a single day

    cout << "\n----- Task 3 -----\n\n";
    int summ = 0, tickets, countt = 0;
    for (int i = 1; i <= 5; i++){
        cout << "Enter tickets sold for show " << i << " : ";
        cin >> tickets;
        summ += tickets;
        countt++;
    }
    cout << "-------------------------------\n";
    cout << "Total tickets sold today: " << summ << endl;

    // the program that can print a tree from stars
    cout << "\n------ Task 4 -----\n\n";
    int height;
    cout << "Enter a triangle height: ";
    cin >> height;

    for (int i = 1; i <= height; i++){
        for (int j = 1; j <=height - i; j++){
            cout << " ";
        }
        for (int k = 1; k <= (2 * i) - 1; k++){
            cout << "*";
        }
        cout << endl;
    }

    // The program that can print special number pattern
    cout << "\n----- Task 5 -----\n\n";
    int k;
    cout << "Enter a number: ";
    cin >> k;
    for(int i = 1; i <= k; i++){
        for (int space = 1; space <= k - i; space++){
            cout << " ";
        }
        for (int number = 1; number <= i; number++){
            cout << number;
        }
        cout << endl;
    }
 

    return 0;
}