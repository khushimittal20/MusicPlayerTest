# C++ Music Player 🎵

## Overview

This is a command-line based music player developed in C++ using Object-Oriented Programming principles. It allows users to manage a music library, create and manage playlists, play `.wav` files using the Windows Multimedia API (WinMM), and maintain a playback history. The project emphasizes modularity, file handling, and user interaction through a simple terminal interface.

## Features

- User registration and login
- Add songs to a central music library
- Search and play songs by title
- Create, select, and delete playlists
- Add or remove songs from playlists
- Persistent storage of library and playlists using text files
- Song playback using the WinMM library
- Listening history tracking per user
## How to Run

### Prerequisites

- Windows OS (required for WinMM)
- `.wav` audio files in the same directory or with absolute paths

### Compilation Command

Use a C++ compiler with support for Windows libraries:

```bash
g++ main.cpp Player.cpp MusicLibrary.cpp Playlist.cpp Song.cpp User.cpp -o music_player -lwinmm
.\music_player
```

## Methodology

- **Language:** C++
- **Paradigm:** Object-Oriented Programming (encapsulation, inheritance, polymorphism)
- **File Handling:** Used for storing songs, playlists, and user information
- **Multimedia:** Used WinMM (`<windows.h>` and `<mmsystem.h>`) for `.wav` playback
- **Design:** Modular file structure with separate header and source files for each class

## Sample Output
![image](https://github.com/user-attachments/assets/9ba08ad8-fbbd-46c5-8163-410bcf92daf3)


## Future Improvements

- Add volume control and mute/unmute functionality
- Search songs by artist, album, or genre
- Enhance playlist management with sorting and filtering
- Introduce graphical user interface (GUI) using frameworks like Qt or SFML
- Support for additional audio formats (e.g., MP3, FLAC) using libraries like SDL2 or FMOD
- Online streaming support or integration with APIs
- Cross-platform support (Linux/MacOS)

## Contributing

Contributions are welcome! If you'd like to improve this project, feel free to:

1. Fork the repository
2. Create a new branch (`git checkout -b feature-name`)
3. Make your changes
4. Commit your changes (`git commit -m "Add feature"`)
5. Push to the branch (`git push origin feature-name`)
6. Open a pull request

Please make sure your code is well-documented and follows consistent style.




