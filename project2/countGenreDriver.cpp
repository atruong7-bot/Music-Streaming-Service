// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #4

#include <iostream>
#include <fstream>
#include <string>
#include "Song.h"

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

/*
* This helper function will compare the genre the user is looking for to the genre of each song
and checks if they are the same even if they are capitalized differently
* Parameters: string genre, string compare
* Return: true or false
*/

bool isSameString(string genre, string compare){
    int sizeG = genre.size();
    int sizeC = compare.size();
    int check = 0; //will be used to figure out if all characters of string genre match all characters of string compare
    if(sizeG != sizeC) //genres being compared must be same length first
    {
        return false;
    }
    else
    {
        for(int i = 0; i < sizeG; i++)
        {
            if( (genre[i] == compare[i]) || (genre[i] == compare[i]+32) || (genre[i] == compare[i] -32) ) //check if each character is the same 
            {
            check = check + 1; //when character is the same, check is iterated
           
            }
        }
        
        if(check == sizeG) // if all characters of string genre match all characters of string compare
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}

/*
* This function will count all songs of a particular genre
* Parameters: string genre, array songs, int numSongsStored
* Return: int - The count of songs that match the given Genre. Return 0 if no songs match (given genre is not found) or if the array is empty or if the number of songs are invalid (like a negative number).
*/


int countGenre(string genre, Song arr[], int numSongsStored)
{

    if(numSongsStored <= 0) //checks if the array is empty or if the number of songs are invalid (like a negative number).
    {
        return 0;
    }

    int count = 0; //counts how many songs match the genre the user inputs 
    for(int i = 0; i < numSongsStored; i++)
    {
        if(isSameString(genre, arr[i].getGenre()) == true)
        {
            count++;
        }
    }
    return count;


}





int main()
{
    //  //test 1
    // Song song[50];
    // int numSongsStored = 0;
    // int songArrSize = 50;
    // int i = readSongs("songs1.txt",song, numSongsStored, songArrSize);
    // // update numSongsStored based on i
    // cout << countGenre("Rock", song, numSongsStored);   

    //test 2
    Song song[50];
    int numSongsStored = 0;
    int songArrSize = 50;
    int i = readSongs("noGenre.txt",song, numSongsStored, songArrSize);
    // update numSongsStored based on i 
    cout << countGenre("Metal", song, numSongsStored);
    
    // //test 3
    // //number of songs stored is negative
    // numSongsStored = -1;
    // cout << countGenre("grunge", song, numSongsStored) << endl;
    


    return 0;
}