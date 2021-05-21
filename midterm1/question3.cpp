#include <iostream>
#include <string>
using namespace std;

int main() {

    string userInput = "";
    cin >> userInput;

    // Find the required letters and replace them with their corresponding symbols
    // Using a while loop to find more than one occurrence (if it exists) of the letter
    while (userInput.find('i') != string::npos) {
        userInput.replace(userInput.find('i'), 1, "!");
    }
    while (userInput.find('a') != string::npos) {
        userInput.replace(userInput.find('a'), 1, "@");
    }
    while (userInput.find('l') != string::npos) {
        userInput.replace(userInput.find('l'), 1, "1");
    }
    while (userInput.find('B') != string::npos) {
        userInput.replace(userInput.find('B'), 1, "8");
    }
    while (userInput.find('E') != string::npos) {
        userInput.replace(userInput.find('E'), 1, "3");
    }
    while (userInput.find('t') != string::npos) {
        userInput.replace(userInput.find('t'), 1, "7");
    }
    while (userInput.find('s') != string::npos) {
        userInput.replace(userInput.find('s'), 1, "$");
    }
    while (userInput.find('o') != string::npos) {
        userInput.replace(userInput.find('o'), 1, "0");
    }

    // Append ^k to the end of the string
    userInput = userInput + "z^k";

    // Output the string
    cout << userInput << endl;
    return 0;
}
