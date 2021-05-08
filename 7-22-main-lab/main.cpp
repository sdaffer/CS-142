#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"

int main() {
    // Create two objects of ItemToPurchase class
    ItemToPurchase firstItem;
    ItemToPurchase secondItem;
    string currItemName = "";
    double currItemPrice = 0.0;
    double priceTotal = 0.0;
    double firstPriceSubTotal = 0.0;
    double secondPriceSubTotal = 0.0;
    int currItemQuantity = 0;

    /*Prompt user for two items and put them into both objects */
    // Item1
    cout << "Item 1" << endl;
    cout << "Enter the item name: ";
    getline(cin, currItemName);
    //cin >> currItemName;
    cout << endl;
    cout << "Enter the item price: ";
    cin >> currItemPrice;
    cout << endl;
    cout << "Enter the item quantity: ";
    cin >> currItemQuantity;
    cout << endl << endl;

    firstItem.SetName(currItemName);
    firstItem.SetPrice(currItemPrice);
    firstItem.SetQuantity(currItemQuantity);

    // Item2
    cout << "Item 2" << endl;
    cout << "Enter the item name: ";
    cin.ignore();
    getline(cin, currItemName);
    //cin >> secondItemName;
    cout << endl;
    cout << "Enter the item price: ";
    cin >> currItemPrice;
    cout << endl;
    cout << "Enter the item quantity: ";
    cin >> currItemQuantity;
    cout << endl;
    cout << endl;

    secondItem.SetName(currItemName);
    secondItem.SetPrice(currItemPrice);
    secondItem.SetQuantity(currItemQuantity);

    // Set precision for correct output
    cout << fixed << setprecision(2);

    /*Sum up total cost for both items and output*/
    // Item1
    cout << "TOTAL COST" << endl;
    cout << firstItem.GetName() << " " << firstItem.GetQuantity() << " @ $";
    cout << firstItem.GetPrice() << " = $";
    firstPriceSubTotal = firstItem.GetPrice() * firstItem.GetQuantity();
    cout << firstPriceSubTotal << endl;

    // Item2
    cout << secondItem.GetName() << " " << secondItem.GetQuantity() << " @ $";
    cout << secondItem.GetPrice() << " = $";
    secondPriceSubTotal = secondItem.GetPrice() * secondItem.GetQuantity();
    cout << secondPriceSubTotal << endl;

    cout << endl;
    priceTotal = firstPriceSubTotal + secondPriceSubTotal;
    cout << "Total: $" << priceTotal;

    return 0;
}