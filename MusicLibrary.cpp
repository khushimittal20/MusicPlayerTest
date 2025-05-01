#include "MusicLibrary.h"
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
