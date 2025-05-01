
#ifndef PLAYER_H
#define PLAYER_H

#include "Song.h"
#include "MusicLibrary.h"
#include "Playlist.h"
#include <string>
#include "User.h"

class Player {
private:
    MusicLibrary library;
    Playlist* currentPlaylist;
    User user; 
public:
    Player();
    ~Player();  
    void run();
    void addSongToLibrary();
    void addSongToPlaylist();
    void playSong(const Song& song);
    void playSongByTitle();
};

#endif 
