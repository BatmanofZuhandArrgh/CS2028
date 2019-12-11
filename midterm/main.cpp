//
//  main.cpp
//  MidtermRedo
//
//  Created by Macbook on 12/11/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int ROW = 16;
int COL = 20;
//1. TicketInfo Structure
struct TicketInfo{
    int TicketNumber;
    double price;
    string SeatingInfo;
};

TicketInfo ArrayFunction(TicketInfo Arr[][COL]){
    return Arr[0][0];
}

//2. clss Frame
class Frame1{
private:
    string label;
    double x_coord, y_coord;
    double width;
    double height;
public:
    Frame1(){
        label = "";
        x_coord = 0;
        y_coord = 0;
        width = 0;
        height = 0;
    }

    Frame1(string name, int initX, int initY, int initW, int initH){
        label = name;
        x_coord = initX;
        y_coord = initY;
        width = initW;
        height = initH;
    }
    void Resize(int H, int W){
        height = H;
        width = W;
    }
    void getHeight(){
        cout << "Height is: "<< height << endl;
    }
    
    void getWidth(){
        cout << "Width is: "<< width << endl;
    }
    
    void MoveTo(int NewX, int NewY){
        x_coord = NewX;
        y_coord = NewY;
    }
};

//3. Class Shape and Loc
class Shape{
private:
    int width;
    int height;
public:
    Shape(int w, int h){
        width = w;
        height = h;
    };
    Shape(){
        width = 0;
        height = 0;
    };
    int Width(){
        return width;
    }
    int Height(){
        return height;
    }
    void setWidth(int);
    void setHeight(int);
};

void Shape::setWidth(int w){
    width = w;
}

void Shape::setHeight(int h){
    height = h;
}

class Loc{
private:
    int x_coord;
    int y_coord;
public:
    Loc(int x, int y){
        x_coord = x;
        y_coord = y;
    }
    Loc(){
        x_coord = 0;
        y_coord = 0;
    }
    int X(){
        return x_coord;
    }
    int Y(){
        return y_coord;
    }
    void setX(int);
    void setY(int);
};

void Loc::setY(int y){
    y_coord = y;
}

void Loc::setX(int x){
    x_coord = x;
}

class Frame : public Shape, public Loc{
private:
    string label;
public:
    Frame(string name, int X, int Y, int width, int height) : Shape(width, height), Loc(X,Y){
        label = name;
    }
    void Resize(int w, int h){
        setHeight(h);
        setWidth(w);
    }
    void Moveto(int x, int y){
        setX(x);
        setY(y);
    }
};

class animal{
private:
    int x;
public:
    //These 2 functions are to be overriden in the derived class
    virtual int getAge() = 0;
    virtual void show() = 0;
    int showX(){
        return x;
    }
};

class mammal : public animal{
private:
    int y;
public:
    //Overriding the virtual functions defined in animal
    int getAge(){
        return y;
    }
    void show(){
        cout << showX() << endl;
        cout << y << endl;
    }
};

int main() {
    
    //1. TicketInfo Structure
    TicketInfo Seat[ROW][COL];

    for (int i = 0; i < ROW ; i++){
        for (int j = 0; j < COL; i++){
    cout << "Enter Ticket number: "<< endl;
    cin >> Seat[i][j].TicketNumber;
    cout << "Enter price: "<< endl;
    cin >> Seat[i][j].price;
    cout << "Enter Seating information: " << endl;
    cin >> Seat[i][j].SeatingInfo;
        }
    }
    //2. Class Frame
//    Frame1 displayGraphics("Display graphics", 5, 2, 6, 3);
//    displayGraphics.Resize(75, 50);
//
//    Frame1* viewGraphics;
//    viewGraphics = new Frame1("Display graphics", 5, 2, 6, 3);
//    viewGraphics->Resize(200, 150);
//
//    viewGraphics->getWidth();
//    viewGraphics->getHeight();
//
//    Frame1 winList[5];
//    for (int i = 0; i<5; i++){
//        winList[i].Resize(20,20);
//    }
//    int incrementX = 0;
//    for (int i = 0; i<5; i++){
//        winList[i].MoveTo(incrementX, 0);
//        incrementX = incrementX + 20;
//    }
    
    //3. Frame inheritance
    
    return 0;
}
