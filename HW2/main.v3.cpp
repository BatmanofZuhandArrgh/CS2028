// Data Structures Laboratory
// Section 004
// Homework
// 10/28/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens and Ayumi Mutoh
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//////////ROOM
struct Room{
    string name;
    string activities;
    double length, width;
    bool privateornot;
    
    // Overloading ==
    bool operator == (const Room & obj){
        if((length == obj.length) && (width == obj.width) &&
           (name == obj.name) &&
           (activities == obj.activities))
            return true;
        else
            return false;
    };
    
    // Overloading !=
    bool operator != (const Room & obj){
        if((length != obj.length) || (width != obj.width) ||
           (name != obj.name) ||
           (activities != obj.activities))
            return true;
        else
            return false;
    };
    
};
////////////////////////////////////////////////////////////////////////////////
//////////ROW OF ROOM
class Row{
private:
    struct ListRoom{
        Room value;
        struct ListRoom *next;
    };
    ListRoom* head;
public:
    //Default Constructor
    Row(){
        head = nullptr;
    }
    
    //Destructor
    //~Row();
    
    //LinkedList Operations
    void appendNode(Room);
    void insertNode(Room, Room);
    void deleteNode(Room);
    void displayRow();
    void areaListingRow();
    double areapublicspace();
    double areaprivatespace();
    void functionofRoom();
};

//////////Operations Definition ROW OF ROOM
//Append a room, to the right of the existing room.
void Row::appendNode(Room room){
    ListRoom * newRoom; //To point to the new Node
    ListRoom * nodePtr;
    
    //Creating the node and point the pointer to the null next node
    newRoom = new ListRoom;
    newRoom->value = room;
    newRoom->next = NULL;
    
    if(!head)
        head = newRoom;
    else{
        nodePtr = head;
        
        while (nodePtr-> next)
        {nodePtr = nodePtr->next;}
        
        nodePtr->next = newRoom;
}
}

