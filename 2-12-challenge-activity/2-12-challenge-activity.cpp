#include <iostream>
using namespace std;

int main() {
    int amountToChange;
    int numFives;
    int numOnes;

    cin >> amountToChange;
    numFives = amountToChange / 5;

    /* Your solution goes here  */
    //Both of these solutions work, but they wanted the % operator used.
    //numOnes = amountToChange - (numFives * 5);
    numOnes = amountToChange % 5;

    cout << "numFives: " << numFives << endl;
    cout << "numOnes: " << numOnes << endl;


    return 0;
}