// devruz
// lab assignment 7
#include<iostream>
using namespace std;
void showMenu();
int area(int height, int width);
float area(float side1, float side2);
int area(int edge);
void qualityPoints(int grade);
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a:b;
} 

template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}
int main() {

    // program to calculate area of following figures using function overloading.
    cout << "\n===== Task 1 =====\n";
    int option;
    do {
        showMenu();
        cin >> option;
        switch (option) {
            case 1: {
                int height, width;
                cout << "Enter height: ";
                cin >> height;
                cout << "Enter width: ";
                cin >> width;
                area(height, width);
                break;
            }
            case 2:{
                float side1, side2;
                cout << "Enter side: ";
                cin >> side1;
                cout << "Enter another side: ";
                cin >> side2;
                area(side1, side2);
                break;
            }
            case 3:{
                int edge;
                cout << "Enter edge: ";
                cin >> edge;
                area(edge);
                break;
            }
            case 4: {
                cout << "Thank you! Program ended.";
                break;
            }
            default:{
                cout << "Invalid input! Please try again.\n";
                break;
            }
        }
    } while(option != 4); 

    // Program that can analyze student grades.
    cout << "\n\n===== Task 2 =====\n\n";
    int grade;
    do {
        cout << "Enter your average (0 - 100): ";
        cin >> grade;
        if (grade < 0 || grade > 100) {
            cout << "Invalid input! Please enter a value between 0 and 100.\n";
        }
    } while (grade < 0 || grade > 100);
    qualityPoints(grade);

    // Program  that uses a function templates called max and min
    // to determine the larger and smaller arguments.
    cout << "\n===== Task 3 =====\n";
    cout << "\nIntegers\n";
    cout << "Maximum: " << maximum(100, 120) << endl;
    cout << "Minimum: " << minimum(100, 120) << endl;
    cout << "\nFloating points numbers\n";
    cout << "Maximum: " << maximum(21.02, 25.04) << endl;
    cout << "Minimum: " << minimum(21.02, 25.04) << endl;
    cout << "\nCharacters\n";
    cout << "Maximum: " << maximum('H', 'Q') << endl;
    cout << "Minimum: " << minimum('H', 'Q') << endl;
    return 0;
}
void showMenu() {
    cout << "\n===== Menu =====\n";
    cout << "1. Rectangle\n";
    cout << "2. Triangle\n";
    cout << "3. Square\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}
int area(int height, int width) {
    int s = height * width;
    cout << "Area: " << s << endl;
}
float area(float side1, float side2) {
    float x = (float)1/2 * side1 * side2;
    cout << "Area: " << x << endl;
}
int area(int edge) {
    int n = edge * edge;
    cout << "Area: " << n << endl;
}
void qualityPoints(int grade){
    int result;
    if (grade <= 100 && grade >= 90)
    result = 4;
    else if (grade < 90 && grade >= 80)
    result = 3;
    else if (grade < 80 && grade >= 70)
    result = 2;
    else if (grade < 70 && grade >= 60)
    result = 1;
    else if (grade < 60)
    result = 0;
    else {
        cout << "Invalid input! Try again.\n";
        return;
    }
    cout << "Your grade: " << result << endl;

}
