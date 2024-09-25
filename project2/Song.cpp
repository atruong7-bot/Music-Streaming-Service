// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #1

#include "Song.h"
#include <iostream>


using namespace std;

//constructors
Song::Song()
{
    title = "";
    artist = "";
    genre = "";
}

Song::Song(string title_, string artist_, string genre_)
{
    title = title_;
    artist = artist_;
    genre = genre_;
}

//getters/setters

string Song::getTitle()
{
    return title;
} 

void Song::setTitle(string setTitle)
{
    title = setTitle;
}

string Song::getArtist()
{
    return artist;
}

void Song::setArtist(string setArtist)
{
    artist = setArtist;
}

string Song::getGenre()
{
    return genre;
}

void Song::setGenre(string setGenre)
{
    genre = setGenre;
}

