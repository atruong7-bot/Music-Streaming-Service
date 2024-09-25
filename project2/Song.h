// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #1
//interview link: https://cuboulder.zoom.us/j/6940021686


#ifndef SONG.H //preprocessor activites, when compiling turn these into comments so compilation works
#define SONG.H 

#include <string>
using namespace std;

class Song
{
    private: //members that cannot be accessed without public functions
    string title;
    string artist;
    string genre;

    public: //members that can access private members
    Song(); //default constructor
    Song(string title, string artist, string genre); //parameterized constructor
    string getTitle();
    void setTitle(string title);
    string getArtist();
    void setArtist(string artist);
    string getGenre();
    void setGenre(string genre);
};

#endif