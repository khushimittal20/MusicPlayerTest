#include "Song.h"
#include <iostream>

Song::Song() : title(""), artist(""), album(""), duration(0.0), filename("") {}

Song::Song(std::string t, std::string a, std::string al, float d, std::string f)
    : title(t), artist(a), album(al), duration(d), filename(f) {}

void Song::display() const {
    std::cout << "Title: " << title
              << ", Artist: " << artist
              << ", Album: " << album
              << ", Duration: " << duration << " mins"
              << ", Filename: " << filename << std::endl;
}

std::string Song::getTitle() const {
    return title;
}
std::string Song::getArtist() const {  // Add this function
    return artist;
}

std::string Song::getAlbum() const {   // Add this function
    return album;
}
std::string Song::getFilename() const {
    return filename;
}

float Song::getDuration() const {
    return duration;
}
