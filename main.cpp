/////////////////////////////////////////////////////////////////////
// Name: Zander Leone
// Date: 10/14/2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Asks for number of patients, their names,
//                      weights, and heights, and calculates their
//                      BMI and weight classification
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double cmToMeter(double height);
double calcBMI(double weight, double height);
string weightClass(double BMI);

int main()
{
    int patientCount = 0;
    double kiloG = 0;
    double height = 0;
    double BMI = 0;
    string patientName;

    cout << "How many patients do you want to process today? ";
    cin >> patientCount;
    cout << endl << endl;
    cout << setprecision(2) << fixed;

    for (int i = 1; i <= patientCount; i++) {
        cin.ignore();
        cout << "Enter the patient's name (#" << i << "): ";
        getline(cin, patientName);
        cout << "Enter weight in kilograms: ";
        cin >> kiloG;
        if (kiloG < 0) {
            cout << defaultfloat;
            cout << "ERROR: The value " << kiloG << " is invalid for weight in kilograms." << endl;
            cout << "Program ended." << endl;

            return 0;
        }
        cout << "Enter height in centimeters: ";
        cin >> height;
        if (height < 0) {
            cout << defaultfloat;
            cout << "ERROR: The value " << height << " is invalid for height in centimeters." << endl;
            cout << "Program ended." << endl;

            return 0;
        }
        height = cmToMeter(height);
        BMI = calcBMI(kiloG, height);

        cout << patientName << "'s BMI is: " << BMI << endl;
        cout << "The BMI classification is " << weightClass(BMI) << endl << endl << endl;
    }

    cout << "Thank you for using our system." << endl;

    return 0;
}

double cmToMeter(double height) {
    return height / 100;
}

double calcBMI(double weight, double height) {
    return weight / (height * height);
}

string weightClass(double BMI) {
    if (BMI < 18.5){
        return "Underweight";
    }
    else if (BMI < 25) {
        return "Normal";
    }
    else if (BMI < 30) {
        return "Overweight";
    }
    else {
        return "Obese";
    }
}