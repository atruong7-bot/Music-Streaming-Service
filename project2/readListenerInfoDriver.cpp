// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #7

#include <iostream>
#include <fstream>
#include <string>
#include "Listener.h"

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

int main()
{
    // //test 1
    // int numListenersStored = 0;
    // int listenerArrSize = 50;
    // Listener listener[listenerArrSize];
    // readListenerInfo("playlist.txt", listener, numListenersStored, listenerArrSize, 50);

    //test 2
    int numListenersStored = 2;
    int listenerArrSize = 2;
    Listener listener[listenerArrSize];
    cout << readListenerInfo("morePlaylist.txt", listener, numListenersStored, listenerArrSize, 50) << endl;

    // //test 3
    // const int listenerArrSize = 2;
    // Listener listeners[listenerArrSize];
    // listeners[0].setListenerName("ritchie");
    // listeners[0].setSongsAt(0,0);
    // listeners[0].setSongsAt(1,1);
    // listeners[0].setSongsAt(2,2);
    // int numListenersStored = 1;
    // readListenerInfo("playlist2.txt",listeners,
    // numListenersStored, listenerArrSize, 50);
}