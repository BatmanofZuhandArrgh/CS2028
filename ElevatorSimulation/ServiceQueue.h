// Data Structures Laboratory
// Section 004
// Homework
// 12/09/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens and Ayumi Mutoh
//

#ifndef ServiceQueue_hpp
#define ServiceQueue_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

//I could use the Heap implementation of Priority Queue, but I figure using a Linked List implementation should be easier
template<class T>
class ServiceQueue{
private:
    struct ListNode{
        T value;
        struct ListNode *next;
    };
    ListNode *head;
    ListNode *P = nullptr;
public:
    // Constructor
    ServiceQueue(){
        head = nullptr;
    }
    
    //Destructor
    //~Destructor();
    
    //Append a node at the end of the list
    void appendNode(T a){
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
    bool isIn(T a){
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
    
    int peekHead(){
        if(!head)
            return 0;
        return head->value;
    }
    
    bool isEmpty(){
        if(!head)
            return true;
        else
            return false;
    }
    
    void deleteNode(T a){
        ListNode *nodePtr;
        ListNode *previousNode = nullptr;
        
        if(!head)
            return;
        
        if(head->value == a){
            nodePtr = head->next;
            delete head;
            head = nodePtr;
        }
        else{
            nodePtr = head;
            while(nodePtr!=NULL && nodePtr->value != a){
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
            
            if(nodePtr){
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
    }
    
    void reset(){
        P = head;
    }
    
    int size(){
        ListNode* nodePtr;
        int count = 0;
        
        nodePtr = head;
        while(nodePtr != NULL){
            count = count + 1;
            nodePtr = nodePtr->next;
        }
        return count;
    }
    
    T seeAt(int a){
        if(!head)
            throw logic_error("There's nothing on this list");
        
        if (a > size()-1 || a < 0)
            throw logic_error("Invalid Index1");
        
        P = head;
        
        for (int i = 0; i< a; i++){
            P = P->next;
        }
        return P->value;
    }
    
    ListNode* seeNext(){
        if(!head){
            cout << "This list is empty" << endl;
            return nullptr;
        }
        if(P == nullptr){
            reset();
            return P;
        }
        else{
            P = P->next;
            return P;
        }
    }
    
    T seeCurrent(){
        if(!head)
            throw logic_error("This list is empty");
        
        if(P == nullptr){
            reset();
            return P->value;
        }
        else
            return P->value;
    }
    
    ListNode* seeCurrentPointer(){
        if(!head){
            cout << "This list is empty" << endl;
            return  nullptr;
        }
            return P;
    }
    
};

#endif /* ServiceQueue_hpp */
