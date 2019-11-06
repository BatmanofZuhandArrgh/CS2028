//
//  main.cpp
//  Lab7v2
//
//  Created by Macbook on 11/4/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////
////////////////////THE CLASS FROM TASK 2
class Item{
private:
    double PartNumber;
    string Description;
    double Price;
    string UOM; //Unit of measure
    double QuantityonHand;
    int LeadTime;
public:
    Item(){
        PartNumber = 0;
        Description = "";
        Price = 0;
        UOM = ""; //Unit of measure
        QuantityonHand = 0;
        LeadTime = 0;
    }
    
    Item(double a, string b, double c, string d){
        PartNumber = a;
        Description = b;
        Price = c;
        UOM = d;
        QuantityonHand = 0;
    }
    
    Item(double a){
        PartNumber = a;
    }
    
    //Return the information to the item
    string GetPartInfo(){
        string s = to_string(PartNumber);
        string info = s + ": " + Description;
        return info;
    }
    
    //Return price of the product
    double GetPrice(){
        return Price;
    }
    
    //Check if the product is in stock
    bool InStock(){
        if(QuantityonHand>0)
            return true;
        else
            return false;
    }
    
    //Assess if this is available
    bool Available(int Day){
        if (QuantityonHand>0)
            return true;
        else{
            if(Day>LeadTime)
                return true;
            else
                return false;
        }
    }
    
    //Overloading
    // Overloading ==
    bool operator == (const Item & obj){
        if(PartNumber == obj.PartNumber)
            return true;
        else
            return false;
    };
    
    // Overloading !=
    bool operator != (const Item & obj){
        if(PartNumber != obj.PartNumber)
            return true;
        else
            return false;
    };
    
    // Overloading >
    bool operator > (const Item & obj){
        if(PartNumber > obj.PartNumber)
            return true;
        else
            return false;
    };
    
    // Overloading <
    bool operator < (const Item & obj){
        if(PartNumber < obj.PartNumber)
            return true;
        else
            return false;
    };
    
    
};

//////////////////////////////////////////////////////
////////////////////THE CLASS FROM TASK 1
template <class T>
class LinkedList {
private:
    struct ListNode{
        T value;
        struct ListNode * next;
        
        // Overloading ==
        bool operator == (const ListNode & obj){
            if(value == obj.value)
                return true;
            else
                return false;
        };
        
        // Overloading !=
        bool operator != (const ListNode & obj){
            if(value != obj.value)
                return true;
            else
                return false;
        };
        
        // Overloading <
        bool operator < (const ListNode & obj){
            if(value < obj.value)
                return true;
            else
                return false;
        };
        
        // Overloading >
        bool operator > (const ListNode & obj){
            if(value > obj.value)
                return true;
            else
                return false;
        };
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
        ListNode *nextNode;
        
        NodePtr = head;
        
