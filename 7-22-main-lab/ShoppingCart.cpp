#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

// Constructors
// Constructor with no parameters
ShoppingCart::ShoppingCart() {
    customerName = "none";
    dateCreated = "January 1, 2016";
    itemList.resize(0); //FIXME: I added this because I wasn't sure if I needed the vector to begin with a defined size 0
}
// Constructor with parameters
ShoppingCart::ShoppingCart(string paramCustomerName, string paramDateCreated) {
    customerName = paramCustomerName;
    dateCreated = paramDateCreated;
}


// Setters
void ShoppingCart::AddItem(ItemToPurchase paramItem) { //FIXME: This function is not working. Needs to be checked out.
    // Escape helper is my way of making sure that the item is added only once when the appropriate conditions are met
    int escapeHelper = 0;

    //itemList.push_back(paramItem);
    // Loop through itemList vector. If the item is already found, output that it is already found. Otherwise, add it
    if (itemList.size() == 0) {
        itemList.push_back(paramItem);
        escapeHelper = escapeHelper + 1;
    }
    else {
        for (int i = 0; i < itemList.size(); ++i) {
            if (itemList.at(i).GetName() == paramItem.GetName()) {
                cout << "Item is already found in the cart. It will not be added." << endl;
            }
            else {
                escapeHelper = escapeHelper + 1;
            }
        }
    }
    if (escapeHelper == 0) {
        itemList.push_back(paramItem);
    }
}
void ShoppingCart::RemoveItem(string paramItemName) {
    // Loop through itemList vector. If the item not found, output that it won't be removed. Otherwise, remove it. Similar to add item function
    for (int i = 0; i < itemList.size(); ++i) {
        if (itemList.at(i).GetName() == paramItemName) {
            // If found, remove it at the current index
            itemList.erase(itemList.begin() + i);
        }
        else {
            cout << "Item not found in cart. It will not be removed." << endl;
        }
    }
}
void ShoppingCart::UpdateQuantity(string paramItemName, int paramQuantity) {
    // Loop through itemList vector. If item not found, output that it won't be modified. Otherwise, modify it. Similar to add and remove functions
    for (int i = 0; i < itemList.size(); ++i) {
        if (itemList.at(i).GetName() == paramItemName) {
            // If found, update quantity at current index
            itemList.at(i).SetQuantity(paramQuantity);
        }
        else {
            cout << "Item not found in cart. It will not be modified." << endl;
        }
    }
}


// Getters
string ShoppingCart::GetCustomerName() const {return customerName;}
string ShoppingCart::GetDateCreated() const {return dateCreated;}
int ShoppingCart::GetQuantityCart() const {return itemList.size();} //FIXME: Is this the correct return?
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
    // If shopping cart is empty, output so. Otherwise, loop through and print each description

    if (itemList.empty()) {
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << customerName << "'s Shopping Cart - " << dateCreated << endl;
        cout << endl;
        cout << "Item Descriptions" << endl;
        for (int i = 0; i < itemList.size(); ++i) {
            cout << itemList.at(i).GetName() << ": " << itemList.at(i).GetDescription() << endl;
        }
    }
}
void ShoppingCart::PrintNumberAndCost() const {
    double totalCost = 0.0;

    // If shopping cart is empty, output so. Otherwise, output number of items, subtotals and total
    if (itemList.empty()) {
        cout << "Shopping cart is empty." << endl;
    }
    else {
        // Loop through and use Item member function to print costs and update total cost
        for (int i = 0; i < itemList.size(); ++i) {
            itemList.at(i).PrintCostItem();
            totalCost = totalCost + (itemList.at(i).GetPrice() * itemList.at(i).GetQuantity());
        }
    }
    // Output total cost - set precision for standard dollar form
    cout << fixed << setprecision(2);
    cout << "Total: $" << totalCost << endl;
}