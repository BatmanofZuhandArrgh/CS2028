//
//  main.cpp
//  HW2
//
//  Created by Macbook on 10/13/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//////////ROOM
struct Room{
    double length, width;
    bool SWall,NWall,WWall,EWall;
    bool operator == (const Room & obj){
        if((length = obj.length)
           && (width == obj.width)
           && (SWall == obj.SWall)
           && (NWall == obj.NWall)
           && (WWall == obj.WWall)
           && (EWall == obj.EWall))
            return true;
        else
            return false;
    };
};

///////////FLOOR
class Floor{
private:
    double Ewalllength, Wwalllength, Nwalllength, Swalllength;
    struct ListNode{
        Room value;
        struct ListNode *next;
    };
    ListNode *head;
    
public:
    //Default Constructor
    Floor(){
        head = nullptr;
    }
    //Destructor
    ~Floor();
    
    void setLength(double length){
        Nwalllength = Swalllength = length;
    }
    
    void setWidth(double width){
        Ewalllength = Wwalllength = width;
    }
    
    double getLength(){
        return Nwalllength;
    }
    
    double getWidth(){
        return Ewalllength;
    }
    // Linked list operations
    void appendNode(Room);
    //void insertNode(Room);
    void deleteNode(Room);
    void displayList() const;
};


//Appending a node
void Floor::appendNode(Room room){
    ListNode * newRoom; //To point to the new Node
    ListNode * NodePtr; //To move thru the list
    
    //Creating the node and point the pointer to the null next node
    newRoom = new ListNode;
    newRoom->value = room;
    newRoom->next = nullptr;
    
    if(!head){
        head = newRoom; // If there is no head node, make that the newRoom node
    }
    else{
        NodePtr = head; // If there is, then run the node pointer from the head
        while(NodePtr->next){
            NodePtr = NodePtr->next;
        }
        NodePtr = newRoom;
    }
}

//Inserting a node: Doesn't make sense here
/*void Floor::insertNode(Room room){
    ListNode * newRoom;
    ListNode * NodePtr;
    ListNode * previousNode = nullptr;
    
    //Creating the node and point the pointer to the null next node
    newRoom = new ListNode;
    newRoom->value = room;
    
    if(!head){
        head = newRoom; // If there is no head node, make that the newRoom node
        newRoom->next = nullptr;
    }
    else{//Otherwise Insert new node
        NodePtr = head; //Run this pointer from head
        previousNode = nullptr; //let this pointer be null
        
        while(NodePtr != nullptr){
            previousNode = NodePtr;
            NodePtr = NodePtr->next;
        }
    }
    if (previousNode == nullptr){
        head = newRoom;
        newRoom->next = nullptr;
    }
    else{
        previousNode->next = newRoom;
        newRoom->next = NodePtr;
    }
}*/



void Floor::deleteNode(Room room){
    ListNode *NodePtr;
    ListNode *PreviousNode;
    
    //If the list is empty
    if(!head){
        return;
    }
    //If the node needs deleting is the first node
    if(head->value == room){
        NodePtr = head->next;
        delete head;
        head = NodePtr;
    }
    else{
        NodePtr = head;
        //Assign the previous node to the node before the node we need to find and the nodeptr to the node after that
        while((NodePtr != nullptr) && !(NodePtr->value == room)){
            PreviousNode = NodePtr;
            NodePtr = NodePtr->next;
        }
        //If the node is not at the end, then link the previous node to the node after the node, and delete the node.
        if(NodePtr){
            PreviousNode->next = NodePtr->next;
            delete NodePtr;
        }
    }
}

void Floor::displayList()const{
    ListNode *NodePtr;
    NodePtr = head;
    if (!head){
        cout<<"The floor is empty";
    }
    while(NodePtr!=nullptr){
        cout << NodePtr->value.length << endl; //Display just the length
        NodePtr = NodePtr->next;
    }
}


//////////BUILDING
class Building{
private:
    string address;
    string name;
    Floor floor;
    double width;
    double length;
    int stories;
    double height;
    
public:
    //Default Constructor
    Building(){
        name = address = " ";
        width = length = height = 0;
        stories = 0;
        Floor floor;
    }
    
    //Destructor
    ~Building();
    
    void setName(string Name){
        name = Name;
    }
    
    string getName(){
        return name;
    }
    
    void setAddress(string Address){
        address = Address;
    }
    
    string getAddress(){
        return address;
    }
    
    void setWidth(double Width){
        width = Width;
    }
    
    double getWidth(){
        return width;
    }
    
    void setLength(double Length){
        length = Length;
    }
    
    double getLength(){
        return length;
    }
    
    void setStories(int Stories){
        stories = Stories;
    }
    
    int getStories(){
        return stories;
    }
    
    void setHeight(double Height){
        height = Height;
    }
    
    double getHeight(){
        return height;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 69;
}