        while(NodePtr != nullptr){
            nextNode = NodePtr->next;
            delete NodePtr;
            NodePtr = nextNode;
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
    
    /*
    //SEENEXT FUNCTION w/o P
    ListNode* seeNext(ListNode * Batman){
        ListNode * NodePtr;
        
        NodePtr = head;
        
        if(!head)
            throw logic_error("No node");
        else if(Batman == nullptr)
            return nullptr;
        else{
            Batman = Batman->next;
            return Batman;
        }
    }
    
    
     //SEENEXT FUNCTION with P
     ListNode* seeNext(){
     if(!head)
         throw logic_error("No node");
     else if(P == nullptr)
     return nullptr;
     else{
     P = P->next;
     return P;
     }
     }
    
    
    
    //SEEAT FUNCTION w/o P
    ListNode* seeAt(int i){
        ListNode * NodePtr;
        NodePtr = head;
        int count = 0;
        
        if(i> size()-1)
            throw logic_error("Invalid index");
        else{
            NodePtr = head;
            while(NodePtr->next){
                if(count == i){
                    return NodePtr;
                }
                NodePtr = NodePtr->next;
                count++;
            }
        }
    }
    
    
    
     //SEEAT FUNCTION with P
     ListNode* seeAt(int i){
     ListNode * NodePtr;
     NodePtr = P;
     int count = 0;
     
     if(i> size()-1)
     throw logic_error("Invalid index");
     else{
     NodePtr = head;
     while(P->next){
     if(count == i){
         return P;
     }
         NodePtr = NodePtr->next;
         count++;
     }}}
    */
    
    
    /*
    T returnAt(int i){
        return seeAt(i)->value;
    }
    
    T returnNext(){
        return seeNext()->value;
    }
    */
    // Overloading ==
    bool operator == (const LinkedList & obj){
        ListNode * NodePtr1;
        ListNode * NodePtr2;
        NodePtr1 = head;
        NodePtr2 = obj.head;
        
        if(head == nullptr && obj.head == nullptr){
            return true;
        }
        
        if(head == nullptr && obj.head != nullptr){
            return false;
        }
        
        if(head != nullptr && obj.head == nullptr){
            return false;
        }
        
        while(NodePtr1 != nullptr && NodePtr2 != nullptr){
            if(NodePtr1->value != NodePtr2->value){
                return false;
            }
        NodePtr1 = NodePtr1->next;
        NodePtr2 = NodePtr2->next;
        }
        return true;
        }
    
    // Overloading !=
    bool operator != (const LinkedList & obj){
        ListNode * NodePtr1;
        ListNode * NodePtr2;
        NodePtr1 = head;
        NodePtr2 = obj.head;
        
        if(head == nullptr && obj.head == nullptr){
            return false;
        }
        
        if(head == nullptr && obj.head != nullptr){
            return true;
        }
        
        if(head != nullptr && obj.head == nullptr){
            return true;
        }
        
        while(NodePtr1 != nullptr && NodePtr2 != nullptr){
            if(NodePtr1->value != NodePtr2->value){
                return true;
            }
            NodePtr1 = NodePtr1->next;
            NodePtr2 = NodePtr2->next;
        }
        return false;
    }
    
    // Overloading >
    bool operator > (const LinkedList & obj){
        ListNode * NodePtr1;
        ListNode * NodePtr2;
        NodePtr1 = head;
        NodePtr2 = obj.head;
        
        if(head == nullptr || obj.head == nullptr){
            return false;
        }
        
        while(NodePtr1 != nullptr && NodePtr2 != nullptr){
            if(NodePtr1->value == NodePtr2->value || NodePtr1->value < NodePtr2->value){
                return false;
            }
            NodePtr1 = NodePtr1->next;
            NodePtr2 = NodePtr2->next;
        }
        return true;
    }
    
    // Overloading <
    bool operator < (const LinkedList & obj){
        ListNode * NodePtr1;
        ListNode * NodePtr2;
        NodePtr1 = head;
        NodePtr2 = obj.head;
        
        if(head == nullptr || obj.head == nullptr){
            return false;
        }
        
        while(NodePtr1 != nullptr && NodePtr2 != nullptr){
            if(NodePtr1->value == NodePtr2->value || NodePtr1->value > NodePtr2->value){
                return false;
            }
            NodePtr1 = NodePtr1->next;
            NodePtr2 = NodePtr2->next;
        }
        return true;
    }
    
    };


//LinkedList Operations:

//1. Append one node into the linked list with the item in that node
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

//2. Get the items and remove it from the linked list
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

//3. Definition of function to check if the item is in the linked list
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

// 4. FUnction if the list is empty
template <class T>
bool LinkedList<T>::IsEmpty() {
    if(!head)
        return true;
    else
        return false;
}

// 5. Function returning the size of the list
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

// 6. Function putting the P pointer back to the head
template <class T>
void LinkedList<T>::Reset(){
    P = head;
}

// 7. Function returning the item and move the P pointer one step forward
template <class T>
T LinkedList<T>::seeNext(){
    if(!head)
        throw logic_error("Empty LinkedList");
    
    if(P == head){
        P = P->next;
        return head->value;
    }
    else if(P == nullptr){
        Reset();
        return P->value;
    }
    else{
        ListNode * NodePtr;
        
        NodePtr = P;
        P = P->next;
        return NodePtr->value;
    }
}

// 8. Function returning the item at the point
template <class T>
T LinkedList<T>::seeAt(int i) {
    ListNode * NodePtr = P;
    int count = 0;
    
    if(!head)
        throw logic_error("Empty list");
    
    else if(i>size()-1|| i<0)
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


int main() {
    LinkedList<Item> ListofItem;
    Item A(12,"Batman", 334, "Batarang");
    Item B(23,"Superman", 3432, "Heat Vision");
    Item C(34,"WonderWoman", 34, "Lasso of Truth");
    Item D(45,"Flash", 234, "Speed");
    Item E(56,"Green Lantern", 55, "Power of Will");

    ListofItem.AddItems(A);
    ListofItem.AddItems(B);
    ListofItem.AddItems(C);
    ListofItem.AddItems(D);
    ListofItem.AddItems(E);
    
    int choice = 0;
    
    while(choice != 9){
        cout << "Menu: "<<endl;
        cout << "1. AddItem"  << endl;
        cout << "2. GetItem" << endl;
        cout << "3. IsInList" << endl;
        cout << "4. IsEmpty" << endl;
        cout << "5. Size" << endl;
        cout << "6. SeeNext" << endl;
        cout << "7. SeeAt" << endl;
        cout << "8. Reset" << endl;
        cout << "9. Quit the program" << endl;
        cout << "Enter your choice: ";
        cin>> choice;
        cout << endl;
        /*
        Item(double a, string b, double c, string d){
            PartNumber = a;
            Description = b;
            Price = c;
            UOM = d;
            QuantityonHand = 0;
        }
         */
        switch (choice) {
            case 1:{
                cout << "Please input the following information."<< endl;
                
                cout << "1. Part Number: ";
                double a;
                cin >> a;
                cout << endl;
                
                cout << "2. Description: ";
                string b;
                cin >> b;
                cout << endl;
                
                cout << "3. Price: ";
                double c;
                cin >> c;
                cout << endl;
                
                cout << "4. Unit of measurement: ";
                string d;
                cin >> d;
                cout << endl;
                
                Item I(a,b,c,d);
                
                ListofItem.AddItems(I);
                break;
            }
                
            case 2:{
                cout << "Please input the part number you want to search:";
                double e;
                cin >> e;
                cout << endl;
                
                Item I(e);
                cout << "Here is the specs about the item you searched for :"<< endl;
                cout << ListofItem.GetItems(I).GetPartInfo()<< endl;
                break;
            }
                
            case 3:{
                cout << "Please input the part number you want to search:";
                double e;
                cin >> e;
                cout << endl;
                
                Item I(e);
                cout << "The item is";
                if(ListofItem.IsInList(I))
                    cout << " ";
                else
                    cout << " not ";
                cout << "in the list."<< endl;
                break;
            }
                
            case 4:{
                cout << "The list is";
                if(ListofItem.IsEmpty())
                    cout << " ";
                else
                    cout << " not ";
                cout << "empty."<< endl;
                break;
            }
                
            case 5:{
                cout << "The size of the list is: "<< ListofItem.size()<<endl;
                break;
            }
            case 6:{
                cout << "The specs of the item at the pointer P is: ";
                cout << ListofItem.seeNext().GetPartInfo() <<endl;
                break;
            }
            case 7:{
                cout << "Please input the index you want to check: ";
                int f;
                cin >> f;
                cout << endl;
                
                cout << "The specs of the item at the pointer P is: ";
                cout << ListofItem.seeAt(f).GetPartInfo() <<endl;
                break;
            }
            case 8:{
                cout << "Resetting pointer P to the beginning of the list!";
                ListofItem.Reset();
                break;
            }
            default:{
                cout<< endl;
                cout << "Please enter options from 1 to 8!" << endl;
                break;
            }
        }
        //choice = 9;
    }
    
    
    
    return 0;
}
