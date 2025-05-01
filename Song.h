#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
private:
    std::string title;
    std::string artist;
    std::string album;
    std::string filename;
    float duration;  

public:
    Song();
    Song(std::string title, std::string artist, std::string album, float duration, std::string filename);

    void display() const; 
    std::string getTitle() const;
    std::string getArtist() const;   // Add this line
    std::string getAlbum() const;    // Add this line
    std::string getFilename() const;
    float getDuration() const;
};

#endif 
