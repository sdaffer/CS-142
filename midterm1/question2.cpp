#include <iostream>
using namespace std;

// Function prototypes
double CalculateDrinkCost(int paramNumDrinks, double paramCostPerDrink);
void CalculatePackaging(int paramNumDrinks, int paramNumDrinksPerTray, int &paramNumTrays, int &paramNumExtraDrinks);


// Main function
int main(){
    int userNumDrinks = 0.0;
    const int NUM_DRINKS_PER_TRAY = 4;
    int numTrays = 0;
    int numExtraDrinks = 0;
    double costPerDrink = 0.85;
    double totalCost = 0.0;

    // Get user input for total number of drinks
    cin >> userNumDrinks;

    // Calculate total cost and packaging and assign those values to variables
    totalCost = CalculateDrinkCost(userNumDrinks, costPerDrink);
    CalculatePackaging(userNumDrinks, NUM_DRINKS_PER_TRAY, numTrays, numExtraDrinks);

    // Output calculations with formatting
    cout << "Total number of drinks: " << userNumDrinks << endl;
    cout << "Number of full trays: " << numTrays << endl;
    cout << "Number of extra drinks: " << numExtraDrinks << endl;
    cout << "Total cost of the drink order: $" << totalCost << endl;

    return 0;
}


// Functions
double CalculateDrinkCost(int paramNumDrinks, double paramCostPerDrink) {
    double totalCost = 0.0;
    totalCost = paramNumDrinks * paramCostPerDrink;
    return totalCost;
}
void CalculatePackaging(int paramNumDrinks, int paramNumDrinksPerTray, int &paramNumTrays, int &paramNumExtraDrinks) {
    int numTrays = 0;

    // Performing integer division to drop the decimal - we only want the whole number.
    numTrays = paramNumDrinks / paramNumDrinksPerTray;
    paramNumTrays = numTrays;

    paramNumExtraDrinks = paramNumDrinks - (numTrays * paramNumDrinksPerTray);
}