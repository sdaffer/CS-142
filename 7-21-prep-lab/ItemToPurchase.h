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
        ItemToPurchase(); // Prototype default constructor
    private:
        string itemName;
        double itemPrice;
        int itemQuantity;
};


#endif //INC_7_21_PREP_LAB_ITEMTOPURCHASE_H