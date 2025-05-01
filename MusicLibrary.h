#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include "Song.h"
#include <vector>

class MusicLibrary {
private:
    std::vector<Song> songs;

public:
    void addSong(const Song& song);
    void displayAllSongs() const;
    Song* searchSong(const std::string& title);
    const std::vector<Song>& getSongs() const;
};

#endif 
