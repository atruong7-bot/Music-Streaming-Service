// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #6

#include "Listener.h"
#include <iostream>


using namespace std;

// constructors
Listener::Listener()
{
    listenerName = "";
    for (int i = 0; i < size; i++) //initialize all elements in array to 0
    {
        playCount[i] = 0;
    }
}

Listener::Listener(string listenerName_, int playCount_[], int size_)
{
    listenerName = listenerName_;
    
    if (size_ < size) 
    {
        for (int i = 0; i < size_ ; i++) //fills part of the array, bounded by size_ (user input)
        {
            playCount[i] = playCount_[i];
        }

        for (int i = size_; i < size; i++) //fills the rest of the elements with 0
        {
            playCount[i] = 0;
        }
    }

    else if (size_ >= size)
    {
        for (int i = 0; i < size; i++) //fills all elements of playCount array, disregards anything larger than size (50)
        {
            playCount[i] = playCount_[i];
        }
    }

}

//getters/setters

string Listener::getListenerName()
{
    return listenerName;
}

void Listener::setListenerName(string setListenerName)
{
    listenerName = setListenerName;
}

int Listener::getPlayCountAt(int index1_)
{
    if ((index1_ > size - 1) || (index1_ < 0)) //if the index is greater than the last index in playCount array (playCount[49]) or negative
    {
        return -1;
    }

    return playCount[index1_];
}

bool Listener::setPlayCountAt(int index2_, int value_)
{
    if ((index2_ >= 0) && (index2_ < size) && (value_ > 0))
    {
        playCount[index2_] = value_;
        return true; //true if able to update playCount[index] to value
    }

    else
    {
        return false;
    }
}

int Listener::totalPlayCount()
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += playCount[i]; //calculates sum of all the number of plays of all songs
    }

    return total;
}

int Listener::getNumUniqueSongs()
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (playCount[i] >= 1)
        {
            count++; //counts all songs that have atleast one play
        }
    }

    return count;

}

int Listener::getSize()
{
    return size;
}







    

