#include <iostream>
using namespace std;

// Class header
#include "Playlist.h"


// Constructors
// Default constructor
Playlist::Playlist() {
    playlistName = "no playlist name";
}
// Parameter constructor
Playlist::Playlist(string paramPlaylistName) {
    playlistName = paramPlaylistName;
}


// Setters
void Playlist::SetPlaylistName(string paramPlayListName) {
    playlistName = paramPlayListName;
}
void Playlist::AddSongToPlaylist(Song *songToAdd) {
    songsOnPlaylist.push_back(songToAdd);
}
void Playlist::RemoveSongFromPlaylistAtIndex(int paramSongIndex) {
    delete songsOnPlaylist.at(paramSongIndex);
    songsOnPlaylist.erase(songsOnPlaylist.begin() + paramSongIndex);
}
void Playlist::RemoveSongFromPlaylist(string songName) {
    // Loop through all songs on the playlist object and remove anytime the song name matches the parameter
    for (unsigned int i = 0; i < songsOnPlaylist.size(); ++i) {
        if (songName == songsOnPlaylist.at(i)->GetSongName()) {
            // Deallocate memory and remove from playlist
            cout << "IT FOUND THE NAME" << endl;
            delete songsOnPlaylist.at(i);
            cout << "IT DEALLOCATED MEMORY" << endl;
            songsOnPlaylist.erase(songsOnPlaylist.begin() + i);
            cout << "IT ERASED THE SONG ON PLAYLIST VECTOR" << endl;
            //FIXME: The loop gets at least to this point. I think that there's an error because the loop doesn't have the correct range after the song is removed
            break;
        }
    }
}


// Getters
string Playlist::GetPlayListName() const {
    return playlistName;
}

// Play playlist member function
void Playlist::PlayPlaylist() const {
    for (unsigned int i = 0; i < songsOnPlaylist.size(); ++i) {
        songsOnPlaylist.at(i)->PlaySong();
    }
}

// List all songs on playlist member function
void Playlist::ListAllSongsOnPlaylist() const {
    for (unsigned int i = 0; i < songsOnPlaylist.size(); ++i) {
        cout << "  " << i << ": " << songsOnPlaylist.at(i)->GetSongName() << endl;
    }
}