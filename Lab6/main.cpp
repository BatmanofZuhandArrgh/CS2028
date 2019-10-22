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
    //Constructor
    HanoiTower(int i){
        stackArray = new T*[i];
        StackSize = i;
        top = -1;
    }
    
    //Destructor
    ~HanoiTower(){
        delete [] stackArray;
    };
    
    //Check if array is full
    bool isFull() const{
        bool status;
        if (top == StackSize - 1)
            status = true;
        else
            status = false;
        return status;
    }
    
    //Check if array is empty
    bool isEmpty() const{
        bool status;
        if (top == -1)
            status = true;
        else
            status = false;
        return status;
    }
    
    //Return the number of plates in the stacks
    int length(){
        return (top + 1);
    }
    
    //Push one element onto the back
    void push(T* t){
        if(isFull()){
            cout<< "Stack is full" <<endl;
            /*
            HanoiTower<T> temp = new T*[StackSize+1];
            for(int i=0;i<=top;i++){
                temp[i] = stackArray[i];
            }
            
            stackArray = new T*[StackSize+1];
            for(int i=0;i<temp.length();i++){
                stackArray[i] = temp[i];
            }
            top ++;
            stackArray[top] = t;
             */
        }
        else{
            top ++;
            stackArray[top] = t;}}
    
    //Remove one item at the top
    T *pop(T* t){
        if(isEmpty()){
            cout << "The stack is empty." << endl;}
        else{
            t = stackArray[top];
            top--;
        }
        return t;}
    
    // Return the address of the item on top of the stack
    T ** topaddress(){
        return &stackArray[top];
    }
    

    
    //Delete all of stacks
    void empty(){
        while(top != 0){
            delete stackArray[top];
            stackArray[top] = nullptr;
            top--;
        }
    }
    
    //Print all results
    template <class A>
    friend void printf(HanoiTower<A>);
};

template <class A>
void printf(HanoiTower<A> stack){
    int len = stack.length();
    A** top2 = stack.topaddress();
        while(len!= 0){
            cout << **top2 << endl;
            top2--;
            len--;
        }
}

int main() {
    //HanoiTower<double> stack(4);
    
    int numDisks;
    cout<<"Enter number of disks to be used in the game: "<<endl;
    cin>>numDisks;
    
    HanoiTower<double> stack(numDisks);
    //stack.push(30);
    //stack.push(31);
    
    //cout<< stack.isEmpty() << endl;

    
    return 0;
}
