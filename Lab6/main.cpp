// Data Structures Laboratory
// Section 004
// Lab 6
// 10/25/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens




/////////////////////////////////
//TO MAKE THINGS CLEAR, THIS FILE IS JUST THE IMPLEMENTATION OF CLASS QUEUE AND STRUCT MOVES
//IT HAS NOTHING TO DO WITH THE GAME, WHICH WILL BE COMBINED WITH THIS IN FILE LAB6TASK1GAME

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct moves{
    char popfrom;
    char pushto;
};

template <class T>
class queue {
private:
    int temp;
    vector<T> actionqueue;
    
public:
    
    ///////////////////////////////
    //Default constructor
    queue(){
        actionqueue;
    }
    
    ///////////////////////////////
    //Destructor
    //~queue();
    
    ///////////////////////////////
    //Queuefunctions
    bool isEmpty();
    int vectorsize();
    void enqueue(T);
    T dequeue();
    void clear();
    
    template <class A>
    A friend access(queue<A>, int);
};

template<class T>
bool queue<T>::isEmpty(){
    if (actionqueue.size() == 0)
    return true;
    else
        return false;
}


template<class T>
int queue<T>::vectorsize(){
    return actionqueue.size();
}

template<class T>
void queue<T>::enqueue(T action){
        actionqueue.push_back(action);
}

template <class T>
T queue<T>::dequeue() {
    T temp = actionqueue[0];
    actionqueue.erase(actionqueue.begin());
    return temp;
}

template <class T>
void queue<T>::clear(){
    for (int i = 0; i < actionqueue.size(); i++){
        actionqueue.pop_back();
    }
}

template<class A>
A access(queue<A> ListofMoves, int i){
    return ListofMoves.actionqueue[i];
}

void displayallmoves(queue<moves> ListofMoves){
    for (int i = 0; i < ListofMoves.vectorsize(); i++){
        cout << access(ListofMoves, i).popfrom << "---->" << access(ListofMoves, i).pushto << endl;
    }
}
    
int main() {
    queue<moves> ListofMoves;
    moves Move1 = {'1','2'};
    moves Move2 = {'2','3'};
    moves Move3 = {'4','5'};
    ListofMoves.enqueue(Move1);
    ListofMoves.enqueue(Move2);
    ListofMoves.enqueue(Move3);
    
    cout << "The size of the vector is: " << ListofMoves.vectorsize()<< endl;
    
    displayallmoves(ListofMoves);
    
    cout << "Dequeueing the list"<< endl;
    ListofMoves.dequeue();
    
    cout << "The size of the vector is: " << ListofMoves.vectorsize()<< endl;
    
    displayallmoves(ListofMoves);
    cout << "Is the vector empty?" << ListofMoves.isEmpty() << endl;
    
    
    
    cout << "Clearing all vectors" << endl;
    cout << "Is the vector empty?" << ListofMoves.isEmpty() << endl;
    
    
    return 0;
}
