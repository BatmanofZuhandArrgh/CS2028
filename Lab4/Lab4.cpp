// Data Structures Laboratory
// Section 004
// Lab 4
// 9/30/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens

#include <iostream>
#include <stdio.h>
#include <string>
#include "BaseClassGame.h"
#include "DerivedClassBoardGame.h"
#include "DerivedClassVideoGame.h"
using namespace std;

void function1(game &a){
    a.play();
    a.winner();
}
void function1(game *a){
    a->play();
    a->winner();
}

int main()
{
    game a;
    boardgame b;
    videogame c;
    game *d = new boardgame();
    game *e = new videogame();
    
    while(true)
    {
        int choice;
        char yesno;
        cout<<" Press 1 for an instance of game. \n Press 2 for an instance of board game. \n Press 3 for an instance of video game. \n Press 4 for an instance of a board game declared as a game \n Press 5 for an instance of a video game declared as a game \n";
        int i,j,k;
        
        cin>>choice;
        if(choice==1)
        {
            cout << "Please input the number of players" << endl;
            cout << "Number of players: ";
            cin >> i;
            cout << "Please input the score"<<endl;
            cout << "Score: ";
            cin >> j;
            a.setNumPlayers(j);
            a.setScore(j);
            
            a.play();
            a.winner();
            function1(a);
        }
        else if(choice==2)
        {
            cout << "Please input the number of players" << endl;
            cout << "Number of players: ";
            cin >> i;
            cout << "Please input the score"<<endl;
            cout << "Score: ";
            cin >> j;
            cout << "Please input the boardsize" << endl;
            cout << "BoardSize: ";
            cin >> k;
            b.setNumPlayers(i);
            b.setScore(j);
            b.setSize(k);
            
            b.play();
            b.winner();
            function1(b);
        }
        else if(choice==3)
        {
            cout << "Please input the number of players" << endl;
            cout << "Number of players: ";
            cin >> i;
            cout << "Please input the score"<<endl;
            cout << "Score: ";
            cin >> j;
            cout << "Please input the level of difficulty" << endl;
            cout << "Difficulty: ";
            cin >> k;
            c.setNumPlayers(i);
            c.setScore(j);
            c.setDiff(k);
            
            c.play();
            c.winner();
            function1(c);
        }
        else if(choice==4)
        {
            cout << "Please input the number of players" << endl;
            cout << "Number of players: ";
            cin >> i;
            cout << "Please input the score"<<endl;
            cout << "Score: ";
            cin >> j;
            d->setNumPlayers(i);
            d->setScore(j);
            
            d->play();
            d->winner();
            function1(*d);
        }
        else if(choice==5)
        {
            cout << "Please input the number of players" << endl;
            cout << "Number of players: ";
            cin >> i;
            cout << "Please input the score"<<endl;
            cout << "Score: ";
            cin >> j;
            e->setNumPlayers(i);
            e->setScore(j);
            
            e->play();
            e->winner();
            function1(*e);
        }
        cout<<"Would you like to continue? (y/n)"<<endl;
        cin>>yesno;
        if(yesno=='n' || yesno=='N')break;
    }
    
    return 0;
}
