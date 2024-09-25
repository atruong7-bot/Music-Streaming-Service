// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #2

#include <iostream>
#include <fstream>

#include "Song.h" //copies contents

using namespace std;

/*
* This function  takes a string, splits it at every occurrence of a delimiter, 
and then populates an array of strings with the split pieces, up to the provided maximum number of pieces. 
* Parameters: 
-The string to be split 
-A separator, char, which marks where the string should be split up 
-An array of string, where the split-apart string pieces will be stored 
-The size of the array, int 
* Return: the number of pieces the string was split into, as an integer. 
*/


int split(string a, char sep, string arr[], int size)
{
    int stringSize = a.size();

    int position = 0; //to keep track of the position of the array

    if(a == "") //if the string is nothing
    {
        return 0;
    }

    for(int i = 0; i < stringSize; i++) //traverse string a
    {
        if(a[i] == sep)
        {
            position++; //once the character of the string is the seperator, position of the array moves to the next element
        }

        else
        {
            arr[position] = arr[position] + a[i]; //constructing the element letter by letter
        }
        
    }
    if(position + 1 > size) //If the string is split into more pieces than the size of the array (the last parameter), 
    //then the function returns -1. 
    {
        return -1;
    }
    return position + 1; //the number of pieces the string was split into

}

/*
* This function will fill an array of Song objects with title, artist and genre information.
* Parameters: string fileName, array songs, int numSongsStored, int songArrSize
* Return: int total number of songs
*/

int readSongs(string fileName, Song arr[], int numSongsStored, int songArrSize)
{

    ifstream file;
    file.open(fileName);

    if (numSongsStored == songArrSize)
    {
        return -2;
    }

    if(file.fail() == true) //if file cannot be opened
    {
        
        return -1;
    }

    string line; //used for getline

    while(getline(file, line) && numSongsStored < songArrSize) //The number of songs stored in the array cannot exceed the songArrSize
    {
        string arr1[3];
        // 3 elements: title, artist, genre
        // this information is in each Song array element
        // reinitialized each loop
        
        if (line == "") 
        {
            continue; //empty lines are not added to array
        }
        
        if (line != "")
        {
            split (line, ',', arr1, 3);

            Song addToArray; //new song to be added to song array 
            addToArray.setTitle(arr1[0]);
            addToArray.setArtist(arr1[1]);
            addToArray.setGenre(arr1[2]);

            arr[numSongsStored] = addToArray; //adding new song with title, artist, genre to current song array
            numSongsStored++; //iterate next postion of song array
        }



    }
    return numSongsStored;
}



int main()
{
    //test 1
    // no songs stored with numSongs 0
    Song songs[10] = {};
    songs[0].setTitle("name1");
    songs[0].setArtist("artist1");
    songs[0].setGenre("genre1");
    cout << readSongs("fileName.txt", songs, 1, 10) << endl;
    
    // //test 2
    // // Test non-exist file
    // cout << readSongs("whatsong.txt", songs, 0, 50) << endl;

    // //test 3
    // // Test if you have read in the titles correctly
    // int numsongs = readSongs("songs_mini_test.txt", songs, 0, 50);

    // cout << "Function returned value: " << numsongs << endl;

    // // checking the elements in the arr
    // if(numsongs == 3)
    // {
    //     printArrTitle(songs, numsongs);
    // }
    // else
    // {
    //     cout << "make sure your song count is correct" << endl;




    // }
    return 0;
}