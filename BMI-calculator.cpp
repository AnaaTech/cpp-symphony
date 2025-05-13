#include <iostream>
#include <cmath>
using namespace std;
// Program to calculate BMI

//Function to ensure positive input
int getPositiveInput() {
    int value;
    while (true) {
        cin >> value;
        if (value > 0) {
            return value;
        } else {
            cout << "Please enter a positive number: ";
        }
    }
}

// Function to get positive double input
double getPositiveDoubleInput() {
    double value;
    while (true) {
        cin >> value;
        if (value > 0) {
            return value;
        } else {
            cout << "Please enter a positive number: ";
        }
    }
}
// Function to convert height from feet and inches to meters
double convertHeightToMeters(int feet, int inches) {
     double totalInches = (feet * 12) + inches;
    return totalInches * 0.0254;
}
// Function to convert weight from pounds to kilograms
double convertWeightToKilograms(int pounds) {
    return pounds * 0.453592;
}
// Function to calculate BMI
double calculateBMI(double weight, double height) {
    return weight / (height * height);
}
// Function to display weight status
void displayWeightStatus(double bmi) {
    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "Normal weight" << endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obesity" << endl;
    }
}
// Actual program starts here
int main() {
    int feet, inches, pounds;
    double height, weight, bmi;

    cout << "Enter your height (feet and inches): ";
    cout << "\nFeet: ";
    feet = getPositiveInput();
    cout << "Inches: ";
    inches = getPositiveInput();

    cout << "Enter your weight (pounds): ";
    pounds = getPositiveInput();

    // Convert height and weight
    height = convertHeightToMeters(feet, inches);
    weight = convertWeightToKilograms(pounds);

    // Calculate BMI
    bmi = calculateBMI(weight, height);

    // Display BMI and weight status
    cout << "Your BMI is: " << round(bmi * 100.0) / 100.0 << endl;
    displayWeightStatus(bmi);

    return 0;
}






