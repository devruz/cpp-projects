// devruz
// lab assignment 8
#include<iostream>
using namespace std;

int gcd(int a, int b);
void withdraw(double&balance, double amount);
void addBonus(int &grade, int bonus);

int main() {
    int option;
    do {

        // this menu - based program 
        // that lets the user choose one of the several tasks.
        cout << "\n===== Menu =====\n\n";
        cout << "1. G.C.D (recursive)\n";
        cout << "2. Banking\n";
        cout << "3. Grading\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:{
                int a, b;
                do {

                    cout << "Enter two positive integers: ";
                    cin >> a >> b;

                    if (a <= 0 || b <= 0)
                        cout << "Invalid data! Try again." << endl;

                } while (a <= 0 || b <= 0);

                cout << "G.C.D = " << gcd(a, b) << endl;
                break;
            }
            case 2:{
                double balance, amount;
                do {
                    cout << "Enter your current amount: ";
                    cin >> balance;

                    if (balance <= 0)
                        cout << "Invalid data! Try again." << endl;

                } while (balance <= 0);
                do {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;

                    if (amount <= 0)
                        cout << "Invalid data! Try again." << endl;

                } while (amount <= 0);
                withdraw(balance, amount);
                break;
            }
            case 3:{
                int grade, bonus;
                do {
                    
                    cout << "Enter current grade (0-100): ";
                    cin >> grade;

                    if (grade <= 0) 
                        cout << "Invalid input! Try again.\n";

                }while (grade <= 0);

                cout << "Enter bonus points: ";
                cin >> bonus;

                addBonus(grade, bonus);
                break;
            }
            case 4:{

                cout << "Program ended! Thank you.\n";
                break;
            }
            default:{

                cout << "Invalid input! Please try again.";
                break;
            }
        }

    } while (option != 4);
    return 0;
}
int gcd(int a, int b) {

    if (b == 0)
        return a;

    return gcd(b, a % b);
}
void withdraw(double&balance, double amount) {

    if (amount > balance) {
        cout << "Error: Insufficient balance!\n";

    } else {

        balance -= amount;
        cout << "Withdrawal successful.\n";
        cout << "Remaining balance: " << balance << endl;
    }
}
void addBonus(int &grade, int bonus) {

    grade += bonus;
    cout << "Bonus applied.\n";
    cout << "Updated grade: " << grade << endl;
}