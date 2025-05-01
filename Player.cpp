
#include "Player.h"
#include "Song.h"
#include <iostream>
#include <limits>
#include <windows.h>
#include <mmsystem.h>  
#pragma comment(lib, "winmm.lib") 


Player::Player() : user("admin", "1234") {
    currentPlaylist = new Playlist("My Playlist");
}


Player::~Player() {
    delete currentPlaylist;  
}

void Player::run() {

    std::string uname, pass;
    std::cout << "=== Login ===\nUsername: ";
    std::getline(std::cin, uname);
    std::cout << "Password: ";
    std::getline(std::cin, pass);

    if (!user.validateLogin(uname, pass)) {
        std::cout << "Invalid credentials. Exiting...\n";
        return;  
    }

    std::cout << "Login successful. Welcome, " << user.getUsername() << "!\n";
    
    int choice;
    do {
        std::cout << "\n=== Music Player Menu ===\n";
        std::cout << "1. Add Song to Library\n";
        std::cout << "2. Display Library\n";
        std::cout << "3. Add Song to Playlist\n";
        std::cout << "4. Show Playlist\n";
        std::cout << "5. Play Playlist\n";
        std::cout << "6. Play a Song by Title\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1: addSongToLibrary(); break;
            case 2: library.displayAllSongs(); break;
            case 3: addSongToPlaylist(); break;
            case 4: currentPlaylist->showPlaylist(); break;
            case 5: currentPlaylist->playAll(); break;
            case 6: playSongByTitle(); break;
            case 0: std::cout << "Exiting Music Player.\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Player::addSongToLibrary() {
    std::string title, artist, album, filename;
    float duration;
    std::cout << "Enter title: "; std::getline(std::cin, title);
    std::cout << "Enter artist: "; std::getline(std::cin, artist);
    std::cout << "Enter album: "; std::getline(std::cin, album);
    std::cout << "Enter duration (minutes): "; std::cin >> duration; std::cin.ignore();
    std::cout << "Enter filename (e.g., song.wav): "; std::getline(std::cin, filename);
    library.addSong(Song(title, artist, album, duration, filename));
    std::cout << "Song added to library.\n";
}

void Player::addSongToPlaylist() {
    std::string title;
    std::cout << "Enter song title to add to playlist: ";
    std::getline(std::cin, title);
    Song* song = library.searchSong(title);
    if (song) {
        currentPlaylist->addSong(*song);
        std::cout << "Added to playlist: " << song->getTitle() << "\n";  // Debugging line
    } else {
        std::cout << "Song not found in library.\n";
    }
}

void Player::playSong(const Song& song) {
    std::cout << "Now Playing: " << song.getTitle() << std::endl;
    PlaySound(song.getFilename().c_str(), NULL, SND_FILENAME | SND_ASYNC);
    std::cout << "(Press Enter to stop playback)\n";
    // std::cin.ignore();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    PlaySound(NULL, NULL, 0);
}

void Player::playSongByTitle() {
    std::string title;
    std::cout << "Enter song title to play: ";
    std::getline(std::cin, title);
    Song* song = library.searchSong(title);
    if (song) {
        playSong(*song);
    } else {
        std::cout << "Song not found.\n";
    }
}
