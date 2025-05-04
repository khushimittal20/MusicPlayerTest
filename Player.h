
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
    std::vector<Playlist*> playlists;  
public:
    Player();
    ~Player();  
    MusicLibrary& getLibrary();  
    void run();
    void addSongToLibrary();
    void addSongToPlaylist();
    void playSong(const Song& song);
    void playSongByTitle();
    void createPlaylist();  
    void selectPlaylist();  
    void deletePlaylist();  
    void deleteSongFromPlaylist();  
    void deleteSongFromLibrary();
};

#endif 
