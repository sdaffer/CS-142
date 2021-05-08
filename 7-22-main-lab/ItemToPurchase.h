#ifndef INC_7_21_PREP_LAB_ITEMTOPURCHASE_H
#define INC_7_21_PREP_LAB_ITEMTOPURCHASE_H
#include <iostream>
using namespace std;

class ItemToPurchase {
public:
    void SetName(string nameParam);
    string GetName() const;
    void SetPrice(double priceParam);
    double GetPrice() const;
    void SetQuantity(int quantityParam);
    int GetQuantity() const;
    void SetDescription(string descriptionParam);
    string GetDescription() const;
    void PrintCostItem(ItemToPurchase itemObject) const;
    void PrintDescriptionItem(ItemToPurchase itemObject) const;
    ItemToPurchase(); // Prototype default constructor
private:
    string itemName;
    string itemDescription;
    double itemPrice;
    int itemQuantity;
};


#endif //INC_7_21_PREP_LAB_ITEMTOPURCHASE_H