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
void Playlist::RemoveSongFromPlaylist(int paramSongIndex) {
    // TODO: Is this the right way to deallocate memory and remove the song?
    delete songsOnPlaylist.at(paramSongIndex);
    songsOnPlaylist.erase(songsOnPlaylist.begin() + paramSongIndex);
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