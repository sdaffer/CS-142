#include <iostream>
#include <string>
using namespace std;

// Class files
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

std::string GetUserString(const std::string& prompt);

void AddMenuOption(ShoppingCart& paramUserCart);
void RemoveMenuOption(ShoppingCart& paramUserCart);
void ChangeMenuOption(ShoppingCart& paramUserCart);
void DescriptionsMenuOption(ShoppingCart paramUserCart);
void CartMenuOption(ShoppingCart paramUserCart);
void OptionsMenuOption();
void QuitMenuOption();


int main() {

    std::string customerName = GetUserString("Enter Customer's Name: ");
    std::string todayDate = GetUserString("Enter Today's Date: ");

    // Creating shopping cart with the above information
    ShoppingCart userShoppingCart(customerName, todayDate);

    std::string userMenuChoice = "none";

    // Menu selection loop
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


string GetUserString(const std::string& prompt) {
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


void AddMenuOption(ShoppingCart& paramUserCart) {
    std::string itemName = GetUserString("Enter the item name: ");
    std::string itemDescription = GetUserString("Enter the item description: ");
    double itemPrice = GetUserDouble("Enter the item price: ");
    int itemQuantity = GetUserInt("Enter the item quantity: ");

    ItemToPurchase itemObject(itemName, itemDescription, itemPrice, itemQuantity);
    paramUserCart.AddItem(itemObject);
}

void RemoveMenuOption(ShoppingCart& paramUserCart) {
    std::string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");

    paramUserCart.RemoveItem(nameOfItemToRemove);
}

void ChangeMenuOption(ShoppingCart& paramUserCart) {
    std::string nameOfItemToChange = GetUserString("Enter the item name: ");
    int newItemQuantity = GetUserInt("Enter the new quantity: ");

    paramUserCart.UpdateQuantity(nameOfItemToChange, newItemQuantity);
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