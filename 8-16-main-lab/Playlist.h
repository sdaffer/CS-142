#ifndef INC_8_16_MAIN_LAB_PLAYLIST_H
#define INC_8_16_MAIN_LAB_PLAYLIST_H
#include <string>
#include <vector>
#include "Song.h"
using namespace std;


class Playlist {
public:
    // Constructors
    Playlist(); // Default constructor
    Playlist(string paramPlaylistName); // Parameter constructor

    // Setters
    void SetPlaylistName(string paramPlayListName);
    void AddSongToPlaylist(Song *songToAdd);
    void RemoveSongFromPlaylistAtIndex(int paramSongIndex);
    void RemoveSongFromPlaylist(string songName);

    // Getters
    string GetPlayListName() const;

    // Play playlist member function
    void PlayPlaylist() const;

    // List all songs on playlist member function
    void ListAllSongsOnPlaylist() const;

private:
    string playlistName;
    vector <Song*> songsOnPlaylist;// TODO: Is an asterisk needed here?

};


#endif //INC_8_16_MAIN_LAB_PLAYLIST_H
