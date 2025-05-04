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

## Methodology

- **Language:** C++
- **Paradigm:** Object-Oriented Programming (encapsulation, inheritance, polymorphism)
- **File Handling:** Used for storing songs, playlists, and user information
- **Multimedia:** Used WinMM (`<windows.h>` and `<mmsystem.h>`) for `.wav` playback
- **Design:** Modular file structure with separate header and source files for each class

## File Structure

