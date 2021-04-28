#include <iostream>
using namespace std;

int main() {
    //Variables needed for calculation
    int userNumFirst = 0;
    int userNumSecond = 0;
    int userNumSquared = 0;
    int userNumCubed = 0;
    int userNumSum = 0;
    int userNumProduct = 0;

    //First part of user input
    cout << "Enter integer: ";
    cin  >> userNumFirst;
    cout << endl;

    //First calculations of user input
    userNumSquared = userNumFirst * userNumFirst;
    userNumCubed = userNumFirst * userNumFirst * userNumFirst;

    //Output of first calculations
    cout << "You entered: " << userNumFirst << endl;
    cout << userNumFirst << " squared is " << userNumSquared << endl;
    cout << "And " << userNumFirst << " cubed is " << userNumCubed << "!!" << endl;

    //Second part of user input
    cout << "Enter another integer: ";
    cin  >> userNumSecond;
    cout << endl;

    //Second calculations of user input
    userNumSum = userNumFirst + userNumSecond;
    userNumProduct = userNumFirst * userNumSecond;

    //Output of second calculations
    cout << userNumFirst << " + " << userNumSecond << " is " << userNumSum << endl;
    cout << userNumFirst << " * " << userNumSecond << " is " << userNumProduct << endl;
    return 0;
}