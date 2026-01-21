// devruz
// lab_assignment3
// Appliying conditional logic and boolean expressions to real-world problems 
// while highlighting the need for explicit logical operators in range comparisons.
#include <iostream>
using namespace std;
int main(){
    
    // The programm can calculates a tax based on your salary
    cout << "=== Task 1 ===\n" << endl;
    float salary, tax;
    cout << "Enter your salary in USD: ";
    cin >> salary;

    if (salary < 1000) {
        tax = 0;
    }
    else if (salary >= 1000 && salary <= 2000) {
        tax = salary * 0.20;
    }
    else if  (salary > 2000 && salary <= 3000) {
        tax = 0.30;
    }
    else if (salary > 3000) {
        tax = 0.40;
    }
    
    double income = salary - tax;
    cout << "Tax payable: $" << tax << endl;
    cout << "Income after tax deduction: $" << income << endl;

    // The program on Task 2 determines whether a number is positive oer negative
    cout << "\n=== Task 2 ===\n" << endl;
    int number;
    cout << "Enter your number: ";
    cin >> number;
    if (number > 0) {
        cout << "Your number is positive!!!" << endl;
    }
    else if ( number < 0) {
        cout << " Your number is negative!!!" << endl;
    }
    else if (number == 0) {
        cout << "Your number is 0!!!" << endl;
    }

    // This program determines the grade of steel based on its hardness, 
    // carbon content, and tensile strength.
    cout << "\n=== Task 3 ===\n" << endl;
    double carbon;
    int hardness, tensile, grade;

    cout << "Enter hardness: ";
    cin >> hardness;
    cout << "Enter  carbon content: ";
    cin >> carbon;
    cout << "Enter tensile strength: ";
    cin >> tensile;

    bool a = hardness > 50;
    bool b = carbon < 0.7;
    bool c = tensile > 5600;
    
    if (a && b && c)
    grade = 10;
    else if (a && b)
    grade = 9;
    else  if (b && c)
    grade = 8;
    else if (a && c)
    grade = 7;
    else if (a || b || c)
    grade = 6;
    else
    grade = 5;
    
    cout << "Grade of steel: " << grade << endl;

    return 0;
}


