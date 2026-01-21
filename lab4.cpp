// devruz
// lab assignment 4 
// loops (do-while, while), conditional branching (if-else),
#include<iostream>
using namespace std;
int main(){

    // A program that keeps asking the user for a password 
    // until they type the correct one
    cout << "-------- Task 1 ---------\n" << endl; 

    int password = 123456789;
    int x;
    do {
        cout << "Enter your password: ";
        cin >>x;
        if (x != password)
        do {
            cout << "Invalid password! Please try again: ";
            cin >> x;
        }while (x != password);
        
    }while(x != password);
    cout << "Access granted!" << endl;

    // A program that keeps asking for student ages one by one, 
    // until the user enters -1 (which means “stop”).
    cout << "\n-------- Task 2 -------\n\n";

    int age;
    int sum = 0, count = 0;
    double average;
    while(true){
        cout << "Enter student age (-1 to stop): ";
        cin >> age;
        if (age == -1) 
        break;
        if (age < 0) {
            cout << "Invalid age! Please try again.\n";
            continue;
        }
        sum += age;
        count++;
    }
    if (count > 0) {
        average = sum / count;
        cout << "Average age = " << average << endl;
    } else {
        cout << "No valid ages entered." << endl;
    }

    // Program to input a number and then calculate sum of its digits.
    cout <<"\n-------- Task 3 -------\n";

    int num, summ = 0;
    cout << "Enter a number: ";
    cin >> num;
    int callnumber = num;
    while (num > 0) {
        summ += num % 10;
        num /= 10;
    }
    cout << "Sum of digits of " << callnumber << " = " << summ << endl;

    return 0;

}

