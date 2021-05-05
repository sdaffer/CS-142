#include <iostream>
#include <vector>
using namespace std;


// Function prototypes
void outputVector();
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
    }


    return 0;
}


// Functions
void outputVector() {

}

double totalWeight(vector<double> inputVector) {
    double returnedTotalWeight = 0.0;



    return returnedTotalWeight;
}

double averageWeight(vector<double> inputVector) {

}

double maxWeight(vector<double> inputVector) {

}