#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes so main() is easier to read
double PaymentSimulation(double initialLoan, double lengthPayback, double interestRate, double initialGuess);
double ExactCalculation(double initialLoan, int lengthPayback, double interestRate);

// Global variables
const double MONTHS_IN_YEAR = 12.0;

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
    cout << endl;
    cout << endl;

    cout << "Guess monthly payment: ";
    cin >> initialUserGuess;
    cout << endl << endl;


    // Payment simulation loop
    returnedAmountOwed = PaymentSimulation(initialUserLoanAmount, lengthUserPayback, interestUserRate, initialUserGuess);
    do {
        // Instructions on how to update the initial guess if there's still a balance (paid too little)
        if (returnedAmountOwed > 0) {
            initialUserGuess = initialUserGuess + (returnedAmountOwed / (MONTHS_IN_YEAR * lengthUserPayback));
            returnedAmountOwed = PaymentSimulation(initialUserLoanAmount, lengthUserPayback, interestUserRate, initialUserGuess);
        }
        // Instructions on how to update the initial guess if paid too much
        else if (returnedAmountOwed < 0) {
            initialUserGuess = initialUserGuess + (returnedAmountOwed / (MONTHS_IN_YEAR * lengthUserPayback));
            returnedAmountOwed = PaymentSimulation(initialUserLoanAmount, lengthUserPayback, interestUserRate, initialUserGuess);
        }
    } while (fabs(returnedAmountOwed) >= 0.01);


    // Output result of simulation. Precision is set to round to nearest cent.
    cout << fixed << setprecision(2);
    cout << "Final monthly payment: $" << initialUserGuess << endl;
    cout << "Final amount owed: $" << returnedAmountOwed << endl;


    // Verification with exact calculation. Precision is set to round to nearest cent.
    cout << "Monthly payment (from formula): $";
    cout << fixed << setprecision(2) << ExactCalculation(initialUserLoanAmount, lengthUserPayback, interestUserRate);


    return 0;
}


// Payment simulation function
double PaymentSimulation(double initialLoan, double lengthPayback, double interestRate, double initialGuess) {
    // Using a double here to prevent possible integer division somewhere
    double numPayments = 0.0;
    double debtLeft = initialLoan;

    numPayments = lengthPayback * MONTHS_IN_YEAR;

    for (int i = 0; i < numPayments; ++i) {
        debtLeft = ((1 + (interestRate / MONTHS_IN_YEAR)) * debtLeft) - initialGuess;
    }

    return debtLeft;
}

// Exact calculation function
double ExactCalculation(double initialLoan, const int lengthPayback, const double interestRate) {
    double monthlyPayment;
    monthlyPayment = ((1 - (1 + (interestRate / MONTHS_IN_YEAR))) / ((pow(1 + (interestRate / MONTHS_IN_YEAR), -MONTHS_IN_YEAR * lengthPayback)) - 1)) * initialLoan;
    return monthlyPayment;
}