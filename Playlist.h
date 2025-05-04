#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <vector>
#include <string>


class Playlist {
private:
    std::string name;
    std::vector<Song> songs;

public:
    Playlist(std::string name);
    void addSong(const Song& song);
    void showPlaylist() const;
    void playAll() const;
    std::string getName() const;
    void removeSong(const std::string& title);
    void loadFromFile();  // Load playlist from file
    void saveToFile() const;  // Save playlist to file
};

#endif 
