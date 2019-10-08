// Data Structures Laboratory
// Section 004
// Lab 5
// 10/3/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#ifndef shelf_h
#define shelf_h

#include "BaseClassGame.h"
#include "fullShelf.h"
#include "emptyShelf.h"
#include "DerivedClassBoardGame.h"
#include "DerivedClassVideoGame.h"
#include <iostream>
#include <array>
using namespace std;

const static int numGames=10;

class shelf
{
public:
    
    bool isEmpty;
    shelf()
    {
        //set every "game" existing in the games array as default empty game
        for(int i=0;i<games.size();i++)
        {
            games[i]=game{};
        }
        
        //Initialize empty shelf
        numStored=0;
    }
    
    void add(game game)
    {
        fullShelf s;
        if(numStored==games.size())
        {
            throw s;
            return;
        }
        //Add the game as the game at the end
        games[numStored]=game;
        numStored+=1;
    }
    
    game remove()
    {
        emptyShelf s;
        if(numStored==0)
        {
            throw s;
            return game{};
        }
        
        game temp=games[numStored-1];
        games[numStored]=game{};
        if(numStored>0)
            numStored-=1;
        
        cout<<"\nThe values for the removed game were as follows... \nNumber of players: "<<temp.getNumPlayers()<<"\nScore: "<<temp.getScore()<<"\n";
        
        return temp;
    }
    
    int getnumStored()
    {
        return numStored;
    }
    
private:
    array<game,numGames> games;
    int numStored;
};

#endif /* Shelf_h */
