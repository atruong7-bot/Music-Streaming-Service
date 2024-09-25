// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #9

#include <iostream>
#include <fstream>
#include <string>
#include "Listener.h"

using namespace std;

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
* This function adds a listener to the listeners array
* Parameters: string listenerName, array listeners, int numSongs, int numListenersStored, int listenersArrSize
* Return: int number of listeners in array
*/

int addListener(string listenerName, Listener arr[], const int numSongs = 50, int numListenersStored = 0, int listenersArrSize = 100)
{


    if (numListenersStored >= listenersArrSize) //case 1, listener array is full
    {
        return -1;
    }
    else
    {
        int checkListenerExist = 0; //used to check if there is already a listener of the same name in the array, will stay 0 if there is not 

        for (int i = 0; i < numListenersStored; i++) //traverse through Listener array to find string ListenerName
        {
            if(isSameString(listenerName, arr[i].getListenerName()) == true) 
            {
                checkListenerExist++; 
            }
        }
        

        if (checkListenerExist != 0) //case 2, listener exists
        {
            return -2;
        }

        if (listenerName == "") // case 3, empty string
        {
            return -3;
        }

        else 
        {   
            Listener addToArray; //adding new listener to listener array
            addToArray.setListenerName(listenerName); //set listener name

            for (int i = 0; i < numSongs + 1; i++)  // fills all 50 elements of playCount array to 0
            {
                addToArray.setPlayCountAt(i, 0);
            }
            
            arr[numListenersStored] = addToArray; //next position in Listener array = numListenersStored (position of arrays start at 0)

            return numListenersStored + 1; //since were adding a new listener, the total listeners after we add them is gonna be numListenersStored + 1
        }
    }

}

int main()
{
    // //test 1
    // // Add when array is full
    // Listener listeners[1];
    // int listenerArrSize = 1;
    // int numSongs  = 5;

    // listeners[0].setListenerName("Ninja");

    // // Add 5 listens by the user "Ninja"
    // for(int i=0; i<numSongs; i++) 
    // {
    //     listeners[0].setPlayCountAt(i, i);
    // }

    // int numListenersStored = 1;

    // cout<<addListener("Knuth", listeners, numSongs, numListenersStored, listenerArrSize)<<endl;

    //test 2
    // Normal use
    Listener listeners[2];
    int listenerArrSize = 2;
    int numSongs  = 5;

    listeners[0].setListenerName("Ninja");

    // Add 5 listens by the user "Ninja"
    for(int i=0; i<numSongs; i++) 
    {
        listeners[0].setPlayCountAt(i, i);
    }

    int numListenersStored = 1;

    cout<<addListener("Knuth", listeners, numSongs, numListenersStored, listenerArrSize)<<endl;

    // //test 3
    // // Add empty string
    // Listener listeners[2];
    // int listenerArrSize = 2;
    // int numSongs  = 5;

    // listeners[0].setListenerName("Ninja");

    // // Add 5 listens by the user "Ninja"
    // for(int i=0; i<numSongs; i++) 
    // {
    //     listeners[0].setPlayCountAt(i, i);
    // }

    // int numListenersStored = 1;

    // cout<<addListener("", listeners, numSongs, numListenersStored, listenerArrSize)<<endl;

    return 0;
}