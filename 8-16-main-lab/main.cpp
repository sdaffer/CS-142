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

void AddSongsMenuOption(vector <Song*> &paramUserSongs);
void ListSongsMenuOption(vector <Song*> paramUserSongs);
void AddPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists);
void AddSongToPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists);
void ListPlaylistsMenuOption(vector <Playlist*> paramUserPlaylists);
void PlayPlaylistMenuOption(vector <Playlist*> paramUserPlaylists);
void RemovePlaylistMenuOption(vector <Playlist*> &paramUserPlaylists);
void RemoveSongFromPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists);
void RemoveSongFromLibraryMenuOption(vector <Song*> &paramUserSongs);
void OptionsMenuOption();
void QuitMenuOption();


// Main function
int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    //TODO: Create vectors to hold the songs and playlists
    vector<Song*> allSongs; // TODO: is the astrix what's needed here?
    vector<Playlist*> allPlaylists;

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(allSongs);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(allSongs);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(allPlaylists);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(allPlaylists);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(allPlaylists);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(allPlaylists);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(allPlaylists);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(allPlaylists);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(allSongs);
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

void AddSongsMenuOption(vector <Song*> &paramUserSongs) {
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

        // Creating new song object with new to allocate memory
        Song* newSong = new Song(songName, firstLine); // Play count initialized to 0 in constructors
        paramUserSongs.push_back(newSong);

        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(vector <Song*> paramUserSongs) {
    for (unsigned int i = 0; i < paramUserSongs.size(); ++i) {
        cout << paramUserSongs.at(i)->GetSongName() << ": \"" << paramUserSongs.at(i)->GetFirstLine() << "\", ";
        cout << paramUserSongs.at(i)->GetPlayCount() << " play(s)." << endl;
    }
}

void AddPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists) {
    string userPlaylistName = "";
    cout << "Playlist name: ";
    cin >> userPlaylistName;

    Playlist* newPlaylist = new Playlist(userPlaylistName);
    paramUserPlaylists.push_back(newPlaylist);
}

void AddSongToPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists) {

}

void ListPlaylistsMenuOption(vector <Playlist*> paramUserPlaylists) {
    //TODO: Implement this menu option
}

void PlayPlaylistMenuOption(vector <Playlist*> paramUserPlaylists) {
    //TODO: Implement this menu option
}

void RemovePlaylistMenuOption(vector <Playlist*> &paramUserPlaylists) {
    //TODO: Implement this menu option
}

void RemoveSongFromPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists) {
    //TODO: Implement this menu option
}

void RemoveSongFromLibraryMenuOption(vector <Song*> &paramUserSongs) {
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
    // TODO: Need to delete all songs in this function before the code terminates
    exit(0);
}
