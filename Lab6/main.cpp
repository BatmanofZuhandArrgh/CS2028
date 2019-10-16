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
    static int top;
    T **stackArray;
    
public:
    //Constructor
    HanoiTower(int i){
        stackArray = new T[i];
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
    
    //Push one element onto the back
    void push(T* t){
        if(isFull()){
            cout << "The array is full." << endl;
            stackArray = new T[StackSize+1];
            top ++;
            stackArray[top] = t;
        }
        else{
            top ++;
            stackArray[top] = t;}}
    
    //Remove one item at the top
    T pop(T* t){
        if(isEmpty()){
            cout << "The stack is empty." << endl;}
        else{
            t = stackArray[top];
            top--;
        }
        return t;}
    
    //Return the number of plates in the stacks
    int length(){
        return (top + 1);
    }
    
    
    void empty(){
        while(top != 0){
            delete stackArray[top];
            top--;
        }
    }
        
    friend void print(){
        int top1 = top;
        while(top1 != 0){
            cout << stackArray[top1] << endl;
            top1--;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
