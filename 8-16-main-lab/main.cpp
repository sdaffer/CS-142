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
void AddSongToPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists, vector <Song*> paramUserSongs);
void ListPlaylistsMenuOption(vector <Playlist*> paramUserPlaylists);
void PlayPlaylistMenuOption(vector <Playlist*> paramUserPlaylists);
void RemovePlaylistMenuOption(vector <Playlist*> &paramUserPlaylists);
void RemoveSongFromPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists);
void RemoveSongFromLibraryMenuOption(vector <Song*> &paramUserSongs, vector <Playlist*> &paramUserPlaylists);
void OptionsMenuOption();
void QuitMenuOption(vector <Song*> &paramUserSongs, vector <Playlist*> &paramUserPlaylists);


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
            AddSongToPlaylistMenuOption(allPlaylists, allSongs);
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
            RemoveSongFromLibraryMenuOption(allSongs, allPlaylists);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption(allSongs, allPlaylists);
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

void AddSongToPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists, vector <Song*> paramUserSongs) { // TODO: Does this need to be moved to after the ListPlaylist function? (BC it calls it?)
    int userPlaylistIndex = 0;
    int userSongIndex = 0;

    // List all of the playlist by calling the function that's already built to do it
    ListPlaylistsMenuOption(paramUserPlaylists);

    // Get user input
    cout << "Pick a playlist index number: ";
    cin >> userPlaylistIndex;

    // Output all of the songs in the library
    for (unsigned int i = 0; i < paramUserSongs.size(); ++i) {
        cout << "  " << i << ": " << paramUserSongs.at(i)->GetSongName() << endl;
    }

    // Get user input
    cout << "Pick a song index number: ";
    cin >> userSongIndex;
    cout << endl;

    // Now add the song to the playlist
    paramUserPlaylists.at(userPlaylistIndex)->AddSongToPlaylist(paramUserSongs.at(userSongIndex));

}

void ListPlaylistsMenuOption(vector <Playlist*> paramUserPlaylists) {
    // Loop through the allplaylist vector and list each one
    for (unsigned int i = 0; i < paramUserPlaylists.size(); ++i) {
        cout << "  " << i << ": " << paramUserPlaylists.at(i)->GetPlayListName() << endl;
    }
}

void PlayPlaylistMenuOption(vector <Playlist*> paramUserPlaylists) {
    int userPlaylistIndex = 0;

    // Call the main function to list all playlists
    ListPlaylistsMenuOption(paramUserPlaylists);

    // Get user input
    cout << "Pick a playlist index number: ";
    cin >> userPlaylistIndex;

    // Call the playlist member function to deal with the actual playing
    paramUserPlaylists.at(userPlaylistIndex)->PlayPlaylist();
}

void RemovePlaylistMenuOption(vector <Playlist*> &paramUserPlaylists) {
    int userPlayListIndex = 0;

    // Call the main function to list all playlists
    ListPlaylistsMenuOption(paramUserPlaylists);

    // Get user input
    cout << "Pick a playlist index number to remove: ";
    cin >> userPlayListIndex;
    cout << endl;

    // Deallocate memory and remove from the allplaylists vector
    // TODO: Is this the right way to deallocate memory and remove the playlist?
    delete paramUserPlaylists.at(userPlayListIndex);
    paramUserPlaylists.erase(paramUserPlaylists.begin() + userPlayListIndex);
}

void RemoveSongFromPlaylistMenuOption(vector <Playlist*> &paramUserPlaylists) {
    int userPlaylistIndex = 0;
    int userSongIndex = 0;

    // Call the main function to list all playlists
    ListPlaylistsMenuOption(paramUserPlaylists);

    // Get user input
    cout << "Pick a playlist index number: ";
    cin >> userPlaylistIndex;
    cout << endl;

    // Output all songs on that user specified playlist and get input on index of song to remove
    paramUserPlaylists.at(userPlaylistIndex)->ListAllSongsOnPlaylist();
    cout << "Pick a song index number to remove: ";
    cin >> userSongIndex;
    cout << endl;

    // Use the playlist member function to deallocate memory and remove the song from the vector
    // Deallocation and removal handled in the member function
    paramUserPlaylists.at(userPlaylistIndex)->RemoveSongFromPlaylistAtIndex(userSongIndex);
}

void RemoveSongFromLibraryMenuOption(vector <Song*> &paramUserSongs, vector <Playlist*> &paramUserPlaylists) {
    int userSongIndex = 0;

    // Output all songs in the allsongs vector
    for (unsigned int i = 0; i < paramUserSongs.size(); ++i) {
        cout << "  " << i << ": " << paramUserSongs.at(i)->GetSongName() << endl;
    }

    // Get user input
    cout << "Pick a song index number to remove: ";
    cin >> userSongIndex;


    // Remove from all playlists that the song was added to
    for (unsigned int i = 0; i < paramUserPlaylists.size(); ++i) {
        // Memory deallocation is handled by the removesongfromplaylist member function
        // TODO: The following line causes the program to abort. It doesn't work.
        paramUserPlaylists.at(i)->RemoveSongFromPlaylist(paramUserSongs.at(userSongIndex)->GetSongName());
    }

    // Deallocate memory and remove the song from the library vector
    delete paramUserSongs.at(userSongIndex);
    paramUserSongs.erase(paramUserSongs.begin() + userSongIndex);

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

void QuitMenuOption(vector <Song*> &paramUserSongs, vector <Playlist*> &paramUserPlaylists) {
    std::cout << "Goodbye!" << std::endl;

    // Deallocate memory for all songs before exiting
    for (unsigned int i = 0; i < paramUserSongs.size(); ++i) {
        // The following if condition makes sure we don't try to access a vector out of range
        if ((paramUserSongs.size() == 0) || (paramUserPlaylists.size() == 0)) {
            break;
        }
        else {
            string songNameToDelete = "";
            cout << "stop1" << endl;
            songNameToDelete = paramUserSongs.at(i)->GetSongName();
            delete paramUserSongs.at(i);
            cout << "stop2" << endl;
            // FIXME: THe problem is in this line below. I'll try to modify it
            paramUserPlaylists.at(i)->RemoveSongFromPlaylistAtIndex(i); // Deleting memory is handled inside this member function
            //paramUserPlaylists.at(i)->RemoveSongFromPlaylist(songNameToDelete);
            cout << "stop3" << endl;
        }
    }

    exit(0);
}
