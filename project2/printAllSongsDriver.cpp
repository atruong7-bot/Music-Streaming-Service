// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #3

#include <iostream>
#include <fstream>

#include "Song.h" //copies contents

using namespace std;

/*
* This function displays the contents of your music library
* Parameters: array Songs, int numsongs
* Return: none
*/

void printAllSongs(Song arr[], int numSongs)
{
        if(numSongs <= 0)
        {
            cout << "No songs are stored" <<endl;
        }
        
        else
        {
            cout << "Here is a list of songs" << endl;
            for(int i = 0; i < numSongs; i++) //traverses through song array
            {
                cout << arr[i].getTitle() << " is by " << arr[i].getArtist() << endl; 
            }
        }
}

int main()
{
    // //test 1
    // //no songs stored with numSongs 0
    // Song songs[10];
    // printAllSongs(songs, 0);

    // //test 2 
    // // no songs stored with negative numSongs
    // Song songs[10];
    // printAllSongs(songs, -1);

    // //test 3
    // // print three songs
    Song songs[3];

    // putting songs in the songs array
    songs[0].setTitle("Eleanor Rigby");
    songs[0].setArtist("The Beatles");

    songs[1].setTitle("Jive Talkin");
    songs[1].setArtist("The Bee Gees");

    songs[2].setTitle("ABC");
    songs[2].setArtist("The Jackson 5");

    printAllSongs(songs, 3);    


    return 0;
}