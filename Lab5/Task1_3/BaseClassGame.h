// Data Structures Laboratory
// Section 004
// Lab 5
// 10/3/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#ifndef BaseClassGame_h
#define BaseClassGame_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class game
{   public:
    //Default Constructor
    game()
    {
        numplayers=0;
        score=0;}
    //Constructors
    game(int a1,int a2)
    {
        numplayers=a1;
        score=a2;
    }
    //NumPlayers Mutators
    int getNumPlayers()
    {
        return numplayers;
    }
    void setNumPlayers(int i)
    {
        numplayers=i;
    }
    //Score Mutators
    int getScore()
    {
        return score;
    }
    void setScore(int i)
    {
        score=i;
    }
    //play and winner function. Play will be overridden
    virtual void play()
    {
        cout<<"Let's Play"<<endl;
    }
    void winner()
    {
        cout<<"Not Yet"<<endl;
    }
    
private:
    int numplayers;
    int score;
};




#endif /* Class_h */

