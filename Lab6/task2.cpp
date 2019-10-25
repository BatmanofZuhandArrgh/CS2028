//
//  main.cpp
//  Lab6
//
//  Created by Macbook on 10/16/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <iostream>
using namespace std;

template < class T >
class HanoiTower{
private:
    int StackSize;
    int top;
    //T **stackArray;
    
public:
    T **stackArray;
    ////////////////////
    //Constructor
    HanoiTower(int i){
        stackArray = new T*[i];
        StackSize = i;
        top = -1;
    }
    /*
     ////////////////////
     //Destructor
     ~HanoiTower(){
     for(int i = 0; i<=StackSize; i++)
     {
     stackArray[i] = nullptr;
     delete stackArray[i];
     }
     delete stackArray;
     }*/
    
    ////////////////////
    //Check if array is full
    bool isFull() const{
        bool status;
        if (top == StackSize - 1)
            status = true;
        else
            status = false;
        return status;
    }
    
    ////////////////////
    //Check if array is empty
    bool isEmpty() const{
        bool status;
        if (top == -1)
            status = true;
        else
            status = false;
        return status;
    }
    
    ////////////////////
    //Return the number of plates in the stacks
    int length(){
        return (top + 1);
    }
    
    ////////////////////
    //Push one element onto the back
    void push(T* t){
        if(length() == StackSize){
            cout<< "Stack is full" <<endl;
            /*T** temp = new T*[StackSize+1];
             for(int i=0;i<=top;i++){
             temp[i] = stackArray[i];
             }
             temp[top+1] = t;
             stackArray = temp;
             
             for(int i = 0; i<=StackSize; i++)
             {
             temp[i] = nullptr;
             delete temp[i];
             }*/
        }
        else{
            top ++;
            stackArray[top] = t;}}
    
    ////////////////////
    //Remove one item at the top
    T *pop(){
        T *t = nullptr;
        if(length() == 0){
            cout << "The stack is empty." << endl;}
        else{
            t = stackArray[top];
            top--;
        }
        return t;}
    
    ////////////////////
    // Return the address of the item on top of the stack
    T * topaddress(){
        return stackArray[top];
    }
    
    
    ////////////////////
    //Delete all of stacks
    void empty(){
        if (top == -1){
            return;
        }
        while(top != -1){
            stackArray[top] = nullptr;
            delete stackArray[top];
            top--;
        }
    }
    
    ////////////////////
    //Print all results
    template <class A>
    friend void displayobject(HanoiTower<A>);
    
    template <class B>
    friend void displaypointer(HanoiTower<B>);
    
    template <class C>
    friend C accessobject(HanoiTower<C>, int);
    
};

//Displaying all the objects the pointers in the Stack array are pointing at
template <class A>
void displayobject(HanoiTower<A> stack){
    for (int i = 0; i<= stack.top; i++){
        cout << *stack.stackArray[i] << " ";
    }
    cout << endl;
}

//Displaying all the pointers in the Stack array
template <class B>
void displaypointer(HanoiTower<B> stack){
    for (int i = 0; i<= stack.top; i++){
        cout << *stack.stackArray[i] << " ";
    }
    cout << endl;
}

//Trying to access a particular element inside the stackArray
template <class C>
C accessobject(HanoiTower<C> stack, int i){
    return (*stack.stackArray[i]);
}

template <class T>
void displayallpoles(HanoiTower<T> stack1, HanoiTower<T> stack2, HanoiTower<T> stack3){
    cout << "Here are the poles: " << endl;
    cout << "A---";
    displayobject(stack1);
    cout << "B---";
    displayobject(stack2);
    cout << "C---";
    displayobject(stack3);
}

template <class T>
void popandpush(HanoiTower<T> &stack1, HanoiTower<T> &stack2) {
    if (stack2.isEmpty() || (*stack2.topaddress())>(*stack1.topaddress())){
        stack2.push(stack1.topaddress());
        stack1.pop();
    }
    else{
        cout << "Illegal move, please input pole names again." << endl;
    }
}

int main() {
    
    // Determine the number of disks in the game
    int numDisks = 12;
    while(numDisks>9 || numDisks <=0){
    cout<<"Enter number of disks to be used in the game: (Fewer than 9 disks, pls)"<<endl;
    cin>>numDisks;
    }
    cout << endl;
    
    //Creating 3 stacks representing 3 poles
    HanoiTower<char> stack1(numDisks);
    HanoiTower<char> stack2(numDisks);
    HanoiTower<char> stack3(numDisks);
    
    // Create an array of characters to input onto the poles
    char *disks=new char[numDisks];
    
    // Populate that array with right number of disks
    for(int i=0;i<numDisks; i++)
    {
        char temp = numDisks - i + 48;
        disks[i]=temp;
    }
    
    // Create a bunch of spaces to populate the other stacks
    //char space = NULL;
    //char *n = &space;

    // Pushing array pointers of object into the poles
    for(int i=0;i<numDisks;i++)
    {
        stack1.push(&disks[i]);
    }
    stack2.empty();
    stack3.empty();
    
    
    displayallpoles(stack1, stack2, stack3);
    //cout << "Is the stack2 empty?" << stack2.isEmpty() << endl;

    // Create the win condition
    bool win = false;
    char polepop = ' ';
    char polepush = ' ';
    
    while (!win){
        cout << "Pick the pole to remove the plate from: (A,B,C)"<< endl;
        cin >> polepop;
        
        cout << "Pick the pole to move the plate to: (A,B,C)"<< endl;
        cin >> polepush;
        
        //Move the stack
        if (polepop == 'A' && polepush == 'B'){
            popandpush(stack1, stack2);
        }
        else if (polepop == 'B' && polepush == 'A'){
            popandpush(stack2, stack1);
        }
        else if (polepop == 'A' && polepush == 'C'){
            popandpush(stack1, stack3);
        }
        else if (polepop == 'C' && polepush == 'A'){
            popandpush(stack3, stack1);
        }
        else if (polepop == 'B' && polepush == 'C'){
            popandpush(stack2, stack3);
        }
        else if (polepop == 'C' && polepush == 'B'){
            popandpush(stack3, stack2);
        }
        else{
            cout << "Please input pole names, only A, B and C: " << endl;
        }
        
        if(stack3.isFull()){
            win = true;
            cout << "You won!" <<endl;
        }
        displayallpoles(stack1, stack2, stack3);
    }
    
    return 420;
}

