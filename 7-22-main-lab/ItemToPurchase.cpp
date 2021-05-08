#include <iostream>
#include <iomanip>
using namespace std;

#include "ItemToPurchase.h"


// Default constructor FIXME: Moved constructor to beginning of class. Does this work? Make sure to test.
ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}


// Setters
void ItemToPurchase::SetName(string nameParam) {
    itemName = nameParam;
}
void ItemToPurchase::SetPrice(double priceParam) {
    itemPrice = priceParam;
}
void ItemToPurchase::SetQuantity(int quantityParam) {
    itemQuantity = quantityParam;
}
void ItemToPurchase::SetDescription(string descriptionParam) {
    itemDescription = descriptionParam;
}

// Getters
string ItemToPurchase::GetName()  const {return itemName;}
string ItemToPurchase::GetDescription() const {return itemDescription;}
double ItemToPurchase::GetPrice() const {return itemPrice;}
int ItemToPurchase::GetQuantity() const {return itemQuantity;}


// Printers
/* Below are the printer functions that need a parameter. I will try to do it without a parameter with the ones below these
void ItemToPurchase::PrintCostItem(ItemToPurchase itemObject) const { //FIXME: Is const needed here? I don't think I'm modifying the object
    double itemSubTotal = 0.0;

    // Set precision to display two decimal points in standard dollar form

    cout << fixed << setprecision(2);

    // Output cost in format according to instructions
    cout << itemObject.GetName() << " " << itemObject.GetQuantity() << " @ $";
    cout << itemObject.GetPrice() << " = $";
    itemSubTotal = itemObject.GetPrice() * itemObject.GetQuantity();
    cout << itemSubTotal << endl;
}
void ItemToPurchase::PrintDescriptionItem(ItemToPurchase itemObject) const { //FIXME: Is const needed here? I don't think I'm modifying the object
    cout << itemObject.GetName() << ": " << itemObject.GetDescription() << ".";
}
*/
void ItemToPurchase::PrintCostItem() const { //FIXME: Is const needed here? I don't think I'm modifying the object
    double itemSubTotal = 0.0;

    // Set precision to display two decimal points in standard dollar form

    cout << fixed << setprecision(2);

    // Output cost in format according to instructions
    cout << itemName << " " << itemQuantity << " @ $";
    cout << itemPrice << " = $";
    itemSubTotal = itemPrice * itemQuantity;
    cout << itemSubTotal << endl;
}
void ItemToPurchase::PrintDescriptionItem() const { //FIXME: Is const needed here? I don't think I'm modifying the object
    cout << itemName << ": " << itemDescription << ".";
}