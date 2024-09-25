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
<img width="583" alt="Screenshot 2024-09-25 at 5 31 00 PM" src="https://github.com/user-attachments/assets/c7980110-a036-4d20-84a0-7663fd9820aa">
<img width="438" alt="Screenshot 2024-09-25 at 5 31 42 PM" src="https://github.com/user-attachments/assets/a8bd37d9-293e-4d83-93dd-e312240fd26d">
<img width="456" alt="Screenshot 2024-09-25 at 5 32 07 PM" src="https://github.com/user-attachments/assets/9523fd4e-d851-4b14-b857-1c76ec6deec5">
<img width="468" alt="Screenshot 2024-09-25 at 5 32 16 PM" src="https://github.com/user-attachments/assets/5014fb0e-ea87-405d-ba45-7914c57e563c">
<img width="468" alt="Screenshot 2024-09-25 at 5 32 26 PM" src="https://github.com/user-attachments/assets/27259321-bbeb-4543-8c3b-5d9873c3e361">
<img width="442" alt="Screenshot 2024-09-25 at 5 32 46 PM" src="https://github.com/user-attachments/assets/83fd67a6-5d73-4b17-bb56-924c394e0a68">
<img width="420" alt="Screenshot 2024-09-25 at 5 32 58 PM" src="https://github.com/user-attachments/assets/f5979291-fa62-420a-be4d-26001a0333df">
<img width="354" alt="Screenshot 2024-09-25 at 5 33 04 PM" src="https://github.com/user-attachments/assets/9936b6c2-44bd-42ce-bd1a-e16339a0e580">
<img width="428" alt="Screenshot 2024-09-25 at 5 33 15 PM" src="https://github.com/user-attachments/assets/604a8df3-75a9-4d27-8774-c911239261e3">
<img width="373" alt="Screenshot 2024-09-25 at 5 33 26 PM" src="https://github.com/user-attachments/assets/7dbb3ab8-3343-4904-a9fc-c692a629771c">
<img width="376" alt="Screenshot 2024-09-25 at 5 33 36 PM" src="https://github.com/user-attachments/assets/9d62e707-7f23-449f-b0a2-fcc786bee7d3">
<img width="317" alt="Screenshot 2024-09-25 at 5 34 01 PM" src="https://github.com/user-attachments/assets/5e7c0414-01cd-417c-a5ff-2a16f2e32ca5">
<img width="315" alt="Screenshot 2024-09-25 at 5 34 09 PM" src="https://github.com/user-attachments/assets/58687a62-4add-41bd-b1d4-aac3580083f4">
<img width="352" alt="Screenshot 2024-09-25 at 5 34 14 PM" src="https://github.com/user-attachments/assets/a57a2a48-c9ac-4d23-b7b7-05d8caf5fa36">
<img width="323" alt="Screenshot 2024-09-25 at 5 34 20 PM" src="https://github.com/user-attachments/assets/2ecb99ce-7f5a-4dc1-8b8b-980ddb79f805">
<img width="338" alt="Screenshot 2024-09-25 at 5 34 25 PM" src="https://github.com/user-attachments/assets/7cfa8a6d-0546-4b37-8b1e-8d9c45f5de66">






