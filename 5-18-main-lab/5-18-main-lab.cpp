#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes so main() is easier to read
// FIXME: Think about changing the appropriate parameters to constants
double PaymentSimulation(double initialLoan, double lengthPayback, double interestRate, double initialGuess); //FIXME: Does initialGuess need to be a constant or variable?
double ExactCalculation(const double initialLoan, const int lengthPayback, const double interestRate);

// Global variables

int main() {
    // Variables
    int lengthUserPayback = 0;
    double initialUserLoanAmount = 0.0;
    double interestUserRate = 0.0;
    double initialUserGuess = 0.0;
    double returnedAmountOwed = 0.0;

    // Prompt user for inputs
    cout << "Enter initial loan amount: ";
    cin >> initialUserLoanAmount;
    cout << endl;

    cout << "Enter annual interest rate: ";
    cin >> interestUserRate;
    cout << endl;

    cout << "Enter length of payback period (in years): ";
    cin >> lengthUserPayback;
    cout << lengthUserPayback << endl;
    cout << endl;

    cout << "Guess monthly payment: ";
    cin >> initialUserGuess;
    cout << endl << endl;

    //FIXME: Use one for and one while loop

    // Payment simulation loop
    returnedAmountOwed = PaymentSimulation(initialUserLoanAmount, lengthUserPayback, interestUserRate, initialUserGuess);
    while (returnedAmountOwed != 0) {
        cout << "It's working!" << endl;
    }

    // Output result of simulation. Precision is set to round to nearest cent.
    cout << fixed << setprecision(2);
    cout << "Final monthly payment: $" << "" << endl; //FIXME: Fill in blank with the output from algorithm
    cout << "Final amount owed: $" << returnedAmountOwed << endl; //FIXME: Fill in blank with the output from algorithm

    // Verification with exact calculation. Precision is set to round to nearest cent.
    cout << "Monthly payment (from formula): $";
    cout << fixed << setprecision(2) << ExactCalculation(initialUserLoanAmount, lengthUserPayback, interestUserRate);
    
    return 0;
}


// Payment simulation function
// FIXME: Is PaymentSimulation() supposed to be a double?
// FIXME: Make sure that int lengthPayback doesn't need to be double lengthPayback
// FIXME: Think about changing the appropriate parameters to constants
double PaymentSimulation(double initialLoan, double lengthPayback, double interestRate, double initialGuess) {
    // Using a double here to prevent possible integer division somewhere
    double numPayments = 0.0;
    double debtLeft = initialLoan;

    numPayments = lengthPayback * 12;

    for (int i = 0; i < numPayments; ++i) {
        debtLeft = ((1 + (interestRate / 12.0)) * debtLeft) - initialGuess;
        cout << debtLeft << endl; //FIXME: remove this when done testing
    }



    return debtLeft;
}
// Exact calculation function
// FIXME: Make sure that int lengthPayback doesn't need to be double lengthPayback
// FIXME: Think about changing the appropriate parameters to constants
double ExactCalculation(double initialLoan, const int lengthPayback, const double interestRate) {
    double monthlyPayment;
    monthlyPayment = ((1 - (1 + (interestRate / 12))) / ((pow(1 + (interestRate / 12), -12 * lengthPayback)) - 1)) * initialLoan;
    return monthlyPayment;
}