//
//  Passenger.hpp
//  ElevatorSimulation
//
//  Created by Macbook on 12/1/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#ifndef Passenger_hpp
#define Passenger_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "HallwayButton.h"

using namespace std;

class Passenger{
private:
    // Inherent information
    string PID;
    int originFloor;
    int destFloor;
    
    // Operation-related information
    string in_or_out_Car;
    HallwayButton HBttn; //HallwayButton
    
    // Time-related information
    
    
public:
    //////////////Constructors&Destructors for Passenger/////////////
    //The beginning passengers doesn't have a floor, and wanting to go into the elevator car
    Passenger(){
        PID = "";
        originFloor = 0;
        destFloor = 0;
        in_or_out_Car = "Out";
    }
    
    Passenger(string a, int b, int c){
        PID = a;
        originFloor = b;
        destFloor = c;
        in_or_out_Car = "Out";
    }
    
    //~Passenger();
    
    //////////////Set&Get functions////////////////
    void setPID(string a){
        PID = a;
    }
    
    void setoriginFloor(int a){
        originFloor = a;
    }
    
    void setdestFloor(int a){
        destFloor = a;
    }
    
    string getPID(){
        return PID;
    }
    
    int getoriginFloor(){
        return originFloor;
    }
    
    int getdestFloor(){
        return destFloor;
    }
    //For the purpose of testing
    void setin_or_out_Car(string a){
        in_or_out_Car = a;
    }
    
    string getin_or_out_Car(){
        return in_or_out_Car;
    }
    
    //Set the state of the hallway button based on the destfloor and originfloor
    void setHallwayButton(){
        if (destFloor > originFloor){
            HBttn.DownButton = false;
            HBttn.UpButton = true;
        }
        else if(originFloor > destFloor){
            HBttn.DownButton = true;
            HBttn.UpButton = false;
        }
        else
            cout << "Invalid input, you're going to the same floor, why are you here?"<< endl;
    }
    
    //Returns the state of the hallway button request
    HallwayButton getHallwayButton(){
        setHallwayButton();
        return HBttn;
    }
    
};


#endif /* Passenger_hpp */
