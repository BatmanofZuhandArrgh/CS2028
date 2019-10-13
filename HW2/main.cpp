//
//  main.cpp
//  HW2
//
//  Created by Macbook on 10/13/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct Room{
    
};

class Floor{
private:
    double Ewalllength, Wwalllength, Nwalllength, Swalllength;
    Room room;
    Room *head;
    
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
    void insertNode(Room);
    void deleteNode(Room);
    void displayList() const;
};

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
