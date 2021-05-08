#ifndef INC_7_21_PREP_LAB_ITEMTOPURCHASE_H
#define INC_7_21_PREP_LAB_ITEMTOPURCHASE_H
#include <iostream>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase(); // Default constructor
    ItemToPurchase(string paramItemName, string paramItemDescription, double paramItemPrice, int paramItemQuantity); // Parameter constructor
    void SetName(string nameParam);
    string GetName() const;
    void SetPrice(double priceParam);
    double GetPrice() const;
    void SetQuantity(int quantityParam);
    int GetQuantity() const;
    void SetDescription(string descriptionParam);
    string GetDescription() const;
    // Below are the printer functions that need a parameter. I will try to do it without a parameter with the ones below these
    //void PrintCostItem(ItemToPurchase itemObject) const;
    //void PrintDescriptionItem(ItemToPurchase itemObject) const;
    // Printer functions without the need of a parameter
    void PrintCostItem() const;
    void PrintDescriptionItem() const;

private:
    string itemName;
    string itemDescription;
    double itemPrice;
    int itemQuantity;
};


#endif //INC_7_21_PREP_LAB_ITEMTOPURCHASE_H