#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

int main() {
    ShoppingCart testCart;
    ItemToPurchase testItem;
    ShoppingCart testCartParam("John Doe", "May 8, 2021");

    testItem.SetQuantity(10);
    testItem.SetDescription("Test description");
    testItem.SetPrice(1.50);
    testItem.SetName("Water bottle");


    // FIXME: Testbed for constructors of ShoppingCart class below
    // Default constructor test
    cout << "Beginning constructor tests." << endl;
    cout << "Default customer name: " << testCart.GetCustomerName() << endl;
    cout << "Default date created: " << testCart.GetDateCreated() << endl;
    // Change testCart of ShoppingCart class with parameters and see if parameter constructor works
    cout << "Param customer name: " << testCartParam.GetCustomerName() << endl;
    cout << "Param date created: " << testCartParam.GetDateCreated() << endl;
    cout << "End of constructor tests." << endl;


    // FIXME: Testbed for Setters and Getters and Printers below
    cout << "Beginning setters and getters and printers tests." << endl;
    cout << "Quantity of cart: " << testCartParam.GetQuantityCart() << endl;
    cout << "Total cost of cart: " << testCartParam.GetTotalCost() << endl;
    cout << "Print each description test." << endl;
    testCartParam.PrintEachDescription();
    cout << "Print each cost test." << endl;
    testCartParam.PrintNumberAndCost();

    cout << "Now testing add item function" << endl;
    testCartParam.AddItem(testItem);

    cout << "Redoing getters to see if add item function worked." << endl;
    cout << "Quantity of cart: " << testCartParam.GetQuantityCart() << endl;
    cout << "Total cost of cart: " << testCartParam.GetTotalCost() << endl;
    cout << "Print each description test." << endl;
    testCartParam.PrintEachDescription();
    cout << "Print each cost test." << endl;
    testCartParam.PrintNumberAndCost();

    cout << "Now testing update quantity function" << endl;
    testCartParam.UpdateQuantity("Water bottle");

    cout << "Redoing getters to see if update quantity function worked." << endl;
    cout << "Quantity of cart: " << testCartParam.GetQuantityCart() << endl;
    cout << "Total cost of cart: " << testCartParam.GetTotalCost() << endl;
    cout << "Print each description test." << endl;
    testCartParam.PrintEachDescription();
    cout << "Print each cost test." << endl;
    testCartParam.PrintNumberAndCost();

    cout << "Now testing remove item function" << endl;
    testCartParam.RemoveItem("Water bottle");

    cout << "Redoing getters to see if remove item function worked." << endl;
    cout << "Quantity of cart: " << testCartParam.GetQuantityCart() << endl;
    cout << "Total cost of cart: " << testCartParam.GetTotalCost() << endl;
    cout << "Print each description test." << endl;
    testCartParam.PrintEachDescription();
    cout << "Print each cost test." << endl;
    testCartParam.PrintNumberAndCost();


    cout << "End of setters and getters and printers tests." << endl;

    return 0;
}