// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #1

#include <iostream>
#include "Song.h" // copies the content

using namespace std;

int main()
{
    // //test 1
    // // default constructor
    // Song s1 = Song();
    // cout << s1.getTitle() << endl;
    // cout << s1.getArtist() << endl;
    // cout << s1.getGenre() << endl;

    //test 2
    // checking setter for song name
    Song s2 = Song();
    string title = "Yesterday";
    s2.setTitle(title);
    cout << s2.getTitle() << endl;

    // //test 3
    // Song s3 = Song();
    // string artist = "The Beatles";
    // s3.setArtist(artist);
    // cout << s3.getArtist() << endl;


    return 0;
}