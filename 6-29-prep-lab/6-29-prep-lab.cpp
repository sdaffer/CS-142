#include <iostream>
#include <vector>
using namespace std;


// Function Prototypes



int main() {

    // Variables
    const int NUM_PAIRS = 5;
    vector<int> playerNumber(NUM_PAIRS);
    vector<int> playerRating(NUM_PAIRS);

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
    cout << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl;
    cout << endl;


    return 0;
}


// Functions

void addPlayer(const char inputChar, vector<int>& playerNumber, vector<int>& playerRating) {
    int userInputNumber = 0;
    int userInputRating = 0;

    cout << "Enter another player's jersey number: ";
    cin >> userInputNumber;
    cout << "Enter another player's rating: ";
    cin >> userInputRating;


}

char userInput(){
    char inputChar = 'a';
    cout << "Choose an option: ";
    cin >> inputChar;
    return inputChar;
}