//
//  main.cpp
//  Lab7
//
//  Created by Macbook on 10/29/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;
template <class T>
class LinkedList {
private:
    struct ListNode{
        T value;
        struct ListNode * next;
    };
    ListNode* head;
    
public:
    //Constructor
    LinkedList(){
        head = nullptr;
    }
    
    //Destructor
    ~LinkedList();
    
    //Linked
    void AddItems(T);
    T* GetItems(T);
    bool IsInList(T);
    bool IsEmpty();
    int size();
    T seeNext(int);
    T seeAt(int);
};


//LinkedList Operations:
template <class T>
void LinkedList<T>::AddItems(T item) {
    ListNode * NodePtr;
    ListNode * NewNode;
    
    //Creating a new node
    NewNode = new ListNode;
    NewNode->value = item;
    NewNode->next = nullptr;
    
    if(!head)
        head = NewNode;
    else{
        NodePtr = head;
        while(NodePtr->next){
            NodePtr = NodePtr->next;
        }
        NodePtr->next = NewNode;
    }
}

template <class T>
T * LinkedList<T>::GetItems(T item) {
    ListNode *NodePtr;
    ListNode * PreviousNode = nullptr;
    ListNode * ReturnNode;
    if(!head)
        return;
    
    //If the item is at the head, then remove it and attach
    if (head->value == item){
        NodePtr = head->next;
        ReturnNode = head;
        delete head;
        head = NodePtr;
    }
    else{
        //Initialize Nodeptr at head
        NodePtr = head;
        
        while(NodePtr != nullptr && NodePtr->value != item){
            PreviousNode = NodePtr;
            NodePtr = NodePtr->next;
        }
        if (NodePtr){
            PreviousNode->next = NodePtr->next;
            ReturnNode = NodePtr;
            delete NodePtr;
        }
    }
    return *ReturnNode;
}

template <class T>
bool LinkedList<T>::IsInList(T item) {
    ListNode * NodePtr;
    ListNode * NewNode;
    if(!head)
        return false;
    else{
        NodePtr = head;
        while(NodePtr->next){
            if (NodePtr->value == item){
                return true;
            }
            NodePtr = NodePtr->next;
        }
    }
    return false;
}

int main() {
    return 0;
}
