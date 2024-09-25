// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 2 - Problem #6

#include <iostream>
#include <fstream>
#include "Listener.h" //copies content

using namespace std;

int main()
{
    //test 1
    // Checking Paramterized Constructor
    int playCount[] = {3,4,5};
    Listener listener= Listener("Al", playCount, 3);
    cout << listener.getListenerName() << endl;
    cout << "getPlayCountAt(0) = " << listener.getPlayCountAt(0) << endl;
    cout << "getPlayCountAt(1) = "<< listener.getPlayCountAt(1) << endl;
    cout << "getPlayCountAt(2) = "<< listener.getPlayCountAt(2) << endl;
    cout << "getPlayCountAt(9) = "<< listener.getPlayCountAt(9) << endl;
    cout << "getPlayCountAt(29) = "<< listener.getPlayCountAt(29) << endl;
    cout << "getPlayCountAt(49) = "<< listener.getPlayCountAt(49) << endl;
    cout << "getPlayCountAt(-9) = "<< listener.getPlayCountAt(-9) << endl;
    cout << "getPlayCountAt(-29) = "<< listener.getPlayCountAt(-29) << endl;
    cout << "getPlayCountAt(52) = "<< listener.getPlayCountAt(52) << endl;
    
    // //test 2
    // //Checking Getter for Total Song Count
    // Listener listener= Listener();
    // listener.setListenerName("Jimmy");
    // for(int i=0; i<listener.getSize(); i+=10)
    // listener.setPlayCountAt(i,i);
    // cout << listener.getListenerName() << "'s Total Song Count is: " << listener.totalPlayCount() << endl;  

    // //test 3
    // // Checking Getter for Number of Unique Songs
    // Listener listener = Listener();
    // listener.setListenerName("Jimmy");
    // for(int i=1; i<listener.getSize(); i+=10)
    // listener.setPlayCountAt(i,i);
    // cout << listener.getListenerName() << "'s Number of Unique Songs is: " << listener.getNumUniqueSongs() << endl;
}