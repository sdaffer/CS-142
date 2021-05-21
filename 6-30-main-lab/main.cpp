#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// Global variables
const int NUM_ELEMENTS = 10;

// Functions
// Function to output the entire array
void PrintHotplate(double paramArray[NUM_ELEMENTS][NUM_ELEMENTS]) {
    // Loop through each position i, j and output with 3 decimal places
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        cout << endl;
        for (int j = 0; j < NUM_ELEMENTS; ++j) {
            cout << fixed << setprecision(3) << setw(9) << paramArray[i][j];
            if (j < NUM_ELEMENTS - 1) {
                cout << ",";
            }
        }
    }
}

// Write hotplate to csv
void WriteHotplate(double paramArray[NUM_ELEMENTS][NUM_ELEMENTS]) {
    ofstream outFS;
    outFS.open("Hotplate.csv");

    if (!outFS.is_open()) {
        cout << "Could not open file Hotplate.csv" << endl;
        exit(1);
    }


    // Loop through each position i, j and output with 3 decimal places
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        outFS << endl;
        for (int j = 0; j < NUM_ELEMENTS; ++j) {
            outFS << fixed << setprecision(3) << setw(9) << paramArray[i][j];
            if (j < NUM_ELEMENTS - 1) {
                outFS << ",";
            }
        }
    }

    outFS.close();
}

void UpdateArray(double paramInitialArray[NUM_ELEMENTS][NUM_ELEMENTS], double paramUpdatedArray[NUM_ELEMENTS][NUM_ELEMENTS]) {
    // Calculate the average by looping through each row/column & ignoring borders
    for (int i = 1; i < NUM_ELEMENTS - 1; ++i) {
        for (int j = 1; j < NUM_ELEMENTS - 1; ++j) {
            paramUpdatedArray[i][j] = (paramInitialArray[i - 1][j] + paramInitialArray[i + 1][j] + paramInitialArray[i][j - 1] + paramInitialArray[i][j + 1]) / 4;
        }
    }
}

int main() {
    double initialArray[NUM_ELEMENTS][NUM_ELEMENTS];
    double newArray[NUM_ELEMENTS][NUM_ELEMENTS];
    bool continueLoop = true;
    ifstream inFS;
    ofstream outFS;

    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        for (int j = 0; j < NUM_ELEMENTS; ++j) {
            if ((i == 0 || i == NUM_ELEMENTS - 1) && j > 0 && j < NUM_ELEMENTS - 1) {
                initialArray[i][j] = 100.0;
                newArray[i][j] = 100.0;
            }
            else {
                initialArray[i][j] = 0.0;
                newArray[i][j] = 0.0;
            }
        }
    }

    cout << "Hotplate simulator" << endl << endl;

    // Output initial array
    cout << "Printing the initial plate values...";
    PrintHotplate(initialArray);

    // First update
    cout << endl << "Printing plate after one iteration...";
    UpdateArray(initialArray, newArray);
    PrintHotplate(newArray);

    // Loop through until different is < 0.1
    while (continueLoop) {
        continueLoop = false;
        UpdateArray(initialArray, newArray);

        // Verify temp change is stable
        for (int i = 1; i < NUM_ELEMENTS - 1; ++i) {
            for (int j = 1; j < NUM_ELEMENTS - 1; ++j) {
                if (fabs(initialArray[i][j] - newArray[i][j]) > 0.1) {
                    continueLoop = true;
                }
            }
        }

        // Updating initial array
        for (int i = 1; i < NUM_ELEMENTS - 1; ++i) {
            for (int j = 1; j < NUM_ELEMENTS - 1; ++j) {
                initialArray[i][j] = newArray[i][j];
            }
        }
    }

    cout << endl << endl;
    cout << "Printing final plate...";
    PrintHotplate(newArray);

    cout << endl << "Outputting final plate to file\"Hotplate.csv...\"" << endl << endl;
    WriteHotplate(newArray);


    cout << endl << "Printing input plate after 3 updates..." << endl;

    // Reading and initializing array from .txt
    inFS.open("Inputplate.txt");
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        for (int j = 0; j < NUM_ELEMENTS; ++j) {
            inFS >> initialArray[i][j];
            newArray[i][j] = initialArray[i][j];
        }
    }
    inFS.close();

    // Last three iterations with Inputplate.txt
    for (int x = 0; x < 3; ++x) {
        UpdateArray(initialArray, newArray);
        for (int i = 1; i < NUM_ELEMENTS - 1; ++i) {
            for (int j = 1; j < NUM_ELEMENTS - 1; ++j) {
                initialArray[i][j] = newArray[i][j];
            }
        }
    }

    PrintHotplate(initialArray);

    cout << endl;

    return 0;
}
