// TODO: Do I have any standard libraries needed here?
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