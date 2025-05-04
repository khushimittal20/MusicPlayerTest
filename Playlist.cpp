#include "Playlist.h"
#include "Song.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <limits>
#include <algorithm>

#pragma comment(lib, "winmm.lib")


Playlist::Playlist(std::string n) : name(n) {
    loadFromFile();
}

void Playlist::addSong(const Song& song) {
    songs.push_back(song);
    saveToFile();
}

// void Playlist::showPlaylist() const {
//     std::cout << "=== Playlist: " << name << " ===\n";
//     for (const auto& song : songs)
//         song.display();
// }
void Playlist::showPlaylist() const {
    if (songs.empty()) {
        std::cout << "No songs in the playlist.\n";
    } else {
        std::cout << "=== Playlist ===\n";
        for (const auto& song : songs) {
            std::cout << "Title: " << song.getTitle()<< "\n";
            song.display();
        }
    }
}

void Playlist::playAll() const {
    std::cout << "=== Playing Playlist: " << name << " ===\n";
    for (const auto& song : songs) {
        std::cout << "Now Playing: " << song.getTitle() << std::endl;
        PlaySound(song.getFilename().c_str(), NULL, SND_FILENAME | SND_ASYNC);
        std::cout << "(Press Enter to play next...)\n";
        // std::cin.ignore();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        PlaySound(NULL, NULL, 0); 
    }
}

std::string Playlist::getName() const {
    return name;
}

void Playlist::removeSong(const std::string& title) {
    auto it = std::remove_if(songs.begin(), songs.end(), [&title](const Song& song) {
        return song.getTitle() == title;
    });

    if (it != songs.end()) {
        songs.erase(it, songs.end());
        saveToFile(); 
    }
}
void Playlist::loadFromFile() {
    std::ifstream file(name + ".txt");
    if (file.is_open()) {
        std::string title, artist, album, filename;
        float duration;
        while (file >> title >> artist >> album >> duration >> filename) {
            songs.push_back(Song(title, artist, album, duration, filename));
        }
        file.close();
    }
}

void Playlist::saveToFile() const {
    std::ofstream file(name + ".txt");
    if (file.is_open()) {
        for (const auto& song : songs) {
            file << song.getTitle() << " "
                 << song.getArtist() << " "
                 << song.getAlbum() << " "
                 << song.getDuration() << " "
                 << song.getFilename() << "\n";
        }
        file.close();
    }
}