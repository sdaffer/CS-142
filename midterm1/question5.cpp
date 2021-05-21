#include <iostream>
#include <iomanip>
using namespace std;


// Global variables
const double SALES_TAX = 0.08;


// Main function
int main() {
    // Variables
    double userInput = 0.0;
    double subTotal = 0.0;
    double taxAmount = 0.0;
    double finalTotal = 0.0;
    bool continueLoop = true;

    // Continue getting user input until the user gives 0.0 - sum all user inputs into subtotal
    while (continueLoop) {
        cin >> userInput;
        subTotal = subTotal + userInput;
        if (userInput == 0.0) {
            continueLoop = false;
        }
    }

    // Final calculations
    taxAmount = subTotal * SALES_TAX;
    finalTotal = subTotal + taxAmount;

    // Output with proper formatting
    cout << setprecision(2) << fixed;
    cout << "The receipt for your order will have these totals" << endl << endl;
    cout << "Subtotal: $" << subTotal << endl;
    cout << "Sales tax: $" << taxAmount << endl;
    cout << "Total: $" << finalTotal << endl;

    return 0;
}