#include <iostream>
#include <string>
using namespace std;

int main() {

    // Declare variables
    string userInput;


    // Input prompt
    cout << "Input an abbreviation: ";
    cin >> userInput;
    cout << endl;


    // Branches
    if (userInput == "LOL") {
        cout << "laughing out loud" << endl;
    }
    else if (userInput == "BFF") {
        cout << "best friends forever" << endl;
    }
    else if (userInput == "IDK") {
        cout << "I don't know" << endl;
    }
    else if (userInput == "IMHO") {
        cout << "in my humble opinion" << endl;
    }
    else if (userInput == "TMI") {
        cout << "too much information" << endl;
    }
    else {
        cout << "Unknown" << endl;
    }


    return 0;
}