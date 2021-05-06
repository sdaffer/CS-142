#include <iostream>
#include <vector>
using namespace std;


// Function Prototypes
char UserPromptAndInput();
void OutputPlayersAbove(const vector<int>& playerNumber, const vector<int>& playerRating);
void OutputRoster(const vector<int>& playerNumber, const vector<int>& playerRating);
void DeletePlayer(vector<int>& playerNumber, vector<int>& playerRating);
void UpdateRating(vector<int>& playerNumber, vector<int>& playerRating);
void AddPlayer(vector<int>& playerNumber, vector<int>& playerRating);


// Main function
int main() {

    // Variables
    const int NUM_PAIRS = 5;
    vector<int> playerNumber(NUM_PAIRS);
    vector<int> playerRating(NUM_PAIRS);
    char userInputChar = 'a';
    bool cycleBool = true;

    // Input information into the two vectors
    for (int i = 0; i < NUM_PAIRS; ++i) {
        cout << "Enter player " << i + 1 << "'s jersey number: ";
        cin >> playerNumber.at(i);
        cout << "Enter player " << i + 1 << "'s rating: ";
        cin >> playerRating.at(i);
        cout << endl;
    }

    cout << endl;
    cout << "ROSTER" << endl;

    for (int i = 0; i < NUM_PAIRS; ++i) {
        cout << "Player " << i + 1 << " -- Jersey number: " << playerNumber.at(i) << ", ";
        cout << "Rating: " << playerRating.at(i) << endl;
    }

    cout << endl;

    userInputChar = UserPromptAndInput();

    // Continuously cycle through options until 'q' is entered

    while (cycleBool) {
        if (userInputChar == 'a') {
            AddPlayer(playerNumber, playerRating);
        }
        else if (userInputChar == 'd') {
            DeletePlayer(playerNumber, playerRating);
        }
        else if (userInputChar == 'u') {
            UpdateRating(playerNumber, playerRating);
        }
        else if (userInputChar == 'r') {
            OutputPlayersAbove(playerNumber, playerRating);
        }
        else if (userInputChar == 'o') {
            OutputRoster(playerNumber, playerRating);
        }
        else if (userInputChar == 'q') {
            cycleBool = false;
            exit(0);
        }
        else {
            cout << "Invalid input, please try again." << endl;
        }
        userInputChar = UserPromptAndInput();
    }

    return 0;
}


// Functions

void AddPlayer(vector<int>& playerNumber, vector<int>& playerRating) {
    int userInputNumber = 0;
    int userInputRating = 0;

    cout << "Enter another player's jersey number: ";
    cin >> userInputNumber;
    cout << "Enter another player's rating: ";
    cin >> userInputRating;

    playerNumber.push_back(userInputNumber);
    playerRating.push_back(userInputRating);
}

void UpdateRating(vector<int>& playerNumber, vector<int>& playerRating) {
    int userJerseyInput = 0;
    int userRatingInput = 0;

    cout << "Enter a jersey number: ";
    cin >> userJerseyInput;
    cout << "Enter a new rating for player: ";
    cin >> userRatingInput;

    for (int i = 0; i < playerRating.size(); ++i) {
        if (playerNumber.at(i) == userJerseyInput) {
            playerRating.at(i) = userRatingInput;
        }
    }
}

void DeletePlayer(vector<int>& playerNumber, vector<int>& playerRating) {
    int userJerseyInput = 0;

    cout << "Enter a jersey number: ";
    cin >> userJerseyInput;

    for (int i = 0; i < playerNumber.size(); ++i) {
        if (playerNumber.at(i) == userJerseyInput) {
            playerNumber.erase(playerNumber.begin() + i);
            playerRating.erase(playerRating.begin() + i);
        }
    }
}

void OutputRoster(const vector<int>& playerNumber, const vector<int>& playerRating) {
    cout << "ROSTER" << endl;

    for (int i = 0; i < playerNumber.size(); ++i) {
        cout << "Player " << i + 1 << " -- Jersey number: " << playerNumber.at(i) << ", ";
        cout << "Rating: " << playerRating.at(i) << endl;
    }
}

void OutputPlayersAbove(const vector<int>& playerNumber, const vector<int>& playerRating) {
    int userInput = 0;

    cout << "Enter a rating: ";
    cin >> userInput;
    cout << "ABOVE " << userInput << endl;

    for (int i = 0; i < playerRating.size(); ++i) {
        if (playerRating.at(i) > userInput) {
            cout << "Player " << i + 1 << " -- Jersey number: " << playerNumber.at(i) << ", ";
            cout << "Rating: " << playerRating.at(i) << endl;
        }
    }
}

char UserPromptAndInput(){
    char inputChar = 'a';

    cout << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl;
    cout << endl;

    cout << "Choose an option: ";
    cin >> inputChar;

    return inputChar;
}