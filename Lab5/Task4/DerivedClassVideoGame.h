// Data Structures Laboratory
// Section 004
// Lab 5
// 10/3/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#ifndef DerivedClassVideoGame_h
#define DerivedClassVideoGame_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class videogame : public game
{
public:
    //Base class' Play() got overridden
    void play()
    {
        cout<<"Mash the buttons."<<endl;
    }
    void winner()
    {
        cout<<"Winner music"<<endl;
    }
    //getDiff mutators
    int getDiff()
    {
        return difficulty;
    }
    void setDiff(int d)
    {
        difficulty=d;
    }
    
private:
    int difficulty;
};

#endif /* DerivedClassVideoGame_h */
