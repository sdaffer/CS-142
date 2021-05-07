#include <iostream>
#include "ItemToPurchase.h"

int main() {
    // Create two objects of ItemToPurchase class
    ItemToPurchase firstItem;
    ItemToPurchase secondItem;
    string currItemName = "";
    double currItemPrice = 0.0;
    double priceTotal = 0.0;
    int currItemQuantity = 0;

    /*Prompt user for two items and put them into both objects */
    // Item1
    cout << "Item 1" << endl;
    cout << "Enter the item name: ";
    getline(cin, currItemName);
    cout << "Enter the item price: ";
    cin >> currItemPrice;
    cout << "Enter the item quantity: ";
    cin >> currItemQuantity;

    firstItem.SetName(currItemName);
    firstItem.SetPrice(currItemPrice);
    firstItem.SetQuantity(currItemQuantity);

    // Item2
    cout << "Item 2" << endl;
    cout << "Enter the item name: ";
    getline(cin, currItemName);
    cout << "Enter the item price: ";
    cin >> currItemPrice;
    cout << "Enter the item quantity: ";
    cin >> currItemQuantity;
    cout << endl;

    secondItem.SetName(currItemName);
    secondItem.SetPrice(currItemPrice);
    secondItem.SetQuantity(currItemQuantity);

    /*Sum up total cost for both items and output*/
    // Item1
    cout << "TOTAL COST" << endl;
    cout << firstItem.GetName() << " " << firstItem.GetQuantity() << " @ $";
    cout << firstItem.GetPrice() << " = $";
    priceTotal = priceTotal + firstItem.GetPrice() * firstItem.GetQuantity();
    cout << priceTotal << endl;

    // Item2
    cout << secondItem.GetName() << " " << secondItem.GetQuantity() << " @ $";
    cout << secondItem.GetPrice() << " = $";
    priceTotal = priceTotal + secondItem.GetPrice() * secondItem.GetQuantity();
    cout << priceTotal << endl;

    cout << endl;
    cout << "Total: $" << priceTotal;

    return 0;
}