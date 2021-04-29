#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Variables and constants and constraints
    const double PI = 3.14159265;
    const double LARGE_PIZZA_PRICE = 15.78;
    const double MEDIUM_PIZZA_PRICE = 13.25;
    const double SMALL_PIZZA_PRICE = 8.39;

    // I've made the radius of the pizzas doubles in order to get a double out of the area calculation.
    const double LARGE_PIZZA_RADIUS = 24.0 / 2.0;
    const double MEDIUM_PIZZA_RADIUS = 18.0 / 2.0;
    const double SMALL_PIZZA_RADIUS = 14.0 / 2.0;

    const int LARGE_PIZZA_PEOPLE_FED = 9;
    const int MEDIUM_PIZZA_PEOPLE_FED = 5;
    // Number of pizzas that the small pizza feeds is a double because I need to round up from a decimal to make sure every person is fed.
    const double SMALL_PIZZA_PEOPLE_FED = 2.0;

    int numGuests = 0;
    int numGuestsToBeFed;

    int numLargePizzas;
    int numMediumPizzas;
    // Small pizzas is a double because I need to round a decimal to make sure every person is fed.
    double numSmallPizzas;

    double areaLargePizza;
    double areaMediumPizza;
    double areaSmallPizza;
    double areaTotal;
    double areaPerGuest;

    double numTip = 0.0;
    double totalCost;


    // Output prompt for user to enter how many guests and input for variable
    cout << "Please enter how many guests to order for: ";
    cin >> numGuests;
    cout << endl;


    // Calculation of how many large, medium and small pizza's needed
    // I'm using integer division to drop the decimal to the largest whole number of large and medium pizzas that can be used. Small pizzas will be rounded up.
    numLargePizzas = numGuests / LARGE_PIZZA_PEOPLE_FED;
    numGuestsToBeFed = numGuests - (numLargePizzas * LARGE_PIZZA_PEOPLE_FED);
    numMediumPizzas = numGuestsToBeFed / MEDIUM_PIZZA_PEOPLE_FED;
    numGuestsToBeFed = numGuestsToBeFed - (numMediumPizzas * MEDIUM_PIZZA_PEOPLE_FED);
    // Round down to next whole number for small pizzas. Assuming we can't order a fraction of a pizza.
    numSmallPizzas = floor(numGuestsToBeFed / SMALL_PIZZA_PEOPLE_FED);


    // Output for number of different pizzas
    cout << numLargePizzas << " large pizzas, " << numMediumPizzas << " medium pizzas, and " << numSmallPizzas << " small pizzas will be needed.";
    cout << endl << endl;


    // Area calculation
    areaLargePizza = numLargePizzas * (PI * (LARGE_PIZZA_RADIUS * LARGE_PIZZA_RADIUS));
    areaMediumPizza = numMediumPizzas * (PI * (MEDIUM_PIZZA_RADIUS * MEDIUM_PIZZA_RADIUS));
    areaSmallPizza = numSmallPizzas * (PI * (SMALL_PIZZA_RADIUS * SMALL_PIZZA_RADIUS));
    areaTotal = areaLargePizza + areaMediumPizza + areaSmallPizza;
    areaPerGuest = areaTotal / numGuests;


    // Total area output
    cout << "A total of " << areaTotal << " square inches of pizza will be ordered (" << areaPerGuest << " per guest).";
    cout << endl << endl;


    // Tip prompt
    cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";
    cin >> numTip;
    cout << endl;


    // Tip and total cost calculation
    numTip = numTip / 100; // Convert tip to proper decimal from percentage
    totalCost = ((numLargePizzas * LARGE_PIZZA_PRICE) + (numMediumPizzas * MEDIUM_PIZZA_PRICE) + (numSmallPizzas * SMALL_PIZZA_PRICE)) * (1 + numTip);
    // The tests on zyBooks all round to the nearest dollar, so that is done below.
    totalCost = round(totalCost);


    // Total cost output
    cout << "The total cost of the event will be: $" << totalCost << endl;


    return 0;
}
