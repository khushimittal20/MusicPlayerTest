#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include "Song.h"
#include <vector>

class MusicLibrary {
private:
    std::vector<Song> songs;

public:
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
    bool deleteSong(const std::string& title);

    void addSong(const Song& song);
    void displayAllSongs() const;
    Song* searchSong(const std::string& title);
    const std::vector<Song>& getSongs() const;
};

#endif 
