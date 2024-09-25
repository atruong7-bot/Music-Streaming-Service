// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #11

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Listener.h"
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
* This function will count all the songs of the most frequent genre
* Parameters: array songs, int numSongsStored
* Return int: The count of songs of the most frequent genre. (If more than one genre has
the same highest frequency (i.e in case of a tie) then return the count of songs from
either one of them. If no songs are found then return 0.)
*/

int frequentGenreSongs(Song arr[], int numSongsStored)
{
    if (numSongsStored <= 0) //check if no songs are found or if the song array is empty or if the value of number of songs stored is invalid
    {
        return 0;
    }

    string genre[numSongsStored]; //string array filled with genre
    int numberOfGenre[numSongsStored]; //int array filled with number of songs in a genre, both arrays linked

    int temp = countGenre(arr[0].getGenre(), arr, numSongsStored); //updated in for loop

    for (int i = 0; i < numSongsStored; i++)
    {
        genre[i] = arr[i].getGenre(); //string array is filled with genre from user input Song array

        numberOfGenre[i] = countGenre(genre[i], arr, numSongsStored); //number of genre is found using countGenre function

        if (numberOfGenre[i] > temp) //loop to find the maximum number of most frequent genre
        {
            temp = numberOfGenre[i]; //the maximum is updated 
        }
    }

   

    return temp;

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


//In your driver function, you must declare your arrays with the appropriate size. 
//The capacity of the songs array is 50. The capacity of the listeners array is 100.

int main()
{
    //initialize all variables
    int option = 0;
    string file;
    Song arrSong[50];
    int songArrSize = 50;
    Listener arrListener[100];
    int listenersArrSize = 100;
    int numSongsStored = 0;
    int numListenersStored = 0;
    int totalSongs = 0;
    string genre;
    int songsGenre = 0;
    int freqGenre = 0;
    string listenerName;
    static const int numSongs = 50;
    int totalListeners = 0;
    int maxCol = 51;
    string song;
    int totalPlaysListener = 0;

    //used a do while loop to first print out menu and then accept user input

    do
    {
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read songs from file" << endl;
        cout << "2. Print all songs" << endl;
        cout << "3. Song-count by genre" << endl;
        cout << "4. Songs from most common genre" << endl;
        cout << "5. Add listener" << endl;
        cout << "6. Read listens from file" << endl;
        cout << "7. Get number of listens by a listener" << endl;
        cout << "8. Get listener statistics" << endl;
        cout << "9. Quit" << endl;
        cin >> option;

        if (option == 1)
        {
            cout << "Enter a song file name: " << endl;
            cin >> file;

            totalSongs = readSongs(file, arrSong, numSongsStored, songArrSize); //for organization purposes

            //numSongsStored is constantly updated as the user inputs a file
            
            //if cases
            if (totalSongs == -1) //check if no songs are saved first
            {
                cout << "No songs saved to the database." << endl;
                numSongsStored = 0;
            }

            else //else means that there are songs saved
            { 
                if (totalSongs == -2) //check if numSongsStored is full, if (numSongsStored == songArrSize)
                {
                    cout << "Database is already full. No songs were added." << endl;
                    numSongsStored = songArrSize; // 50
                }
                
                else //if numSongsStored is not full 
                {
                    cout << "Total songs in the database: " << totalSongs << endl;
                    numSongsStored = totalSongs; //total songs is how many songs are currently in the data base, so numSongsStored is updated
                    
                    if (totalSongs == songArrSize) //if numSongsStored becomes full after calling function
                    {
                        cout << "Database is full. Some songs may have not been added." << endl;
                        numSongsStored = songArrSize; //50
                    }
                }    
            }

        }
        
        else if (option == 2)
        {
            printAllSongs(arrSong, numSongsStored); //just prints the songs
        }

        else if (option == 3)
        {
            cout << "Genre:" << endl;
            cin >> genre;

            songsGenre = countGenre(genre, arrSong, numSongsStored); //for organization purposes

            cout << "Total " << genre << " songs in the database: " << songsGenre << endl; 
        }

        else if (option == 4)
        {
            freqGenre = frequentGenreSongs(arrSong, numSongsStored); //for organization purposes
            cout << "Number of songs in most common Genre: " << freqGenre << endl;
        }

        else if (option == 5)
        {
            cout << "Enter a listener name: " << endl;
            cin.ignore();
            getline(cin, listenerName); //used getline to take in whole string including spaces
            
            totalListeners = addListener(listenerName, arrListener, numSongs, numListenersStored, listenersArrSize); //for organization purposes

            //if cases

            if (totalListeners == -1)
            {
                cout << "Database is already full. Listener cannot be added." << endl;
                numListenersStored = listenersArrSize; //like numSongsStored, this varible is constantly updated
            }

            else if (totalListeners == -2)
            {
                cout << "Listener already exists." << endl;
            }

            else if (totalListeners == -3)
            {
                cout << "The listenerName is empty." << endl;
                numListenersStored = 0;
            }

            else
            {
                cout << "Welcome, " << listenerName << "!" << endl;
                numListenersStored = totalListeners; //numListenersStored is updated each time the user adds a new listener
            }

        }

        else if (option == 6)
        {
            cout << "Enter the listener info file name: " << endl;
            cin >> file;

            totalListeners = readListenerInfo(file, arrListener, numListenersStored, listenersArrSize, maxCol); //for organization purposes

            //if cases

            if (totalListeners == -1)
            {
                cout << "Nothing saved to the database." << endl;
            }

            else if (totalListeners == -2)
            {
                
                cout << "Database is already full. Nothing was added." << endl;
            }

            else if (totalListeners == listenersArrSize)
            {
                cout << "Total listeners in the database: " << totalListeners << endl;
                cout << "Database is full. Some listeners may have not been added." << endl;
            }

            else 
            {
                cout << "Total listeners in the database: " << totalListeners << endl;
                numListenersStored = totalListeners; //numListeners stored is updated after calling function
            }


        }

        else if (option == 7)
        {
            cout << "Enter a listener name: " << endl;
            cin.ignore();
            getline(cin, listenerName); //used getline to take in whole string including spaces

            cout << "Enter a song name: " << endl;
            getline(cin, song); //used getline to take in whole string including spaces

            totalPlaysListener = getSongPlayCount(listenerName, song, arrListener, arrSong, numListenersStored, numSongsStored);

            //if cases

            if (totalPlaysListener == -1)
            {
                cout << song << " does not exist." << endl;
            }

            else if (totalPlaysListener == -2)
            {
                cout << listenerName <<  " does not exist." << endl;
            }

            else if (totalPlaysListener == -3)
            {
                cout << listenerName << " and " << song << " do not exist." << endl;
            }

            else 
            {
                cout << listenerName << " has listened to " << song << " " << totalPlaysListener << " times." << endl;
            }
        }

        else if (option == 8)
        {
            cout << "Enter a listener name: " << endl;
            cin >> listenerName;

            getListenerStats(listenerName, arrListener, numListenersStored, numSongs); //calling this function will print stuff (apart of function)

        }

        else if (option == 9)
        {
            cout << "Good bye!" << endl;
            return 0;
        }

        else //if user inputs something other than 1 - 9
        {
            cout << "Invalid input." << endl;
        }

    } 
    while (option != 9); //as long as the user does not input 9 which is quit, this loop will keep running
    

    return 0;
}




