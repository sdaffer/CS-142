#include <iostream>
using namespace std;

#include "ItemToPurchase.h"


void ItemToPurchase::SetName(string nameParam) {
    itemName = nameParam;
}
void ItemToPurchase::SetPrice(double priceParam) {
    itemPrice = priceParam;
}
void ItemToPurchase::SetQuantity(int quantityParam) {
    itemQuantity = quantityParam;
}

string ItemToPurchase::GetName()  const {return itemName;}
double ItemToPurchase::GetPrice() const {return itemPrice;}
int ItemToPurchase::GetQuantity() const {return itemQuantity;}


// Default constructor
ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}