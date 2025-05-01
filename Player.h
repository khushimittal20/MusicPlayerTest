
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
    std::vector<Playlist*> playlists;  // Store multiple playlists
public:
    Player();
    ~Player();  
    MusicLibrary& getLibrary();  // Add this line
    void run();
    void addSongToLibrary();
    void addSongToPlaylist();
    void playSong(const Song& song);
    void playSongByTitle();
    void createPlaylist();  // Add function to create a new playlist
    void selectPlaylist();  // Add function to select an existing playlist
    void deletePlaylist();  // Add function to delete a playlist
    void deleteSongFromPlaylist();  // Add function to delete song
};

#endif 
