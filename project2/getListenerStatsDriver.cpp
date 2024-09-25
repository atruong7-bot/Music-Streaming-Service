// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #10

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Listener.h"

using namespace std;

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
* This function given a listener’s name, prints the number of unique songs that
listener has listened to, and the listener’s average number of listens per song listened to
* Parameters: string listenerName, array of Listener objects, int numListenersStored, int numListenersStored
* Return: int number unique songs that listener has listened to, and the listener’s average number of listens per song listened to
*/

int getListenerStats(string listenerName, Listener arr[], int numListenersStored, int numSongs)
{
    int check = 0; //used to check if a listener is found
    int positionListener = 0; 
    int numberOfUniqueSongs = 0; 
    double totalNumberOfListens = 0;
    double averageNumberOfListens = 0;

    for (int i = 0; i < numListenersStored; i++) //traverse through Listener array to find string ListenerName
    {
        if(isSameString(listenerName, arr[i].getListenerName()) == true) 
        {
            positionListener = i; //position of string ListenerName in Listener array
            check++; 
        }
    }

    if (check != 0) //if a listener is found
    {

        if (arr[positionListener].totalPlayCount() == 0) //first check if the listener has listened to any songs, (if total play count = 0)
        {
            cout << listenerName << " has not listened to any songs." << endl;
        
            return 0;
        }

        for (int j = 0; j < numSongs; j++) //this loop is specific to the average, only adds to total if the song is a unique song 
        {   
            if (arr[positionListener].getPlayCountAt(j) >= 1)
            {
                totalNumberOfListens += arr[positionListener].getPlayCountAt(j);
            }
        }

        numberOfUniqueSongs = arr[positionListener].getNumUniqueSongs(); //getNumUniqeSongs is used from the .h and .cpp file, apart of Listener class
        cout << listenerName << " listened to " << numberOfUniqueSongs << " songs." << endl;

        averageNumberOfListens = totalNumberOfListens / numberOfUniqueSongs;
        cout << listenerName << "'s average number of listens was " << fixed << setprecision(2) << averageNumberOfListens << endl;

        return 1;
    }

    else //listener not found
    {
        cout << listenerName << " does not exist." << endl;

        return -3;
    }


}

int main()
{
    //test 1
    //Q 10 tests
    // 1
    //Creating 3 listeners
    Listener listeners[3];

    //Setting name and listens for Person1
    listeners[0].setListenerName("Person1");
    listeners[0].setPlayCountAt(0,1);
    listeners[0].setPlayCountAt(1,4);
    listeners[0].setPlayCountAt(2,2);

    //Setting name and listens for Person 2
    listeners[1].setListenerName("Person2");

    //Setting name and listens for Person 3
    listeners[2].setListenerName("Person3");
    listeners[2].setPlayCountAt(0,0);
    listeners[2].setPlayCountAt(1,0);
    listeners[2].setPlayCountAt(2,0);

    cout << getListenerStats("Person1", listeners, 3, 3)<<endl;
    cout << getListenerStats("Person2", listeners, 3, 3)<<endl;
    cout << getListenerStats("Person4", listeners, 3, 3)<<endl;

    // //test 2
    // // User not found
    // Listener listeners[1];

    // //Setting name and listens for Person1
    // listeners[0].setListenerName("Person1");
    // listeners[0].setPlayCountAt(0,1);
    // listeners[0].setPlayCountAt(1,4);
    // listeners[0].setPlayCountAt(2,2);

    // cout << getListenerStats("Madhu", listeners, 1, 3) << endl;

    // //test 3
    // // User has not listened to any songs
    // Listener listeners[1];

    // //Setting username and ratings for User1
    // listeners[0].setListenerName("David");

    // cout << getListenerStats("David", listeners, 1, 3) << endl;

    // //test 3
    // //Check for setPrecision; correct average calculation if a user didn't listen to a song
    // Listener listeners[3];

    // //Setting name and listens for Person1
    // listeners[0].setListenerName("Person1");
    // listeners[0].setPlayCountAt(0,0);
    // listeners[0].setPlayCountAt(1,5);
    // listeners[0].setPlayCountAt(2,3);

    // //Setting name and listens for Person 2
    // listeners[1].setListenerName("Person2");

    // //Setting name and listens for Person 3
    // listeners[2].setListenerName("Person3");
    // listeners[2].setPlayCountAt(0,3);
    // listeners[2].setPlayCountAt(1,1);
    // listeners[2].setPlayCountAt(2,1);

    // cout << getListenerStats("Person1", listeners, 3, 3)<<endl;
    // cout << getListenerStats("Person2", listeners, 3, 3)<<endl;
    // cout << getListenerStats("Person3", listeners, 3, 3)<<endl;
}