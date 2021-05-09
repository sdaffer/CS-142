#include <iostream>
#include <string>
#include <iomanip> //TODO: Need to identify if this is actually needed before submitting
using namespace std;

// Class files
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

std::string GetUserString(const std::string& prompt);

void AddMenuOption(ShoppingCart& paramUserCart); //FIXME: Passby reference?
void RemoveMenuOption(ShoppingCart paramUserCart);
void ChangeMenuOption(ShoppingCart paramUserCart);
void DescriptionsMenuOption(ShoppingCart paramUserCart);
void CartMenuOption(ShoppingCart paramUserCart);
void OptionsMenuOption();
void QuitMenuOption();


int main() {
    std::string customerName = GetUserString("Enter Customer's Name: ");
    std::string todayDate = GetUserString("Enter Today's Date: ");

    //TODO: Create a shopping cart with the above information
    // .
    // This should be just one line of code that calls your ShoppingCart constructor
    ShoppingCart userShoppingCart(customerName, todayDate);

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter option: ");

        if (userMenuChoice == "add") {
            AddMenuOption(userShoppingCart);
        }
        else if (userMenuChoice == "remove") {
            RemoveMenuOption(userShoppingCart);
        }
        else if (userMenuChoice == "change") {
            ChangeMenuOption(userShoppingCart);
        }
        else if (userMenuChoice == "descriptions") {
            DescriptionsMenuOption(userShoppingCart);
        }
        else if (userMenuChoice == "cart") {
            CartMenuOption(userShoppingCart);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
double GetUserDouble(const std::string& prompt) {
    double userAnswer = 0.0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}


void AddMenuOption(ShoppingCart& paramUserCart) { //FIXME: This function is not working. Needs to be checked out.
    //FIXME: The test bed worked for the member class function, so there's something wrong in this function
    std::string itemName = GetUserString("Enter the item name: ");
    std::string itemDescription = GetUserString("Enter the item description: ");
    double itemPrice = GetUserDouble("Enter the item price: ");
    int itemQuantity = GetUserInt("Enter the item quantity: ");

    // TODO: You might also print error messages here, depending on how you implement the ShoppingCart class
    ItemToPurchase itemObject(itemName, itemDescription, itemPrice, itemQuantity);
    paramUserCart.AddItem(itemObject);
}

void RemoveMenuOption(ShoppingCart paramUserCart) {
    std::string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");

    //TODO: Remove the item from the shopping cart
    // .
    // This should be just 1 line of code to call the appropriate method on the shoppingCart
    // You might also print error messages here, depending on how you implement the ShoppingCart class
    paramUserCart.RemoveItem(nameOfItemToRemove);
}

void ChangeMenuOption(ShoppingCart paramUserCart) { //FIXME: This doesn't seem to be working either
    std::string nameOfItemToChange = GetUserString("Enter the item name: ");
    int newItemQuantity = GetUserInt("Enter the new quantity: ");

    // TODO: You might also print error messages here, depending on how you implement the ShoppingCart class
    paramUserCart.UpdateQuantity(nameOfItemToChange, newItemQuantity);
    paramUserCart.UpdateQuantity("test change", 1000);
}

void DescriptionsMenuOption(ShoppingCart paramUserCart) {
    //Print the information from the shopping cart
    paramUserCart.PrintEachDescription();
}

void CartMenuOption(ShoppingCart paramUserCart) {
    //Print the information from the shopping cart
    paramUserCart.PrintNumberAndCost();
}

void OptionsMenuOption() {
    std::cout << "MENU" << std::endl
              << "add - Add item to cart" << std::endl
              << "remove - Remove item from cart" << std::endl
              << "change - Change item quantity" << std::endl
              << "descriptions - Print the items' descriptions" << std::endl
              << "cart - Print the shopping cart" << std::endl
              << "options - Print the options menu" << std::endl
              << "quit - Quit" << std::endl << std::endl;
}

void QuitMenuOption() {
    std::cout << "Goodbye." << std::endl;
}