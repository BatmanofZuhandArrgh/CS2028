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
    T **stackArray;
    
public:
    ////////////////////
    //Constructor
    HanoiTower(int i){
        stackArray = new T*[i];
        StackSize = i;
        top = -1;
    }

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
    
    //////////////////
    // Overload the == operators
    bool operator == (const HanoiTower<T> & obj){
        if((top == obj.top) && (StackSize == obj.StackSize) &&
           (*stackArray[top] == *obj.stackArray[top]))
            return true;
        else
            return false;
    };
    
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
void displayallpoles(HanoiTower<T> stack1, HanoiTower<T> stack2, HanoiTower<T> stack3, HanoiTower<T> stack4, HanoiTower<T> stack5){
    cout << "Here are the poles: " << endl;
    cout << "1---";
    displayobject(stack1);
    cout << "2---";
    displayobject(stack2);
    cout << "3---";
    displayobject(stack3);
    cout << "4---";
    displayobject(stack4);
    cout << "5---";
    displayobject(stack5);
}

template <class T>
void popandpush(HanoiTower<T> &stack1, HanoiTower<T> &stack2) {
    if (stack2.isEmpty() || toupper(*stack2.topaddress()) >= toupper(*stack1.topaddress())){
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
    HanoiTower<char> stack4(numDisks);
    HanoiTower<char> stack5(numDisks);
    
    // Create an array of characters to input onto the poles
    char *disks=new char[numDisks];
    char *disks1 = new char[numDisks];
    
    // Populate that array with right number of disks
    for(int i=0;i<numDisks; i++)
    {
        char temp = numDisks - i + 64;
        disks[i]=temp;
    }
    
    for(int i=0;i<numDisks; i++)
    {
        char temp1 = numDisks - i + 96;
        disks1[i]=temp1;
    }
    
    // Create a winning-conditioned stacks to be compared with in the game engine
    HanoiTower<char> uppercasestack(numDisks);
    HanoiTower<char> lowercasestack(numDisks);
    
    // Create a bunch of spaces to populate the other stacks
    //char space = NULL;
    //char *n = &space;
    
    // Pushing array pointers of object into the poles
    for(int i=0;i<numDisks;i++)
    {
        stack1.push(&disks[i]);
        uppercasestack.push(&disks[i]);
        stack5.push(&disks1[i]);
        lowercasestack.push(&disks1[i]);
    }
    stack2.empty();
    stack3.empty();
    stack4.empty();
    
    
    displayallpoles(stack1, stack2, stack3, stack4, stack5);
    //cout << "Is the stack2 empty?" << stack2.isEmpty() << endl;
    
    // Create the win condition
    bool win = false;
    char polepop = ' ';
    char polepush = ' ';
    HanoiTower<char> temp1(numDisks);
    HanoiTower<char> temp2(numDisks);
    
    while (!win){
        cout << "Pick the pole to remove the plate from: (only 1,2,3,4,5)"<< endl;
        cin >> polepop;
        cout << "Pick the pole to move the plate to: (only 1,2,3,4,5)"<< endl;
        cin >> polepush;
        
        // Translate the choice polepop into the pole
        if(polepop == '1')
            temp1 = stack1;
        else if (polepop == '2')
            temp1 = stack2;
        else if (polepop == '3')
            temp1 = stack3;
        else if (polepop == '4')
            temp1 = stack4;
        else if (polepop == '5')
            temp1 = stack5;
        else{
            cout << "Please input pole names, only 1,2,3,4,5: " << endl;
            continue;
        }
        
        // Translate the choice polepush into the pole
            if(polepush == '1')
                temp2 = stack1;
            else if (polepush == '2')
                temp2 = stack2;
            else if (polepush == '3')
                temp2 = stack3;
            else if (polepush == '4')
                temp2 = stack4;
            else if (polepush == '5')
                temp2 = stack5;
            else{
                cout << "Please input pole names, only 1,2,3,4,5: " << endl;
                continue;
            }
        
        // Make sure that the choice aren't the same
        if (polepush == polepop){
            cout << "Please don't input the same pole names. This makes no sense." << endl;
            continue;
        }
    
        
        //Move the stack
        popandpush(temp1, temp2);

        //Assign the existing temp stacks
        if(polepop == '1')
            stack1 = temp1;
        else if (polepop == '2')
            stack2 = temp1;
        else if (polepop == '3')
            stack3 = temp1;
        else if (polepop == '4')
            stack4 = temp1;
        else if (polepop == '5')
            stack5 = temp1;
        
        if(polepush == '1')
            stack1 = temp2;
        else if (polepush == '2')
            stack2 = temp2;
        else if (polepush == '3')
            stack3 = temp2;
        else if (polepush == '4')
            stack4 = temp2;
        else if (polepush == '5')
            stack5 = temp2;
        
        displayallpoles(stack1, stack2, stack3, stack4, stack5);
        
        if( ((stack1.isFull() && stack1 ==lowercasestack) || (stack2.isFull() && stack2 ==lowercasestack)) &&
            ((stack4.isFull() && stack4 ==uppercasestack) || (stack5.isFull() && stack5 ==uppercasestack)) ){
            win = true;
            cout << "You won!" <<endl;
        }
    }
    
    return 420;
}


