//
//  ServiceQueue.hpp
//  ElevatorSimulation
//
//  Created by Macbook on 12/1/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#ifndef ServiceQueue_hpp
#define ServiceQueue_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

//I could use the Heap implementation of Priority Queue, but I figure using a Linked List implementation should be easier
class ServiceQueue{
private:
    struct ListNode{
        int value;
        struct ListNode *next;
    };
    ListNode *head;
public:
    // Constructor
    ServiceQueue(){
        head = nullptr;
    }
    
    //Destructor
    //~Destructor();
    
    //Append a node at the end of the list
    void appendNode(int a){
        ListNode * NewNode;
        ListNode * NodePtr;
        
        NewNode = new ListNode;
        NewNode->value = a;
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
    // Display the queue, for the purpose of checking
    void showQueue(){
        ListNode * NodePtr;
        
        if(!head)
            cout << "There's nothing on this queue" << endl;
        else{
            NodePtr = head;
            
            while(NodePtr){
                cout << NodePtr->value << endl;
                NodePtr = NodePtr->next;
            }
        }
    }
    
    //Check if the element is in the queue
    bool isIn(int a){
        ListNode * Nodeptr;
        
        if(!head)
            return false;
        else{
            Nodeptr = head;
            
            while(Nodeptr){
                if(Nodeptr->value == a)
                    return true;
                Nodeptr = Nodeptr->next;
            }
        }
        return false;
    }
    
    //Insert Node while going up, so any new floor number larger than the current floor (the head of the queue) will be in this queue
    void InsertNodeUp(int a){
        
        //To avoid replication, we exit the moment it's found that the element is in the queue
        if(isIn(a)){
            return;
        }
        
        ListNode* NewNode;
        ListNode* NodePtr;
        ListNode* PreviousNode = nullptr;
        
        //Create a new node and assign a to the value of this node
        NewNode = new ListNode;
        NewNode->value = a;
        NewNode->next = nullptr;
        
        //Inserting node into the queue
        if(!head){
            appendNode(a);
            //head->value = a;
            //NewNode->next = nullptr;
        }
        else{
            NodePtr = head;
            PreviousNode = NULL;
    
            //Any new value added onto the queue must be larger than the current value
            while(NodePtr!=nullptr && NodePtr->value < NewNode->value ){
                PreviousNode = NodePtr;
                NodePtr = NodePtr->next;
            }
            
            if (PreviousNode == NULL){
                head = NewNode;
                NewNode->next = NodePtr;
            }
            else{
            PreviousNode->next = NewNode;
            NewNode->next = NodePtr;
            }
        }
    }
    
     //Insert Node while going down, so any new floor number smaller than the current floor (the head of the queue) will be in this queue
    void InsertNodeDown(int a){
        
        //To avoid replication, we exit the moment it's found that the element is in the queue
        if(isIn(a)){
            return;
        }
        
        ListNode* NewNode;
        ListNode* NodePtr;
        ListNode* PreviousNode = nullptr;
        
        //Create a new node and assign a to the value of this node
        NewNode = new ListNode;
        NewNode->value = a;
        NewNode->next = nullptr;
        
        //Inserting node into the queue
        if(!head){
            appendNode(a);
            //head->value = a;
            //head->next = nullptr;
        }
        else{
            NodePtr = head;
            PreviousNode = NULL;
            //Any new value added onto the queue must be larger than the current value
            while(NodePtr!=nullptr && NodePtr->value >= NewNode->value ){
                PreviousNode = NodePtr;
                NodePtr = NodePtr->next;
            }
            
            if (PreviousNode == NULL){
                head = NewNode;
                NewNode->next = NodePtr;
            }
            else{
                PreviousNode->next = NewNode;
                NewNode->next = NodePtr;
            }
        }
    }
    
    //Dequeue, where the car has complete one trip to the first floor on the queue
    void dequeue(){
        ListNode* NodePtr;
        
        if(!head){
            cout << "There is a no order on the queue." << endl;
        }
        else{
            NodePtr = head;
            head = NodePtr->next;
            delete NodePtr;
        }
    }
};

#endif /* ServiceQueue_hpp */
