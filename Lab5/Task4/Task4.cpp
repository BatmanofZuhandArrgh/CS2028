// Data Structures Laboratory
// Section 004
// Lab 5
// 10/3/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#include <iostream>
#include "BaseClassGame.h"
#include "DerivedClassBoardGame.h"
#include "DerivedClassVideoGame.h"
#include "fullShelf.h"
#include "emptyShelf.h"
#include "EntertainmentCollection.h"
using namespace std;

int main()
{
    shelf<game> a;
    while(true)
    {
        
        int choice;
        cout<<"\nPress 1 to add a board game to the shelf.\nPress 2 remove a board game from the shelf.\nPress 3 see how many board games are currently on the shelf.\nPress 4 to quit."<<endl;
        cin>>choice;
        
        if(choice==1)
        {
            //int size;
            int numPlayers;
            int score;
            game* b=new videogame;
            
            cout<<"\nEnter number of players: ";
            cin>>numPlayers;
            cout<<"Enter score: ";
            cin>>score;
            b->setNumPlayers(numPlayers);
            b->setScore(score);
            
            try
            {
                a.add(*b);
            }
            catch(const fullShelf& e)
            {
                cout<<e.what()<<'\n';
            }
            
        }
        else if(choice==2)
        {
            try
            {
                a.remove();
            }
            catch(const emptyShelf& e)
            {
                cout << e.what() << '\n';
            }
        }
        else if(choice==3)
        {
            cout<<"\nThere are currently "<<a.getnumStored()<<" boardgames on the shelf."<<endl;
        }
        else if(choice==4)break;
        
        
    }
    
    return 0;
}
