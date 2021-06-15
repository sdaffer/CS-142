#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void PrintVector(vector<int>& paramVector);
void ReverseVector(vector<int>& paramVector);

int main() {
    int vectorSize = 0;
    int multiplier = 0;

    // Get user input for the two variables
    cout << "Please enter the vector size:";
    cin >> vectorSize;
    cout << endl;
    cout << "Please enter the multiplier:";
    cin >> multiplier;
    cout << endl;

    // Declare the vector
    vector<int> userVector(vectorSize);

    // Fill the vector according to the instructions
    for (int i = 0; i < vectorSize; ++i) {
        userVector.at(i) = i * multiplier;
    }

    // Call the functions in the order the instructions indicated
    PrintVector(userVector);
    ReverseVector(userVector);
    PrintVector(userVector);

    return 0;
}

// Functions
void PrintVector(vector<int>& paramVector) {
    // Loop through and print the vector
    for (int i = 0; i < paramVector.size(); ++i) {
        cout << paramVector.at(i) << endl;
    }
}

void ReverseVector(vector<int>& paramVector) {
    // Declare/ initialize the holding variable
    int holdVal = 0;

    // Loop through vector and reverse the elements
    for (int i = 0; i < paramVector.size() / 2; ++i) {
        // The bound of the loop is half the size because both parts of the swap are completed when i = half the size
        holdVal = paramVector.at(i);
        paramVector.at(i) = paramVector.at(paramVector.size() - 1 - i);
        paramVector.at(paramVector.size() - 1 - i) = holdVal;
    }
}