// devruz
// lab assignment 6
#include<iostream>
using namespace std;
void convertTime(int totalSeconds);
void convert(double amount, double rate);
void showMenu();
double total(double price, double quantity, double discount);
void displayResult(double totalPrice, double totalDiscount, double totalPay);

int main(){

    // The program that uses functions that can calculates and displays how many hours,
    // minuts and seconds are contained in a given total number of seconds.
    cout << "\n===== Task 1 =====\n\n";
    int totalSeconds, hours, min, sec;
    cout << "Enter total seconds: ";
    cin >> totalSeconds;
    if (totalSeconds < 0)
    cout << "Please enter a non-negative number of seconds.\n";
    else {
        convertTime(totalSeconds);    
    }

    // Program that converts money from one currency to another using 
    // an excange rate entered by the user
    cout << "\n===== Task 2 =====\n\n";
    char ans;
    do {
        double amount, rate;
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter excange rate: ";
        cin >> rate;
        convert(amount, rate);
        cout << "Do another conversation? (y/n): ";
        cin >> ans;

    }while (ans != 'n');
    cout << "\nThank you! Program ended.\n"; 

    // Menu based program that allows the user 
    // to enter and analyze purchased items.
    cout << "\n ===== Task 3 =====\n\n";
    int choice;
    char anss;
    double price, quantity, discount;
    double totalPrice = 0;
    double totalDiscount = 0;
    double totalPay = 0;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:{
                do {
                    cout << "Unit price: ";
                    cin >> price;
                    cout << "Quantity: ";
                    cin >> quantity;
                    cout << "Item discount(% 0-100): ";
                    cin >> discount;
                    double sTotal = price * quantity;
                    double disc = sTotal * (discount / 100);
                    double finalPay = total(price, quantity, discount);
                    totalPrice += sTotal;
                    totalDiscount += disc;
                    totalPay += finalPay;
                    cout << "Added -> total = " << sTotal << ", discount = " << disc << ", Total after discount = " << finalPay << endl;
                    cout << "Add another item? (y/n): ";
                    cin >> ans;
                }while(anss == 'y' || anss == 'y');
                cout << "Thank you.\n"; 
                break;
            }
            case 2:{
                displayResult(totalPrice, totalDiscount, totalPay);
                break;
            }
            case 3:{
                cout << "Thank you! Program ended.\n";
                break;
            }
            default:{
                cout << "Invalid input! Please try again.\n";
            }
        }
    }while(choice != 3);
    return 0;
}
void convertTime(int totalSeconds) {
    int hours = totalSeconds / 3600;
    int min = (totalSeconds % 3600) / 60;
    int sec = totalSeconds % 60;
    cout << hours << " hour " << min << " minute " << sec << " seconds.\n"; 
}
void convert(double amount, double rate) {
    double b = amount * rate;
    cout << "Converted amount: " << b << endl;
}
void showMenu() {
    cout << "===== Billing system =====\n";
    cout << "1. Add items\n";
    cout << "2. Show totals\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}
double total(double price, double quantity, double discount) {
    double sTotal = price * quantity;
    double disc = sTotal * (discount / 100);
    return sTotal - disc;   
}
void displayResult(double totalPrice, double totalDiscount, double totalPay) {
    if (totalPrice == 0) {
        cout << "No items available!\n";
    } else {
        cout << "\nTotal (before discounts): " << totalPrice << endl;
        cout << "Total discounts: -" << totalDiscount << endl;
        cout << "Total (to pay): " << totalPay << endl;
    }
}