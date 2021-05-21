#include <iostream>
#include <string>
using namespace std;

int main() {
    string userInput;
    string outputText = "";
    cin >> userInput;

    // Set the value of separator based on user input
    string separator;
    if (userInput == "newline") {
        separator = '\n';
    } else if (userInput == "space") {
        separator = ' ';
    } else if (userInput == "tab") {
        separator = '\t';
    } else if (userInput == "null") {
        separator = '\0';
    }

    //TODO: create a variable named outputText
    //      that contains a formatted copy of
    //      the poem shown in the example output

    outputText = "Roses are red" + separator + "Violets are blue" + separator + "I like to write code" + separator + "I hope you do too.";
    cout << outputText;
    return 0;
}