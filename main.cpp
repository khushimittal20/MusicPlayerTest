#include <iostream>
#include <limits> 
#include "Player.h"

int main() {
    Player player;
    player.getLibrary().loadFromFile("data/songs.txt");
    player.run();
    player.getLibrary().saveToFile("data/songs.txt");
    return 0;
}
