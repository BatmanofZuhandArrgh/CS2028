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
        for(int i = 0; i<=StackSize; i++)
            {
            stackArray[i] = nullptr;
            delete stackArray[i];
            }}
    
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
            //cout<< "Stack is full" <<endl;
            
            T** temp = new T*[StackSize+1];
            for(int i=0;i<=top;i++){
                temp[i] = stackArray[i];
            }
            temp[top+1] = t;
            stackArray = temp;
    
            for(int i = 0; i<=StackSize; i++)
            {
                temp[i] = nullptr;
                delete temp[i];
            }
        }
        else{
            top ++;
            stackArray[top] = t;}}
    
    //Remove one item at the top
    T *pop(){
        T *t = nullptr;
        if(isEmpty()){
            cout << "The stack is empty." << endl;}
        else{
            t = stackArray[top];
            cout << "top = " << top << endl;
            top--;
            cout << "top = " << top << endl;
        }
        return t;}
    
    // Return the address of the item on top of the stack
    T * topaddress(){
        return stackArray[top];
    }
    

    
    //Delete all of stacks
    void empty(){
        if (top == -1){
            return;
        }
        while(top != 0){
            delete stackArray[top];
            stackArray[top] = nullptr;
            top--;
        }
    }
    
    //Print all results
    template <class A>
    friend A** access(HanoiTower<A>);
};

template <class A>
A ** access(HanoiTower<A> stack){
    return stack.stackArray;
}

int main() {
    
    int numDisks;
    cout<<"Enter number of disks to be used in the game: "<<endl;
    cin>>numDisks;
    
    HanoiTower<double> stack(numDisks);
    
    double Stack1 = 1;
    double Stack2 = 2;
    double Stack3 = 3;

    cout << "Pushing Stack 1" << endl;
    stack.push(&Stack1);
    cout << "Pushing Stack 2" << endl;
    stack.push(&Stack2);
    cout << "Pushing Stack 3" << endl;
    stack.push(&Stack3);
    
    cout << "The number of plates in the stack is " << stack.length()<<endl;
    
    cout << "The pointer at the top is: " << stack.topaddress()<<endl;
    
    cout << *access(stack) << endl;
    
    //access(stack);
    /*cout<<"Poping the top object!"<<endl;
    stack.pop();
    
    cout << stack.topaddress()<<endl;
    printf(stack);*/
    
    cout<<"Emptying the stack"<<endl;
    stack.empty();
    cout<< "Is the stack empty? " << stack.isEmpty() << endl;
    cout << *access(stack) << endl;
    
    return 0;
}

