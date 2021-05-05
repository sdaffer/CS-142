#include <iostream>
#include <vector>
using namespace std;


// Function prototypes
void outputVector(vector<double> inputVector);
double totalWeight(vector<double> inputVector);
double averageWeight(vector<double> inputVector);
double maxWeight(vector<double> inputVector);


// main()
int main() {

    // Variables
    const int NUM_WEIGHTS = 5;
    vector<double> peopleWeights(NUM_WEIGHTS);

    // Prompt user for input of the five weights
    for (int i = 0; i < peopleWeights.size(); ++i) {
        cout << "Enter weight " << i + 1 << ": ";
        cin >> peopleWeights.at(i);
        cout << endl;
    }

    cout << "You entered: ";
    outputVector(peopleWeights);
    cout << endl;

    cout << "Total weight: ";
    cout << totalWeight(peopleWeights);
    cout << endl;

    cout << "Average weight: ";
    cout << averageWeight(peopleWeights);
    cout << endl;

    cout << "Max weight: ";
    cout << maxWeight(peopleWeights);
    cout << endl;


    return 0;
}


// Functions
void outputVector(vector<double> inputVector) {

    for (int i = 0; i < inputVector.size(); ++i) {
        cout << inputVector.at(i) << " ";
    }

}

double totalWeight(vector<double> inputVector) {
    double returnedTotalWeight = 0.0;

    for (int i = 0; i < inputVector.size(); ++i) {
        returnedTotalWeight = returnedTotalWeight + inputVector.at(i);
    }

    return returnedTotalWeight;
}

double averageWeight(vector<double> inputVector) {
    double returnedAverageWeight = 0.0;
    double sumWeight = 0.0;

    for (int i = 0; i < inputVector.size(); ++i) {
        sumWeight = sumWeight + inputVector.at(i);
    }

    returnedAverageWeight = sumWeight / inputVector.size();

    return returnedAverageWeight;
}

double maxWeight(vector<double> inputVector) {
    double returnedMaxWeight = inputVector.at(0);

    for (int i = 0; i < inputVector.size(); ++i) {
        if (inputVector.at(i) >= returnedMaxWeight) {
            returnedMaxWeight = inputVector.at(i);
        }
    }

    return returnedMaxWeight;
}