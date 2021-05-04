#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes so main() is easier to read
// FIXME: Think about changing the appropriate parameters to constants
double PaymentSimulation(double initialLoan, int lengthPayback, double interestRate, double initialGuess);
double ExactCalculation(double initialLoan, int lengthPayback, double interestRate);

// Global variables

int main() {
    // Variables
    int lengthUserPayback = 0;
    double initialUserLoanAmount = 0.0;
    double interestUserRate = 0.0;
    double initialUserGuess = 0.0;

    // Prompt user for inputs
    cout << "Enter initial loan amount: ";
    cin >> initialUserLoanAmount;
    cout << endl;

    cout << "Enter annual interest rate: ";
    cin >> interestUserRate;
    cout << endl;

    cout << "Enter length of payback period (in years): ";
    cin >> lengthUserPayback;
    cout << endl;

    cout << "Guess monthly payment: ";
    cin >> initialUserGuess;
    cout << endl << endl;

    //FIXME: Use one for and one while loop

    // Payment simulation loop

    cout << fixed << setprecision(2);
    cout << "Final monthly payment: $" << "" << endl; //FIXME: Fill in blank with the output from algorithm
    cout << "Final amount owed: $" << "" << endl; //FIXME: Fill in blank with the output from algorithm

    // Verification with exact calculation
    cout << "Monthly payment (from formula): $";
    cout << fixed << setprecision(2) << ExactCalculation(initialUserLoanAmount, lengthUserPayback, interestUserRate);
    
    return 0;
}


// Payment simulation function
// FIXME: Is PaymentSimulation() supposed to be a double?
// FIXME: Make sure that int lengthPayback doesn't need to be double lengthPayback
// FIXME: Think about changing the appropriate parameters to constants
double PaymentSimulation(double initialLoan, int lengthPayback, double interestRate, double initialGuess) {
    double amountOwed = 0;

    return amountOwed;
}
// Exact calculation function
// FIXME: Make sure that int lengthPayback doesn't need to be double lengthPayback
// FIXME: Think about changing the appropriate parameters to constants
double ExactCalculation(double initialLoan, int lengthPayback, double interestRate) {
    double monthlyPayment;
    monthlyPayment = ((1 - (1 + (interestRate / 12))) / ((pow(1 + (interestRate / 12), -12 * lengthPayback)) - 1)) * initialLoan;
    return monthlyPayment;
}