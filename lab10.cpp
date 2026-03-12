#include <iostream>
using namespace std;

void displayRecords(int *p, int n);
void analyze(int *p, int n, int *min, int *max, double *avg);
void sortPatient(int *p, int n); 
void searchPatient(int *p, int n);

int main() {
  int option, n = 0;
  int patientData[30]; 
  int *p = patientData;
  do {
    cout << "===== HOSPITAL PATIENT MONITORING SYSTEM =====\n";
    cout << "1. Enter patient data\n";
    cout << "2. Display all records\n";
    cout << "3. Analyze data\n";
    cout << "4. Sort patient\n";
    cout << "5. Search patient\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
    cin >> option;
    switch(option) {
      case 1: {
        cout << "How many patient?: ";
        cin >> n;
        cout << "Enter heart rate for each patient:\n";
        for(int i=0; i<n; i++) {
          cout << "Patient " << i+1 << " : ";
          cin >> *(p+i);
        }
        cout << "Patient data entered successfully.\n";
        break;
      }
      case 2: {
        if (n == 0) {
          cout << "No patient data available.\n";
        }
        else {
          displayRecords(p, n);
        }
        break;

      }
      case 3: {
        int min, max;
        double avg;
        analyze(p,n,&min,&max,&avg);

        cout << "\n--- Data Analysis ---\n";
        cout << "Lowest heart rate = " << min << endl;
        cout << "Highest heart rate = " << max << endl;
        cout << "Average heart rate = " << avg << endl;    
        break;    
      }
      case 4: {
        if (n == 0) {
          cout << "Patient data sorted succesfully\n";
        }
        else {
          sortPatient(p, n);
        }
        break;
      }
      case 5: {
        if (n == 0) {
          cout << "No data to search!!!\n";
        }
        else {
          searchPatient(p, n);
        }
        
        break;
      }
      case 6: {
        cout << "Program ended. Thank you!\n";
        break;
      }
      default: {
        cout << "Invalid input!\n";
        break;
      }
    }
  } while(option != 6);
}

void displayRecords(int *p, int n) {
  cout << "\n--- Patient Datas ---\n";
  for (int i = 0; i < n; i++) {
    cout << "Patient " << i + 1 
    << ": heart rate = " << *(p+i)
    << " address = " << (p + i) << endl;
  }
}

void analyze(int *p, int n, int *min, int *max, double *avg) {
  *min = *p;
  *max = *p;
  int sum = 0;
   for(int i = 0; i < n; i++){

        if(*(p+i) < *min)
            *min = *(p+i);

        if(*(p+i) > *max)
            *max = *(p+i);

        sum += *(p+i);
    }

    *avg = (double)sum / n;
}

void searchPatient(int *p, int n){

    int target;
    cout << "Enter heart rate to search: ";
    cin >> target;

    for(int i = 0; i < n; i++){

        if(*(p+i) == target){
            cout << "Heart rate " << target
                 << " found for patient #" << i+1 << endl;
            return;
        }

    }

    cout << "No patient found with heart rate " << target << endl;

}

void sortPatient(int *p, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (*(p + j) > *(p + j + 1)) {
        int temp = *(p + j);
        *(p + j) = *(p + j + 1);
        *(p + j + 1) = temp;
      }
    }
  }
}