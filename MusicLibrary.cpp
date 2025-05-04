#include "MusicLibrary.h"
#include <iostream>
#include <fstream>
#include <iostream>

void MusicLibrary::addSong(const Song& song) {
    songs.push_back(song);
}

void MusicLibrary::displayAllSongs() const {
    if (songs.empty()) {
        std::cout << "Library is empty.\n";
        return;
    }
    std::cout << "=== Music Library ===\n";
    for (const auto& song : songs)
        song.display();
}

Song* MusicLibrary::searchSong(const std::string& title) {
    for (auto& song : songs) {
        if (song.getTitle() == title)
            return &song;
    }
    return nullptr;
}

const std::vector<Song>& MusicLibrary::getSongs() const {
    return songs;
}

void MusicLibrary::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string title, artist, album, filename;
        float duration;
        while (file >> title >> artist >> album >> duration >> filename) {
            Song song(title, artist, album, duration, filename);
            addSong(song);  // addSong already kr rkha hai
        }
        file.close();
    } else {
        std::cout << "Failed to open file for reading.\n";
    }
}

void MusicLibrary::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& song : songs) {
            file << song.getTitle() << " "
                 << song.getArtist() << " "
                 << song.getAlbum() << " "
                 << song.getDuration() << " "
                 << song.getFilename() << "\n";
        }
        file.close();
    } else {
        std::cout << "Failed to open file for saving.\n";
    }
}