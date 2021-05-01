#include <iostream>
#include <string>
using namespace std;

int main() {

    // Variables
    string userInput = "";
    string expandedInput = "";

    // Input prompt;
    cout << "Enter text: ";

    // User input;
    getline(cin, userInput); // Don't know if I will use this function for user input
    cout << endl;

    // Display user input
    cout << "You entered: " << userInput << endl;

    // Search string with find() and print meanings
    if (userInput.find("BFF") != string::npos){
        expandedInput = userInput.replace(userInput.find("BFF"), 3, "best friend forever");
    }
    if (userInput.find("IDK") != string::npos){
        expandedInput = userInput.replace(userInput.find("IDK"), 3, "I don't know");
    }
    if (userInput.find("JK") != string::npos){
        expandedInput = userInput.replace(userInput.find("JK"), 2, "just kidding");
    }
    if (userInput.find("TMI") != string::npos){
        expandedInput = userInput.replace(userInput.find("TMI"), 3, "too much information");
    }
    if (userInput.find("TTYL") != string::npos){
        expandedInput = userInput.replace(userInput.find("TTYL"), 4, "talk to you later");
    }


    // Output expanded version
    cout << "Expanded: " << expandedInput << endl;
    return 0;

}