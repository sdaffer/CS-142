#include <iostream>
#include <string>
using namespace std;

int main() {

    // Variables
    string userInput;

    // Input prompt;
    cout << "Enter text: ";

    // User input;
    getline(cin, userInput);

    // Display user input
    cout << "You entered: " << userInput << endl;
    return 0;
}