
#include "Player.h"
#include "Song.h"
#include <iostream>
#include <limits>
#include <windows.h>
#include <mmsystem.h> 
#include <algorithm> 
#pragma comment(lib, "winmm.lib") 

MusicLibrary& Player::getLibrary() {
    return library;  
}

Player::Player() : user("admin", "1234") {
    currentPlaylist = new Playlist("My Playlist");
}


Player::~Player() {
    delete currentPlaylist;  
}

void Player::run() {

    std::string uname, pass;
    int choice;
    std::cout << "=== Music Player ===\n";
    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore();  

    if (choice == 1) {  
        std::cout << "=== Login ===\n";
        std::cout << "Username: ";
        std::getline(std::cin, uname);
        std::cout << "Password: ";
        std::getline(std::cin, pass);

        if (!User::validateLoginFromFile(uname, pass)) {
            std::cout << "Invalid credentials. Exiting...\n";
            return;
        }

        std::cout << "Login successful. Welcome, " << uname << "!\n";
    } else if (choice == 2) {  
        std::cout << "=== Register ===\n";
        std::cout << "Choose a username: ";
        std::getline(std::cin, uname);
        std::cout << "Choose a password: ";
        std::getline(std::cin, pass);

        if (User::registerUser(uname, pass)) {
            std::cout << "Registration successful. You can now log in.\n";
            return;
        }
    } else {
        std::cout << "Invalid choice.\n";
        return;
    }
    
    do {
        std::cout << "\n=== Music Player Menu ===\n";
        std::cout << "1. Add Song to Library\n";
        std::cout << "2. Display Library\n";
        std::cout << "3. Add Song to Playlist\n";
        std::cout << "4. Show Playlist\n";
        std::cout << "5. Play Playlist\n";
        std::cout << "6. Play a Song by Title\n";
        std::cout << "7. Create New Playlist\n";
        std::cout << "8. Select Playlist\n";
        std::cout << "9. Delete Playlist\n";
        std::cout << "10. Delete Song from Playlist\n";
        std::cout << "11. Delete Song from Library\n";
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
            case 7: createPlaylist(); break;
            case 8: selectPlaylist(); break;
            case 9: deletePlaylist(); break;
            case 10: deleteSongFromPlaylist(); break;
            case 11: deleteSongFromLibrary(); break;
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
        std::cout << "Added to playlist: " << song->getTitle() << "\n";  
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

void Player::createPlaylist() {
    std::string name;
    std::cout << "Enter the name for the new playlist: ";
    std::getline(std::cin, name);

    Playlist* newPlaylist = new Playlist(name);
    playlists.push_back(newPlaylist);
    currentPlaylist = newPlaylist;  // new vali banegi
    std::cout << "Playlist created and selected: " << name << "\n";
}

void Player::selectPlaylist() {
    std::cout << "Enter the name of the playlist you want to select: ";
    std::string name;
    std::getline(std::cin, name);

    for (auto& playlist : playlists) {
        if (playlist->getName() == name) {
            currentPlaylist = playlist;
            std::cout << "Selected playlist: " << name << "\n";
            return;
        }
    }
    std::cout << "Playlist not found.\n";
}

void Player::deletePlaylist() {
    std::cout << "Enter the name of the playlist to delete: ";
    std::string name;
    std::getline(std::cin, name);

    auto it = std::remove_if(playlists.begin(), playlists.end(), [&name](Playlist* playlist) {
        return playlist->getName() == name;
    });

    if (it != playlists.end()) {
        delete *it;
        playlists.erase(it);
        std::cout << "Playlist deleted: " << name << "\n";
    } else {
        std::cout << "Playlist not found.\n";
    }
}
void Player::deleteSongFromPlaylist() {
    std::string title;
    std::cout << "Enter the song title to remove from the playlist: ";
    std::getline(std::cin, title);

    if (currentPlaylist) {
        currentPlaylist->removeSong(title);
        std::cout << "Song removed from playlist.\n";
    } else {
        std::cout << "No playlist selected.\n";
    }
}

void Player::deleteSongFromLibrary() {
    std::string title;
    std::cout << "Enter the title of the song to delete from library: ";
    std::getline(std::cin, title);
    if (library.deleteSong(title)) {
        for (auto& pl : playlists)
            pl->removeSong(title);
        if (currentPlaylist)
            currentPlaylist->removeSong(title);
        std::cout << "Song deleted from library and all playlists.\n";
    } else {
        std::cout << "Song not found.\n";
    }
}
