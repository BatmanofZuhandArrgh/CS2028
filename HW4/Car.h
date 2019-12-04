//
//  Car.hpp
//  ElevatorSimulation
//
//  Created by Macbook on 12/1/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Motor.h"
#include "HallwayButton.h"
#include "ServiceQueue.h"

using namespace std;

class Car{
private:
    //Inherent information
    string CarID;
    int CurrentFloor;

    //Operation-related information
    ServiceQueue ServiceQueueUp;
    ServiceQueue ServiceQueueDown;
    string tripDirection;
    int State;
    
    //Time-related information
    int tripCounter;
    int floorServedByTrip;
    
    //HallwayButton-related information
    HallwayButton CarHBttn;
    
    //Motor-related information
    Motor carMotor;
    
public:
    //Information about every single trip
    vector<Passenger> ListofPassenger;
    
    //////Constructors&Destructors for Car///////
    //Default constructor with no trips yet and currently idle, current floor is home
    Car(){
        CarID = "";
        CurrentFloor = 3;
        tripCounter = 0;
        State = 1;
        //ServiceQueueUp.appendNode(CurrentFloor);
        //ServiceQueueDown.appendNode(CurrentFloor);
    }
    
    Car(string ID, int Currentfloor_its_on){
        CarID = ID;
        CurrentFloor = Currentfloor_its_on;
        tripCounter = 0;
        State = 1;
        //ServiceQueueUp.appendNode(CurrentFloor);
        //ServiceQueueDown.appendNode(CurrentFloor);
    }
    
    //~Car();
    
    //////Get&set Function//////////
    void setCarID(string a){
        CarID = a;
    }
    
    string getCarID(){
        return CarID;
    }
    
    void setCurrentFloor(int a){
        CurrentFloor = a;
    }
    
    int getCurrentFloor(){
        return CurrentFloor;
    }
    
    /////////Only for the purpose of debugging
    void setTripDirection(string a){
        tripDirection = a;
    }
    
    string getTripDirection(){
        return tripDirection;
    }
    
   /*
    void setTripCounter(int a){
        tripCounter = a;
    }
    */
    
    int getTripCount(){
        return tripCounter;
    }
    
    int getFloorservedbyTrip(){
        return floorServedByTrip;
    }
    
    void setState (int a){
        State = a;
    }
    
    string WaitIdle(){
        cout << "Idle/ Wait State" << endl;
        return "1. Idle/ Wait State";
    }
    
    string Accelerate(){
        cout << "Accelerate" << endl;
        return "2. Accelerate";
    }
    
    string ConstantMotion(){
        cout << "Constant Motion" << endl;
        return "3. Constant Motion";
    }
    
    string Decelerate(){
        cout << "Decelerate" << endl;
        return "4. Delecrate";
    }
    
    string OpensDoor(){
        cout << "Opens door, takes in passengers and closes door" << endl;
        return "Opens Door";
    }
    //Translate the state into the status of the elevator
    void getState(){
        if(State == 1)
            WaitIdle();
        else if(State == 2)
            Accelerate();
        else if(State == 3)
            ConstantMotion();
        else if(State == 4)
            Decelerate();
        else
            cout << "Invalid State" << endl;
    }
    
    /////////Only for the purpose of debugging
    //Check ServiceQueue Up
    void getServiceQueueUp(){
        ServiceQueueUp.showQueue();
    }
    
    /////////Only for the purpose of debugging
    //Check ServiceQueue Down
    void getServiceQueueDown(){
        ServiceQueueDown.showQueue();
    }
    
    /////////////ELEVATOR RUNS////////////////
    //Everytime a new client uses push the Hallway Button, this is the operation of elevator
    // 1. The Elevator is idle(State1). The Hallway Button get pushed, the first clients are push_back onto the vector of clients serving
    void HallwayButtonPushed(Passenger A){
        
        //The Passenger push the button
        A.setHallwayButton();
        // The passenger profile's got pushed into the list (vector) of passengers currently waiting to be served
        ListofPassenger.push_back(A);
    }
    
