// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #6


#ifndef LISTENER.H //preprocessor activites, when compiling turn these into comments so compilation works
#define LISTENER.H 

#include <string>
using namespace std;

class Listener
{
    private: //members that cannot be accessed without public functions
    string listenerName;
    static const int size = 50;
    int playCount[size];
    

    public: //members that can access private members
    Listener();
    Listener(string listenerName, int playCount[], int size);
    string getListenerName();
    void setListenerName(string name);
    int getPlayCountAt(int index1);
    bool setPlayCountAt(int index2, int value);
    int totalPlayCount();
    int getNumUniqueSongs();
    int getSize();
    


};


#endif