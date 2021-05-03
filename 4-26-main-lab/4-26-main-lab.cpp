// Libraries
#include <iostream>

using namespace std;

// Function prototypes
int PromptHandler(string strPrompt, int optionsAvailable);

int main() {
    // Declare variables


    // A very real warning before we begin
    cout << "CAUTION: I am spectacularly average at chess. Anyone who really knows about the game and plays this adventure will probably laugh at my incompetence." << endl;
    cout << "That's okay, just a warning." << endl;

    cout << PromptHandler("This is the prompt: ", 0);

    return 0;
}

// Function to handle printing a prompt, getting user input, and return user input at the end of the function
int PromptHandler(string strPrompt, int optionsAvailable){
    int userInput;
    cout << "Please enter a number for your input only." << endl;
    cout << strPrompt;
    cin >> userInput;
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again." << endl;
        // cout << strPrompt;
        // cin >> userInput;
        PromptHandler(strPrompt, optionsAvailable);
    }

    // Making sure only the number of available options will be used


    return userInput;
}