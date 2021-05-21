#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Constants
    const double SALES_TAX = 0.08;

    // Variables
    double userInput = 0.0;
    double subTotal = 0.0;
    double finalTotal = 0.0;
    bool continueLoop = true;

    // Continue getting user input until the user gives 0.0
    while (continueLoop) {
        cin >> userInput;
        if (userInput == 0.0) {
            continueLoop = false;
        }
    }



    return 0;
}
