#include <iostream>
using namespace std;

int main() {
    const int NUM_ROWS = 2;
    const int NUM_COLS = 2;
    int milesTracker[NUM_ROWS][NUM_COLS];
    int i;
    int j;
    int maxMiles = 0; // Assign with first element in milesTracker before loop
    int minMiles = 0; // Assign with first element in milesTracker before loop
    int value;

    for (i = 0; i < NUM_ROWS; i++){
        for (j = 0; j < NUM_COLS; j++){
            cin >> value;
            milesTracker[i][j] = value;
        }
    }


    /* Your solution goes here  */
    maxMiles = milesTracker[0][0];
    minMiles = milesTracker[0][0];
    i = 0;
    j = 0;

    for (i = 0; i < NUM_ROWS; ++i) {
        for (j = 0; j < NUM_COLS; ++j) {
            if (milesTracker[i][j] > maxMiles) {
                maxMiles = milesTracker[i][j];
            }
            if (milesTracker[i][j] < minMiles) {
                minMiles = milesTracker[i][j];
            }
        }
    }

    cout << "Min miles: " << minMiles << endl;
    cout << "Max miles: " << maxMiles << endl;

    return 0;
}