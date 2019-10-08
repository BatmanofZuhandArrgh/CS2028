
// Data Structures Laboratory
// Section 004
// Lab 4
// 9/30/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#ifndef DerivedClassBoardGame_h
#define DerivedClassBoardGame_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class boardgame : public game
{
public:
    //Base class' Play() got overridden
    void play()
    {
        cout<<"Roll the dice."<<endl;
    }
    void winner()
    {
        cout<<"Dancing time."<<endl;
    }
    
    //Size mutators
    int getSize()
    {
        return boardsize;
    }
    void setSize(int s)
    {
        boardsize=s;
    }
    
private:
    int boardsize;
};

#endif /* DerivedClassBoardGame_h */
