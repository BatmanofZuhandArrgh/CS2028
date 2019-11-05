//
//  main.cpp
//  Lab7
//
//  Created by Macbook on 10/29/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

struct superheroes{
    string Name;
    int num;
    
    // Overloading ==
    bool operator == (const superheroes & obj){
        if(num == obj.num)
            return true;
        else
            return false;
    };
    
    // Overloading >
    bool operator > (const superheroes & obj){
        if(num > obj.num)
            return true;
        else
            return false;
    };
    
    // Overloading <
    bool operator < (const superheroes & obj){
        if(num < obj.num)
            return true;
        else
            return false;
    };
    
    // Overloading !=
    bool operator != (const superheroes & obj){
        if(num != obj.num)
            return true;
        else
            return false;
    };
    
};

template <class T>
class LinkedList {
private:
    struct ListNode{
        T value;
        struct ListNode * next;
    };
    ListNode* head;
    ListNode* P = nullptr; //Position for SeeAt, SeeNext,
    
public:
    //Constructor
    LinkedList(){
        head = nullptr;
    }
    
    //Destructor
    ~LinkedList(){
        ListNode * NodePtr;
        ListNode * NextNode = nullptr;
        
        NodePtr = head;
        
        while(NodePtr != nullptr){
            NextNode = NodePtr;
            delete NodePtr;
            NodePtr = NextNode;
        }
        cout << "Deleting the linked list" << endl;
    };
    
    //Linked
    void AddItems(T);
    T GetItems(T);
    bool IsInList(T);
    bool IsEmpty();
    int size();
    T seeNext();
    T seeAt(int);
    void Reset();
};


//LinkedList Operations:

//Append one node into the linked list with the item in that node
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

//Get the items and remove it from the linked list
template <class T>
T LinkedList<T>::GetItems(T item) {
    ListNode *NodePtr;
    ListNode * PreviousNode = nullptr;
    ListNode * ReturnNode = nullptr;
    if(!head)
        throw "Error"; ///// IT CANNOT RETURN A NULL POINTER AND THE ITEM.
    
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
    return ReturnNode->value;
}

//Definition of function to check if the item is in the linked list
template <class T>
bool LinkedList<T>::IsInList(T item) {
    ListNode * NodePtr;
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

// FUnction if the list is empty
template <class T>
bool LinkedList<T>::IsEmpty() {
    if(!head)
        return true;
    else
    return false;
}

// Function returning the size of the list
template <class T>
int LinkedList<T>::size() {
    ListNode * NodePtr;
    int size = 1;
    if(!head)
        return 0;
    else{
        NodePtr = head;
        while(NodePtr->next){
            NodePtr = NodePtr->next;
            size = size + 1;
        }
    }
    return size;
}

template <class T>
void LinkedList<T>::Reset(){
    P = head;
}
/*
template <class T>
T LinkedList<T>::seeNext(){
    ListNode * NodePtr;
    
    if(!head)
        throw logic_error("Empty list");
    
    if(P == head){
        P = P->next;
        return head->value;
    }
    else if(P->next = nullptr){
        return P->value;
        
    else
        return P->value;
}*/

template <class T>
T LinkedList<T>::seeAt(int i) {
    ListNode * NodePtr = P;
    int count = 0;
    
    if(!head)
        throw logic_error("Empty list");
    
    else if(i>size()-1 || i<0)
        throw logic_error("Invalid index");
    
    else if(i == 0){
        Reset();
        return head->value;}
    
    else{
    NodePtr = head;
        for (int z = 0;z<size(); z++){
        if (count == i){
            P = NodePtr;
            return NodePtr->value;
            break;
        }
        count++;
        NodePtr = NodePtr->next;
    }
    }
    throw logic_error("Doesn't work");
}


///////MAIN FUNCTION
int main() {
    //////TESTING THE LINKED LIST
    LinkedList<superheroes> DC;
    superheroes Superman{"Superman", 1};
    superheroes Batman{"Batman", 2};
    superheroes WonderWoman{"WonderWoman",3};
    
    DC.AddItems(Superman);
    DC.AddItems(Batman);
    DC.AddItems(WonderWoman);
    DC.Reset();
    
    cout << "Superman is in the list :" << DC.IsInList(Superman) << endl;
    
    cout << "The number at 2 is: ";
    cout << DC.seeAt(0).Name << endl;
    
    //Removing from the list
    cout << DC.GetItems(Batman).num <<endl;
    cout << DC.GetItems(Superman).num <<endl;
    cout << DC.GetItems(WonderWoman).num <<endl;
    
    //cout << "Superman is in the list :" << DC.IsInList(Superman) << endl;
    //cout << "Batman is in the list :" << DC.IsInList(Batman) << endl;
    
    //cout << "The list is empty? " << DC.IsEmpty()<< endl;
    
    //cout << "Size of the linked list: " << DC.size() << endl;
    
    return 420;
}
