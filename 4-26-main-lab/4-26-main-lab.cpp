// Libraries
#include <iostream>
using namespace std;


// Function prototypes
int PromptHandler(string strPrompt, int optionsAvailable);
int CaroKannBegins();
int SafeResponse();
int AggressiveCheck();
int DevelopSafeResponse();


// Main function
int main() {
    // Declare variables
    int userInputReturn;

    // A very real warning before we begin
    cout << "CAUTION: I am spectacularly average at chess. Anyone who really knows about the game and plays this adventure will probably laugh at my incompetence." << endl;
    cout << "That's okay, just a warning." << endl;


    // Begin the game the same way each time
    cout << "You're playing a nice game of chess. Your opponent, playing white, plays e4. ";
    userInputReturn = PromptHandler("Do you 1) play c6; 2) play e5? ", 2);


    // Caro-Kann defense response
    if (userInputReturn == 1) {
        userInputReturn = CaroKannBegins();
        if (userInputReturn == 1) {
            cout << "You play d5." << endl;
            cout << "Out of nowhere the sprinkler system rains water on you and your opponent. " << endl;
            cout << "A fire has started in the building and you both run to safety. " << endl;
            cout << "The end." << endl;
            exit(0);
        }
        if (userInputReturn == 2) {
            cout << "You abandon ship and resign. Good choice because you forgot the next moves to make." << endl;
            cout << "The end." << endl;
            exit(0);
        }
        // Aggressive check line
        if (userInputReturn == 3) {
            userInputReturn = AggressiveCheck();
            if (userInputReturn == 1) {
                cout << "Your opponent flips the board in anger and quits. You win!" << endl;
                cout << "The end." << endl;
                exit(0);
            }
            if (userInputReturn == 2) {
                cout << "You realize you've blundered your queen. No one can save you." << endl;
                cout << "Miraculously, your opponent gets a call and leaves. You actually win!" << endl;
                cout << "The end." << endl;
                exit(0);
            }
        }
    }


    // The safe response line
    if (userInputReturn == 2) {
        userInputReturn = SafeResponse();
        if (userInputReturn == 1) {
            cout << "You play f5." << endl;
            cout << "Nxe5. You lost a pawn." << endl;
            cout << "You get mad, flip the board and quit forever. You lose." << endl;
            cout << "The end." << endl;
            exit(0);
        }
        // Developing safe response line
        if (userInputReturn == 2) {
            userInputReturn = DevelopSafeResponse();
            if (userInputReturn == 1) {
                cout << "You play Be7." << endl;
                cout << "Your opponent plays Nh4." << endl;
                cout << "You play Bxe4." << endl;
                cout << "Your opponent gracefully resigns because he knows that he's lost." << endl;
                cout << "The end." << endl;
                exit(0);
            }
            if (userInputReturn == 2) {
                cout << "You develop Bc5." << endl;
                cout << "Your opponent laughs at you." << endl;
                cout << "You cry inside a little. And that's the last interesting move of the game." << endl;
                cout << "The end." << endl;
                exit(0);
            }
        }
    }
    return 0;
}

// Function to handle printing a prompt, getting user input, and return user input at the end of the function
int PromptHandler(string strPrompt, int optionsAvailable) {
    int userInput;
    cout << "Please enter an integer for your input." << endl;
    cout << strPrompt;
    cin >> userInput;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again." << endl;
        // Call the PromptHandler to try the process again.
        userInput = PromptHandler(strPrompt, optionsAvailable);
    }

    // Making sure the user inputs in the right range
    if ((userInput <= 0) || (userInput > optionsAvailable)) {
        cout << "Input is outside of the correct range of choices. Try again." << endl;
        // Call the PromptHandler to try the process again.
        userInput = PromptHandler(strPrompt, optionsAvailable);
    }
    return userInput;
}

// Functions to call in main() that make main() easier to read
int CaroKannBegins() {
    int userInput;
    cout << "You decide to play your prepared Caro-Kann defense, hoping you remember the right moves." << endl;
    cout << "Your opponent plays the classic response, d4." << endl;
    userInput = PromptHandler("Do you respond with 1) the next Caro-Kann move, d5; 2) abandon ship and resign; 3) change course and give an aggressive check with Qa5? ", 3);
    return userInput;
}

int SafeResponse() {
    int userInput;
    cout << "You play it safe with King's Pawn, e5." << endl;
    cout << "Your opponent attacks e5 with Nf3." << endl;
    userInput = PromptHandler("Do you respond with 1) attacking e4 with f5; 2) developing with Nc6? ", 2);
    return userInput;
}

int AggressiveCheck() {
    int userInput;
    cout << "Qa5+. An aggressive move. Your opponent plays Qd2." << endl;
    userInput = PromptHandler("Do you respond with 1) Qxd2; 2) Qh5? ", 2);
    return userInput;
}

int DevelopSafeResponse() {
    int userInput;
    cout << "You play Nc6." << endl;
    cout << "Your opponent plays Bc4 threatening f7." << endl;
    userInput = PromptHandler("Do you respond with 1) Be7, preparing for all out attack on the king; 2) develop Bc5? ", 2);
    return userInput;
}