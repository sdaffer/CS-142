#include <iostream>

using namespace std;

const int NUM_INTEGERS = 10;

int main(){
    // Declare array of int type and NUM_INTEGERS length
    int userIntArray[NUM_INTEGERS];


    for (int i = 0; i < NUM_INTEGERS; ++i) {

        // Loop through each position and input
        cin >> userIntArray[i];

        // Do the modulus calculation
        userIntArray[i] = userIntArray[i] % 2;

        // If divisible by 2, set the number at that position in the array to 0
        if (userIntArray[i] == 0) {
            userIntArray[i] = 1;
        }
        else {
            userIntArray[i] = 0;
        }
    }
    // Output the array in reverse order
    for (int i = NUM_INTEGERS - 1; i >= 0; --i) {
        cout << userIntArray[i] << endl;
    }


    return 0;
}