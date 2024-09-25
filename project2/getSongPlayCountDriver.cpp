// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #8

#include <iostream>
#include <fstream>
#include <string>
#include "Listener.h"
#include "Song.h"

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
* This function loads the listener logs by reading the playlist.txt file. 
* Parameters: string filename, array listeners, int numListenersStored, int listenerArrSize, int maxCol
* Return: int number of listeners in array
*/

int readListenerInfo(string filename, Listener arr[], int numListenersStored, int listenerArrSize = 100, int maxCol = 51)
{
    if (numListenersStored >= listenerArrSize) //If numListenersStored is greater than or equal to the Listener array size
    {
        return -2;
    }
    
    ifstream file;
    file.open(filename);

    if (file.fail() == true) 
    {
        return -1;
    }

    string line; //used for getline

    int count = 0; //checks if file is empty

    while (getline(file, line) && (numListenersStored < listenerArrSize)) //only gets line if number of listeners in array (iterated each time in loop) is less than array size
    {
        
        string arrColumn[maxCol]; //reinitialized each loop
        
        if (line == "") //if line is empty
        {
            continue; //empty lines are not added to array
        }

        if (line != "") //if line has stuff in it
        {
            
            count++; 
            
            
            int actualNumberColumns = split (line, ',', arrColumn, maxCol); //"split" function returns number of pieces 

            
            if (maxCol < actualNumberColumns)
            {
                
                Listener addToArray; //adding new listener to listener array
                addToArray.setListenerName(arrColumn[0]); //first element of each line is the name

                for (int i = 0; i < maxCol; i++) //fills the whole playCount array
                {
                    addToArray.setPlayCountAt(i, stoi(arrColumn[i + 1])); 
                }

                arr[numListenersStored] = addToArray; //next position in Listener array = numListenersStored (position of arrays start at 0)
                numListenersStored++; //updates how many listeners are stored in the array
            }
            
            else
            {
                
                string arrColumn2[actualNumberColumns]; //different array, reinitialized each loop
                
                split (line, ',', arrColumn2, actualNumberColumns); //takes input from file and puts it into array

                Listener addToArray; //adding new listener to listener array
                addToArray.setListenerName(arrColumn2[0]); //first element of each line is the name

                for (int i = 0; i < actualNumberColumns - 1; i++)  // fills part of playCount array, i < actualNumberColumns - 1 because we don't want the name of the listener, so actual elements - 1 is the bound
                {
                    addToArray.setPlayCountAt(i, stoi(arrColumn2[i + 1]));
                }

                arr[numListenersStored] = addToArray; //next position in Listener array = numListenersStored (position of arrays start at 0)
                numListenersStored++;  //updates how many listeners are stored in the array
            }
        }
    }
    
    if (count == 0) //empty file
    {
        return 0;
    }

    return numListenersStored;
}

/*
* This function, given a listener’s name and a song’s name, returns the total number of plays of that song played by that listener.
* Parameters: string listener name, string song name, Array of Listener objects listeners, Array of Song objects songs, int number of listeners currently stored in the listeners array, int number of songs currently stored the songs array
* Return: int total number of plays of a song by a listener
*/

int getSongPlayCount(string listenerName, string songName, Listener arrListener[], Song arrSong[], int numListenersStored, int numSongsStored)
{
    int check = 0; //used to check if either both listener and song name are found or none are found 
    int check2 = 0; //used to check if the listener name is found but the song name is not found and if the listener name is not found but the song name is found
    int positionListener = 0;
    int positionSong = 0;
    int totalPlaysByListener = 0;



    for (int i = 0; i < numListenersStored; i++) //traverse through Listener array to find string ListenerName
    {
        if(isSameString(listenerName, arrListener[i].getListenerName()) == true) 
        {
            positionListener = i; //position of string ListenerName in Listener array
            check++; 
            check2 = 1;
        }
    }

    for (int j = 0; j < numSongsStored; j++) //traverse through Song array to find string songName
    {
        if (isSameString(songName, arrSong[j].getTitle()) == true)
        {
            positionSong = j; //position of string songName in Song array
            check++;
            check2 = 2;
        }
    }
    
    if (check == 0) //check if none are found first before anything else
    {
        return -3;
    }

    else if (check == 2)
    {
        totalPlaysByListener = arrListener[positionListener].getPlayCountAt(positionSong); //gets the value of playcount of a listener at index positionSong

        if (totalPlaysByListener == 0) //if value of play count is 0
        {
            return 0;
        }
        else
        {
            return totalPlaysByListener;
        }
    }


    //if statements for the cases   

    else if ((check2 == 1) || (numSongsStored == 0)) //if the listener name is found but the song name is not found; this also applies if the song file is empty.
    {
        return -1;
    }

    else //if the listener name is not found but the song name is found; this also applies if the listener file is empty
    {
        return -2;
    }

}

int main()
{
    // //test 1
    // // Returns play count succesfully
    // Song songs[50];
    // int numSongsStored = readSongs("songs2.txt", songs, 0, 50);
    // int numListenersStored = 0;
    // int listenerArrSize = 50;
    // Listener listener[listenerArrSize];
    // numListenersStored = readListenerInfo("playlist.txt", listener, numListenersStored, listenerArrSize, 50);
    // cout<<getSongPlayCount("John", "Goodbye Yellow Brick Road", listener, songs, numListenersStored, numSongsStored)<<endl;

    //test 2
    //Listener does not exist
    Song songs[50];
    int numSongsStored = readSongs("songs2.txt", songs, 0, 50);
    int numListenersStored = 0;
    int listenerArrSize = 50;
    Listener listener[listenerArrSize];
    numListenersStored = readListenerInfo("listenerInfo.txt", listener, numListenersStored, listenerArrSize, 50);
    cout<<getSongPlayCount("Gene", "Goodbye Yellow Brick Road", listener, songs, numListenersStored, numSongsStored)<<endl;

    // //test 3
    // //listener not present
    // Song songs[50];
    // int numSongsStored = readSongs("50Songs.txt", songs, 0, 50);
    // int numListenersStored = 0;
    // int listenerArrSize = 50;
    // Listener listener[listenerArrSize];
    // numListenersStored = readListenerInfo("emptyFile.txt", listener, numListenersStored, listenerArrSize, 51);
    // cout<<getSongPlayCount("John", "Warm Ride", listener, songs, numListenersStored, numSongsStored)<<endl;

    return 0;
}