    // 2. Starting a trip, the first position of the first request will determine the trip direction, if the car is idle. If the car is moving, no need to do this and just continue to load clients' order into the queue.
    void MovingUporDown(){
        if(State == 1){
        Passenger temp = ListofPassenger[0];
        if(temp.getoriginFloor() == CurrentFloor){
            if(temp.getHallwayButton().UpButton == true)
                tripDirection = "Up";
            else
                //I realize that they could both be going up and down, I'm going to prioritize going up.
                tripDirection = "Down";
            }
        else{
        if (temp.getoriginFloor() < CurrentFloor)
            tripDirection = "Down";
        else if(temp.getoriginFloor() > CurrentFloor)
            tripDirection = "Up";
        }
    }
        else
            return;
    }
    
    // 3. Every order afterwards will be added into the ServiceQueueUp or ServiceQueueDown, for individual passenger (Not for the entire vector, it would be too wasteful of processing time
    void HallwayOrderProcessed(Passenger A){
        if(A.getoriginFloor() > CurrentFloor)
            ServiceQueueUp.InsertNodeUp(A.getoriginFloor());
        else if(A.getoriginFloor() < CurrentFloor)
            ServiceQueueDown.InsertNodeDown(A.getoriginFloor());
        else
            OpensDoor();
    }
    
    // 4. Motor pull of push the car. The car software will send signals to the motors to control it 
    void MotorInteraction(){
        if(State == 1)
            carMotor.stop();
        
        else if(State == 2){
            if(tripDirection == "Up")
                carMotor.accelerateUp();
            else if(tripDirection == "Down")
                carMotor.accelerateDown();
        }
        
        else if(State == 3){
            if(tripDirection == "Up")
                carMotor.MoveConstantSpeedUp();
            else if(tripDirection == "Down")
                carMotor.MoveConstantSpeedDown();
        }
        
        else if(State == 4){
         if(tripDirection == "Up")
             carMotor.decelerateUp();
        else if(tripDirection == "Down")
            carMotor.decelerateDown();
        }
    }
    

    // 5. Car moves starts a trip, only in one directions
    void Carmovesbetweenfloor(int DestinationFloor){
        if(tripDirection == "Up"){
            //Accelerate. It will acccelerate for 1 floor
            State = 2;
            getState();
            MotorInteraction();
            
            //Constant Motion. It will move in a constant speed for however many floors are in between the 2 floors. So if there are no floors in between, the car doesn't move in a constant speed at all
            State = 3;
            for (int i = 0; i< abs(DestinationFloor - CurrentFloor)-1; i++ ){
                getState();
            }
            MotorInteraction();
            
            //Decelerate. It will decelerate for 1 floor
            State = 4;
            getState();
            MotorInteraction();
            
            //The car stops and opens the door
            State = 1;
            getState();
            MotorInteraction();
            OpensDoor();
            
            //Currentfloor is now Destination floor and close door
            CurrentFloor = DestinationFloor;
        }
    }
    
    // 6. The Passenger is in the car and started pushing the controller button, to order which floor to go to
    void ControllerOrderProcessed(Passenger A){
        if(A.getdestFloor() > CurrentFloor)
            ServiceQueueUp.InsertNodeUp(A.getoriginFloor());
        else if(A.getdestFloor() < CurrentFloor)
            ServiceQueueDown.InsertNodeDown(A.getoriginFloor());
    }
    
    //////// MAIN OPERATIONS OF THE ELEVATOR////////
    //I. One single trip in one direction
    void ElevatorSmallTrip(vector<Passenger> PassengerVector){
        // Depends on the position of the first person to push the button, the car will decide to go up or down
        HallwayButtonPushed(PassengerVector[0]);
        MovingUporDown();
        
        // Iterate through the entire vector to add orders into the queues
        for (int i = 0; i < PassengerVector.size(); i++){
            HallwayOrderProcessed(PassengerVector[i]);
        }
        
        if(tripDirection == "Up"){
            
        }
    }

};

#endif /* Car_hpp */
