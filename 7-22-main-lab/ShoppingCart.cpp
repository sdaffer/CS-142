#include <iostream>
using namespace std;

#include "ShoppingCart.h"

// Constructors
// Constructor with no parameters
ShoppingCart::ShoppingCart() {
    customerName = "none";
    dateCreated = "January 1, 2016";
}
// Constructor with parameters
ShoppingCart::ShoppingCart(string paramCustomerName, string paramDateCreated) {
    customerName = paramCustomerName;
    dateCreated = paramDateCreated;
}


// Setters


// Getters