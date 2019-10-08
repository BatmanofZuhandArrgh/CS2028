//
//  EntertainmentCollection.h
//  Lab5Task4
//
//  Created by Macbook on 10/8/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#ifndef EntertainmentCollection_h
#define EntertainmentCollection_h
#include "BaseClassGame.h"
#include "fullShelf.h"
#include "emptyShelf.h"
#include "DerivedClassBoardGame.h"
#include "DerivedClassVideoGame.h"
#include <iostream>
#include <array>
using namespace std;

const static int numGames=10;

template <class T>
class shelf
{
public:
    
    bool isEmpty;
    shelf()
    {
        //set every "game" existing in the games array as default empty game
        for(int i=0;i<games.size();i++)
        {
            games[i]=T{};
        }
        
        //Initialize empty shelf
        numStored=0;
    }
    
    void add(T game)
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
    
    T remove()
    {
        emptyShelf s;
        if(numStored==0)
        {
            throw s;
            return T{};
        }
        
        T temp=games[numStored-1];
        games[numStored]=T{};
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
    array<T,numGames> games;
    int numStored;
};

#endif /* EntertainmentCollection_h */
