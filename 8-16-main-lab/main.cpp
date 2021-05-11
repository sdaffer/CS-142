#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class files
#include "Song.h"
#include "Playlist.h"

// TODO: clean up memory when it is no longer used
//  (you need to find the appropriate places in the code to do this)


// Function prototypes
std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(/*TODO: list any parameters here*/);
void ListSongsMenuOption(/*TODO: list any parameters here*/);
void AddPlaylistMenuOption(/*TODO: list any parameters here*/);
void AddSongToPlaylistMenuOption(/*TODO: list any parameters here*/);
void ListPlaylistsMenuOption(/*TODO: list any parameters here*/);
void PlayPlaylistMenuOption(/*TODO: list any parameters here*/);
void RemovePlaylistMenuOption(/*TODO: list any parameters here*/);
void RemoveSongFromPlaylistMenuOption(/*TODO: list any parameters here*/);
void RemoveSongFromLibraryMenuOption(/*TODO: list any parameters here*/);
void OptionsMenuOption(/*TODO: list any parameters here*/);
void QuitMenuOption(/*TODO: list any parameters here*/);


// Main function
int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    //TODO: Create vectors to hold the songs and playlists

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(/*TODO: list any arguments here*/);
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


// Function definitions
std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
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

void AddSongsMenuOption(/*TODO: list any parameters here*/) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        //TODO: Create a Song using `songName` and `firstLine` and add it to allSongs,
        // .
        // This should be just 1-2 lines of code to create the song and add it to the list

        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(/*TODO: list any parameters here*/) {
    //TODO: Implement this menu option
}

void AddPlaylistMenuOption(/*TODO: list any parameters here*/) {
    //TODO: Implement this menu option
}

void AddSongToPlaylistMenuOption(/*TODO: list any parameters here*/) {
    //TODO: Implement this menu option
}

void ListPlaylistsMenuOption(/*TODO: list any parameters here*/) {
    //TODO: Implement this menu option
}

void PlayPlaylistMenuOption(/*TODO: list any parameters here*/) {
    //TODO: Implement this menu option
}

void RemovePlaylistMenuOption(/*TODO: list any parameters here*/) {
    //TODO: Implement this menu option
}

void RemoveSongFromPlaylistMenuOption(/*TODO: list any parameters here*/) {
    //TODO: Implement this menu option
}

void RemoveSongFromLibraryMenuOption(/*TODO: list any parameters here*/) {
    //TODO: Implement this menu option
}

void OptionsMenuOption() {
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption() {
    std::cout << "Goodbye!" << std::endl;
    exit(0);
}
