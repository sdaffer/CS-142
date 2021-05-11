#ifndef INC_8_16_MAIN_LAB_SONG_H
#define INC_8_16_MAIN_LAB_SONG_H
#include <string>
using namespace std;

class Song {
public:
    // Constructors
    Song(); // Default constructor
    Song(string paramSongName, string paramFirstLine); // Parameter constructor

    // Setters
    void SetSongName(string paramSongName);
    void SetFirstLine(string paramFirstLine);
    void SetPlayCount(int paramPlayCount);

    // Getters
    string GetSongName() const;
    string GetFirstLine() const;
    int GetPlayCount() const;

    // TODO: Will I need printers? Not sure yet. Check later.
    // Play song member function. This will increase the playcount for us as well
    void PlaySong();

private:
    string songName;
    string firstLine;
    int playCount;
};


#endif //INC_8_16_MAIN_LAB_SONG_H
