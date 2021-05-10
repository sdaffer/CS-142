#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

// Constructors
// Constructor with no parameters
ShoppingCart::ShoppingCart() {
    customerName = "none";
    dateCreated = "January 1, 2016";
    itemList.resize(0);
}
// Constructor with parameters
ShoppingCart::ShoppingCart(string paramCustomerName, string paramDateCreated) {
    customerName = paramCustomerName;
    dateCreated = paramDateCreated;
}


// Setters
void ShoppingCart::AddItem(ItemToPurchase paramItem) {
    // Escape helper is my way of making sure that the item is added only once when the appropriate conditions are met
    int escapeHelper = 0;

    //itemList.push_back(paramItem);
    // Loop through itemList vector. If the item is already found, output that it is already found. Otherwise, add it
    if (itemList.empty()) {
        itemList.push_back(paramItem);
        escapeHelper = 1;
    }
    else {
        for (int i = 0; i < itemList.size(); ++i) {
            if ((itemList.at(i).GetName() == paramItem.GetName())) {
                cout << "Item is already found in the cart. It will not be added." << endl;
                escapeHelper = 1;
            }
        }
    }

    if (escapeHelper == 0) {
        itemList.push_back(paramItem);
        escapeHelper = 1;
    }
}
void ShoppingCart::RemoveItem(string paramItemName) {
    bool itemFound = false;

    // Loop through itemList vector. If the item not found, output that it won't be removed. Otherwise, remove it. Similar to add item function
    for (int i = 0; i < itemList.size(); ++i) {
        if (itemList.at(i).GetName() == paramItemName) {
            // If found, remove it at the current index
            itemList.erase(itemList.begin() + i);
            // Update itemFound bool to skip over last if statement
            itemFound = true;
        }
    }

    if (itemFound == false) {
        cout << "Item not found in cart. It will not be removed." << endl;
    }
}
void ShoppingCart::UpdateQuantity(string paramItemName, int paramQuantity) {
    bool itemFound = false;

    // Loop through itemList vector. If item not found, output that it won't be modified. Otherwise, modify it. Similar to add and remove functions
    for (int i = 0; i < itemList.size(); ++i) {
        if (itemList.at(i).GetName() == paramItemName) {
            // If found, update quantity at current index
            itemList.at(i).SetQuantity(paramQuantity);
            // Update itemFound bool to skip over last if statement
            itemFound = true;
        }
    }

    if (itemFound == false) {
        cout << "Item not found in cart. It will not be modified." << endl;
    }
}


// Getters
string ShoppingCart::GetCustomerName() const {
    return customerName;
}
string ShoppingCart::GetDateCreated() const {return dateCreated;}
int ShoppingCart::GetQuantityCart() const {return itemList.size();}
double ShoppingCart::GetTotalCost() const {
    double totalCost = 0.0;

    // Loop through the itemList vector and add up all the prices using the get price function
    for (int i = 0; i < itemList.size(); ++i) {
        totalCost = totalCost + itemList.at(i).GetPrice();
    }

    return totalCost;
}


// Printers
void ShoppingCart::PrintEachDescription() const {
    // Display customer name and date always - even if the cart is empty
    cout << customerName << "'s Shopping Cart - " << dateCreated << endl;

    // If shopping cart is empty, output so. Otherwise, loop through and print each description
    if (itemList.empty()) {
        cout << "Shopping cart is empty." << endl;
        cout << endl;
    }
    else {
        cout << endl;
        cout << "Item Descriptions" << endl;
        for (int i = 0; i < itemList.size(); ++i) {
            cout << itemList.at(i).GetName() << ": " << itemList.at(i).GetDescription() << endl;
        }
    }
}
void ShoppingCart::PrintNumberAndCost() const {
    double totalCost = 0.0;
    int numItems = 0;
    bool emptyCart = false;

    // Loop through to find total number of items and update that value
    for (int i = 0; i < itemList.size(); ++i) {
        numItems = numItems + itemList.at(i).GetQuantity();
    }

    // Output cart, name, date, and total number of items
    cout << customerName << "'s Shopping Cart - " << dateCreated << endl;


    // If shopping cart is empty, output so. Otherwise, output number of items, subtotals and total
    if (itemList.empty()) {
        cout << "Shopping cart is empty." << endl;
        cout << endl;
        emptyCart = true;
    }
    else {
        // Output the number of items beneath name and date
        cout << "Number of items: " << numItems << endl;
        cout << endl;

        // Loop through and use Item member function to print costs and update total cost
        for (int i = 0; i < itemList.size(); ++i) {
            itemList.at(i).PrintCostItem();
            totalCost = totalCost + (itemList.at(i).GetPrice() * itemList.at(i).GetQuantity());
        }
    }
    // If cart IS NOT empty, output total cost - set precision for standard dollar form
    if (!emptyCart) {
        cout << fixed << setprecision(2);
        cout << "Total: $" << totalCost << endl;
    }
}