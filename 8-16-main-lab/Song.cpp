// TODO: Do I have any standard libraries needed here?
using namespace std;

// Class header
#include "Song.h"

// Constructors
// Default constructor
Song::Song() {
    songName = "no name";
    firstLine = "no first line";
    playCount = 0;
}
// Parameter constructor
Song::Song(string paramSongName, string paramFirstLine) {
    // I didn't put the play count in the parameters because I think it should always initialize to 0
    songName = paramSongName;
    firstLine = paramFirstLine;
    playCount = 0;
}


// Setters
void Song::SetSongName(string paramSongName) {
    songName = paramSongName;
}
void Song::SetFirstLine(string paramFirstLine) {
    firstLine = paramFirstLine;
}
void Song::SetPlayCount(int paramPlayCount) {
    playCount = paramPlayCount;
}


// Getters
// Auto-grader doesn't like these as one-liners, so they have to be expanded
string Song::GetSongName() const {
    return songName;
}
string Song::GetFirstLine() const {
    return firstLine;
}
int Song::GetPlayCount() const {
    return playCount;
}