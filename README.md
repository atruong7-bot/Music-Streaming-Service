---

# Music Streaming Service - C++ Project

This project is a C++ application designed to manage a music streaming service's song and listener data. The system allows users to load songs and listener information from text files, analyze music preferences, track song play counts, and interact with a variety of data-related features through a menu-driven interface.

## Features

- **Song Class**: Store song attributes such as title, artist, and genre.
- **Listener Class**: Manage listener names and track the number of times each song has been played.
- **File I/O**: Load song and listener data from files to populate the system.
- **Data Analysis**: Analyze the number of songs by genre, get the most frequently played genre, and examine listener statistics.
- **Interactive Menu**: A simple menu interface allows users to interact with the system and perform various operations on the song and listener data.

## System Mechanics

1. **Song Management**:  
   - Store song information such as title, artist, and genre.
   - Load songs from a text file using the `readSongs` function.
   - Print the list of songs and analyze them by genre.

2. **Listener Management**:  
   - Store information about listeners and their song play counts.
   - Add new listeners, track their play counts for songs, and analyze their music habits.
   - Load listener data from a text file using the `readListenerInfo` function.

3. **Data Analysis**:  
   - Count the number of songs in a specific genre.
   - Identify the most frequently occurring genre and the total number of songs in that genre.
   - Get song play counts for specific listeners and generate statistics on the number of unique songs they have listened to.

## How to Use

The application is menu-driven, and users can choose from the following options:
1. Read songs from a file
2. Print all songs
3. Count songs by genre
4. Find the most frequent genre
5. Add a new listener
6. Load listener information from a file
7. Get song play counts by a listener
8. Get statistics for a specific listener
9. Exit the program

## Files

- `Song.h`: Header file for the `Song` class, containing definitions for attributes and member functions.
- `Song.cpp`: Implementation of the `Song` class, including methods to manage song data.
- `Listener.h`: Header file for the `Listener` class, containing listener attributes and functionality.
- `Listener.cpp`: Implementation of the `Listener` class, managing listener play counts and statistics.
- `project2.cpp`: The main driver program that brings together the song and listener functionalities into an interactive menu system.
- **Driver Files**: Additional files to test individual functions and classes such as `songDriver.cpp`, `countGenreDriver.cpp`, and others.

## How to Compile and Run

1. **Clone the Repository**:  
   ```bash
   git clone https://github.com/username/music-streaming-service.git
   ```

2. **Compile the Program**:  
   ```bash
   g++ -std=c++11 project2.cpp Song.cpp Listener.cpp
   ```

3. **Run the Program**:  
   ```bash
   ./a.out
   ```

## Game Flow

1. **Read Song Data**: Load song data into the system from a file using the `readSongs` function.
2. **Manage Listeners**: Add new listeners and track their play counts for various songs.
3. **Data Analysis**: Perform tasks such as counting songs by genre and analyzing listener statistics through the menu interface.

## Requirements

- File handling using C++ streams to read data from files.
- Object-oriented programming principles with classes for `Song` and `Listener`.
- An interactive menu system that allows users to manage songs, listeners, and perform data analysis.

---

### Example Screenshots