////////ERROR
//Insert a room to the right of a room
void Row::insertNode(Room room, Room roomtotheright){
    ListRoom *nodePtr;
    ListRoom *previousNode=nullptr;
    ListRoom *newRoom;
    //ListRoom *temp_node;
    
    //Creating the node and point the pointer to the null next node
    newRoom = new ListRoom;
    newRoom->value = room;
    
    //If there's no node in the list, create the first Node with the newRoom
    if(!head){
        head = newRoom;
        newRoom->next = nullptr;
    }
    else{
        nodePtr = head;
        previousNode = nullptr;
        
        while(nodePtr != nullptr && nodePtr->value != roomtotheright){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        //If the new node is to be the 1st in the list,
        //insert before all other nodes
        if (previousNode == nullptr){
            head = newRoom;
            newRoom->next = nodePtr;
        }
        else{
            previousNode->next = newRoom;
            newRoom->next = nodePtr;
        }
    }
}


//Delete a room. The rest will fill up the row.
void Row::deleteNode(Room room){
    ListRoom * nodePtr;  //To traverse the list
    ListRoom * previousNode=nullptr; //To point to the previous ndoe
    
    //Determine if the first node is the one
    if(!head)
        return;
    
    if(head->value == room){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else{
        //Initialize nodePtr to head of the list
        nodePtr = head;
        
        //Skip all nodes whose value member is not room
        while(nodePtr != nullptr && nodePtr->value != room){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        //If If nodePtr is not at the end of the list
        //Link the previous node to the node after nodePtr, and tdelete Nodeptr;
        if (nodePtr){
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}


//Display the row of room
void Row::displayRow(){
    // Create Nodeptr to traverse the row
    ListRoom *NodePtr;
    cout << " ";
    
    //Put NodePtr onto the head of the linked list
    NodePtr = head;
    
    // When the list is empty, display nothing
    if (!head){
        cout<<"The floor is empty"<< endl;
    }
    
    //Traverse the list, while, NodePtr hasn't hit the end, print the wall
    while(NodePtr!=nullptr){
        cout << "____________"<< " ";
        NodePtr = NodePtr->next;
    }
    cout << endl;
    cout << "| ";
    
    // Set NodePtr to the top of the list again, traverse and print out the name of the room
    NodePtr = head;
    while(NodePtr!=nullptr){
        cout << NodePtr->value.name << " | "; //Display just the name of the room;
        NodePtr = NodePtr->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
//////////OPERATIONS OF VECTOR OF ROW OF ROOM

//Display floor as a bunch of rows from north to south
void displayFloor(vector<Row> vect){
    cout<< "_______________________WALL_________________________"<< endl;
    for (int i = 0; i<vect.size(); i++){
        vect[i].displayRow();
        cout << endl;
    }
    cout<< "_______________________WALL_________________________"<< endl;
}

//Swap the position of 2 rows in the floor plan
void rowSwap(vector<Row> &vect, int i, int j){
    vector<Row> vecttemp = vect;
    if (i<vect.size() && i>=0 && j<vect.size() && j>=0){
        vecttemp[i] = vect[j];
        vecttemp[j] = vect[i];
    }
    else
        cout <<"Please input vector index again" << endl;
    vect = vecttemp;
}


////////////////////////////////////////////////////////////////////////////////
//////////OPERATIONS THAT SHOW THE STATS OF THE FLOOR
//////////AREA OF ROOMS
// Calculate area of each room
double areaRoom(Room room){
    return room.length * room.width;
}

// Area listing of the row
void Row::areaListingRow(){
    ListRoom *NodePtr;
    
    //Put NodePtr onto the head of the linked list
    NodePtr = head;
    
    // When the list is empty, display nothing
    if (!head){
        cout<<"The floor is empty"<< endl;
    }
    while(NodePtr!=nullptr){
        cout << "Area of " << NodePtr->value.name << " is: " << areaRoom(NodePtr->value) << " m2." << endl;
        NodePtr = NodePtr->next;
    }
}

// Area listing of the floor
void areaRoomListing(vector<Row> myFloor){
    for (int i = 0; i< myFloor.size(); i++){
        myFloor[i].areaListingRow();
        cout << endl;
    }
}

// Area of public space per row
double Row::areapublicspace(){
    ListRoom *NodePtr;
    double areaofpublicspace = 0;
    //Put NodePtr onto the head of the linked list
    NodePtr = head;
    
    // When the list is empty, display nothing
    if (!head){
        cout<<"The floor is empty"<< endl;
    }
    while(NodePtr!=nullptr){
        if(NodePtr->value.privateornot==false){
            areaofpublicspace = areaofpublicspace + areaRoom(NodePtr->value);
        }
        NodePtr = NodePtr->next;
    }
    return areaofpublicspace;
}

// Area of private space per row
double Row::areaprivatespace(){
    ListRoom *NodePtr;
    double areaofprivatespace = 0;
    //Put NodePtr onto the head of the linked list
    NodePtr = head;
    
    // When the list is empty, display nothing
    if (!head){
        cout<<"The floor is empty"<< endl;
    }
    while(NodePtr!=nullptr){
        if(NodePtr->value.privateornot==true){
            areaofprivatespace = areaofprivatespace + areaRoom(NodePtr->value);
        }
        NodePtr = NodePtr->next;
    }
    return areaofprivatespace;
}

//Area of private space for the floor
double areaofprivatespaceFloor(vector<Row> myFloor){
    double areaprivatespace = 0;
    for (int i = 0; i< myFloor.size(); i++){
        areaprivatespace = areaprivatespace + myFloor[i].areaprivatespace();
    }
    return areaprivatespace;
}

//Area of public space for the floor
double areaofpublicspaceFloor(vector<Row> myFloor){
    double areaofpublicspace = 0;
    for (int i = 0; i< myFloor.size(); i++){
        areaofpublicspace = areaofpublicspace + myFloor[i].areapublicspace();
    }
    return areaofpublicspace;
}

void DisplayPublicorPrivate(vector<Row> myFloor){
    cout << "Total area of public space in the floor is " << areaofpublicspaceFloor(myFloor) << " m2." << endl;
    cout << "Total area of private space in the floor is " << areaofprivatespaceFloor(myFloor) << " m2." << endl;
    cout << "Total area of the floor is " << areaofpublicspaceFloor(myFloor) + areaofpublicspaceFloor(myFloor)<< " m2." << endl;
}


////////////////////////////////////////////////////////////////////////////////
//////////OPERATIONS THAT SHOW THE STATS OF THE FLOOR
//////////FUNCTION OF ROOMS
// Area listing of the row
void Row::functionofRoom(){
    ListRoom *NodePtr;
    
    //Put NodePtr onto the head of the linked list
    NodePtr = head;
    
    // When the list is empty, display nothing
    if (!head){
        cout<<"The floor is empty"<< endl;
    }
    while(NodePtr!=nullptr){
        cout << "Function of the room " << NodePtr->value.name << " is: " << NodePtr->value.activities << endl;
        NodePtr = NodePtr->next;
    }
}

void functionofRoomListing(vector<Row> myFloor){
    for (int i = 0; i< myFloor.size(); i++){
        myFloor[i].functionofRoom();
        cout << endl;
    }
}


////////////////////////////////////////////////////////////////////////////////
//////////MAIN FUNCTION
int main() {
    //Create the main floor plan
    vector<Row> myFloor;
    
    //Create 2 rows of rooms
    Row Row1;
    Row Row2;
    
    
    //Create a bunch of rooms
    Room Bedroom1{" BedRoom1 ", "Sleeping",3 ,7, true};
    Room Bedroom2{" BedRoom2 ", "Sleeping",3 ,7, true};
    Room Library{" Library  ", "Reading",4 ,4, false};
    Room Workshop{" Workshop ", "Machining and building",1, 10, false};
    Room Bathroom{" BathRoom ", "Taking a shower",6 ,5, false};
    Room Kitchen{" Kitchen  ", "Cooking",2 ,10, false};
    Room DiningRoom{"DiningRoom", "Eating",3 ,7, false};
    Room LivingRoom{"LivingRoom", "Hanging out and having fun", 5, 5, false};
    //Populate the rows with room
    Row1.appendNode(Bedroom1);
    Row1.appendNode(Bathroom);
    Row1.appendNode(Library);
    Row1.appendNode(Bedroom1);
    Row1.appendNode(Bedroom2);
    Row2.appendNode(Kitchen);
    Row2.appendNode(DiningRoom);
    Row2.appendNode(LivingRoom);
    Row2.appendNode(DiningRoom);
    Row2.appendNode(Workshop);
    
    
    
    // Delete a few rooms
    Row1.deleteNode(Bedroom1);
    Row1.deleteNode(Kitchen);
    Row2.deleteNode(DiningRoom);
    
    //I inserted the room and deleted it right away, because it makes a bad display. Please test it as you will.
    //The current state is just easier to look at
    Row2.insertNode(Bathroom, Kitchen);
    Row2.deleteNode(Bathroom);
    // Populate the floor with rows of rooms
    myFloor.push_back(Row1);
    myFloor.push_back(Row2);
    
    // Display the floor
    displayFloor(myFloor);
    
    //Swap the positions of the rows
    cout << "Swapping the rows of rooms" << endl;
    rowSwap(myFloor, 0, 1);
    
    //Display the floor
    displayFloor(myFloor);
    
    
    cout << "STATS about the floor: " << endl;
    //Area of each room and public and private space
    areaRoomListing(myFloor);
    DisplayPublicorPrivate(myFloor);
    cout << endl;
    functionofRoomListing(myFloor);
    
    cout << endl;
    return 69;
}
