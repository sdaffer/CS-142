#ifndef INC_7_22_MAIN_LAB_SHOPPINGCART_H
#define INC_7_22_MAIN_LAB_SHOPPINGCART_H
#include <iostream>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

/*Shopping cart class*/
class ShoppingCart {
public:
    // Constructors
    ShoppingCart(string paramCustomerName, string paramDateCreated); // Prototype constructor with parameters
    ShoppingCart(); // Prototype default constructor with no parameters

    // Setters
    void AddItem(ItemToPurchase paramItem);
    void RemoveItem(string paramItemName);
    void UpdateQuantity(string paramItemName);

    // Getters
    string GetCustomerName() const;
    string GetDateCreated() const;
    int GetQuantityCart() const;
    double GetTotalCost() const;

    // Printers
    void PrintEachDescription() const;
    void PrintNumberAndCost() const;

private:
    string customerName;
    string dateCreated; // FIXME: Is string datatype the best way to do this?
    vector<ItemToPurchase> itemList;
};


#endif //INC_7_22_MAIN_LAB_SHOPPINGCART_H
