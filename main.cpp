#include <iostream>
#include <limits> 
#include "Player.h"

int main() {
    Player player;
    // Load the songs from the file when the program starts
    player.getLibrary().loadFromFile("data/songs.txt");
    player.run();
    player.getLibrary().saveToFile("data/songs.txt");
    return 0;
}
