// Data Structures Laboratory
// Section 004
// Homework
// 12/09/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens and Ayumi Mutoh
//

#ifndef ElevatorCar_h
#define ElevatorCar_h

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Motor.h"
#include "HallwayButton.h"
#include "ServiceQueue.h"
#include "Clock.h"

using namespace std;

class ElevatorCar{
private:
    //Inherent information
    string CarID;
    int CurrentFloor;
    
    //Operation-related information
    ServiceQueue<int> ServiceQueueUp;
    ServiceQueue<int> ServiceQueueDown;
    
    //List of passengers in the car at a moment
    ServiceQueue<Passenger> ServiceQueueCurrent;
    string tripDirection;
    int State;
    
    //Time-related information
    Clock Timer;
    Clock Statetimer;
    int TripCounter = 0;
    int MaxWaitTime;
    int MaxTravelTime;
    double TotalWaitTime;
    double TotalTravelTime;
    
    //HallwayButton-related information
    HallwayButton CarHBttn;
    
    //Motor-related information
    Motor carMotor;
    
public:
    //Information about every single trip
    ServiceQueue<Passenger> QueueofPassengerRequested;
    //For later when we will populate this with the passengers' profiles who've been served
    vector<Passenger> ListofPassengerServed;
    
    //////Constructors&Destructors for Car///////
    //Default constructor with no trips yet and currently idle, current floor is home
    ElevatorCar(){
        CarID = "";
        CurrentFloor = 3;
        State = 1;
    }
    
    ElevatorCar(string ID, int Currentfloor_its_on){
        CarID = ID;
        CurrentFloor = Currentfloor_its_on;
        State = 1;
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
    
    void setTripDirection(string a){
        tripDirection = a;
    }
    
    void switchTripDirection(){
        if(tripDirection == "Up")
            tripDirection = "Down";
        else if(tripDirection == "Down")
            tripDirection = "Up";
    }
    string getTripDirection(){
        return tripDirection;
    }
    
    void setState (int a){
        State = a;
    }
    
    ////////////////ACTIONS BASED ON EACH STATE OF THE CAR
    string WaitIdle(){
        cout << "Idle/ Wait State" << endl;
        return "1. Idle/ Wait State";
    }
    
    string Accelerate(){
        cout << "Accelerate" << endl;
        Timer.add(2);
        return "2. Accelerate";
    }
    
    string ConstantMotion(){
        cout << "Constant Motion" << endl;
        Timer.add(2);
        return "3. Constant Motion";
    }
    
    string Decelerate(){
        cout << "Decelerate" << endl;
        Timer.add(2);
        return "4. Decelerate";
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
    
    void setTimer(int a){
        Timer.setTimer(a);
    }
    
    void getTimer(){
        Timer.dispTime();
    }
    /////////Only for the purpose of debugging
    //Check ServiceQueue Up
    void showServiceQueueUp(){
        ServiceQueueUp.showQueue();
    }
    
    /////////Only for the purpose of debugging
    //Check ServiceQueue Down
    void showServiceQueueDown(){
        ServiceQueueDown.showQueue();
    }
    
    ServiceQueue<int> getServiceQueueUp(){
        return ServiceQueueUp;
    }
    
    ServiceQueue<int> getServiceQueueDown(){
        return ServiceQueueDown;
    }
    
    void showServiceQueueCurrent(){
        ServiceQueueCurrent.showQueue();
    }
    
    ServiceQueue<Passenger> getServiceQueueCurrent(){
        return ServiceQueueCurrent;
    }
    
    //Calculating Max time and average time
    void CalculatingMaxWaitTime(vector<Passenger> &PassengerVector){
        TotalWaitTime = 0;
        MaxWaitTime = PassengerVector[0].getWaitTime().getTimer();
        for(int i=0; i < PassengerVector.size(); i++){
            if(PassengerVector[i].getServed() == true){
                TotalWaitTime = TotalWaitTime + PassengerVector[i].getWaitTime().getTimer();
                if(MaxWaitTime < PassengerVector[i].getWaitTime().getTimer())
                    MaxWaitTime = PassengerVector[i].getWaitTime().getTimer();
            }
        }
    }
    
    void CalculatingMaxTravelTime(vector<Passenger> &PassengerVector){
        TotalTravelTime = 0;
        MaxTravelTime = PassengerVector[0].getTravelTime().getTimer();
        for(int i=0; i < PassengerVector.size(); i++){
            if(PassengerVector[i].getServed() == true){
                TotalTravelTime = TotalTravelTime + PassengerVector[i].getTravelTime().getTimer();
                if(MaxTravelTime < PassengerVector[i].getTravelTime().getTimer())
                    MaxTravelTime = PassengerVector[i].getTravelTime().getTimer();
            }
        }
    }
    
    /////////////////Parts Function that'll help elevator run/////////////////////
    //1. The Hallwaybutton gets pushed and the floor of the passenger will be added into the RequestQueue
    void HallwayOrderProcessed(Passenger A){
        if(A.getoriginFloor() > CurrentFloor)
            ServiceQueueUp.InsertNodeUp(A.getoriginFloor());
        else if(A.getoriginFloor() < CurrentFloor)
            ServiceQueueDown.InsertNodeDown(A.getoriginFloor());
        
    }
    
    // 2. The Passenger is in the car and started pushing the controller button, to order which floor to go to
    void ControllerOrderProcessed(Passenger A){
        if(A.getdestFloor() > CurrentFloor)
            ServiceQueueUp.InsertNodeUp(A.getdestFloor());
        else if(A.getdestFloor() < CurrentFloor)
            ServiceQueueDown.InsertNodeDown(A.getdestFloor());
    }
    
    // 3. Check if the current floor has order
    void checkCurrentFloorforRequests(vector<Passenger> &PassengerVector){
        
        // Check if the current floor has anyone wanting to order on it, if yes, decelerate, opens doors, and queue their request
        for(int i = 0; i< PassengerVector.size(); i++){
            if( (PassengerVector[i].getTimeRequest().getTimer() <= Timer.getTimer()) &&  (PassengerVector[i].getoriginFloor() == CurrentFloor) && (!ServiceQueueCurrent.isIn(PassengerVector[i])) && PassengerVector[i].getServed() == false ){
                if(!QueueofPassengerRequested.isIn(PassengerVector[i]))
                    QueueofPassengerRequested.appendNode(PassengerVector[i]);
                OpensDoor();
                PassengerVector[i].GetIn();
                ControllerOrderProcessed(PassengerVector[i]);
                ServiceQueueCurrent.appendNode(PassengerVector[i]);
            }
        }
        
        //If there are people wantning to get down on this floor, opens door, let them get out, delete them from request queue and archive their profile
        ServiceQueueCurrent.reset();
        while(ServiceQueueCurrent.seeCurrentPointer() != nullptr){
            if(ServiceQueueCurrent.seeCurrent().getdestFloor() == CurrentFloor){
                OpensDoor();
                ServiceQueueCurrent.seeCurrent().GetOut();
                
                for (int i = 0; i<PassengerVector.size(); i++){
                    if(ServiceQueueCurrent.seeCurrent() == PassengerVector[i])
                        PassengerVector[i].setServed(true);
                }
                
                Passenger P = ServiceQueueCurrent.seeCurrent();
                ListofPassengerServed.push_back(P);
                QueueofPassengerRequested.deleteNode(P);
                ServiceQueueCurrent.deleteNode(P);
                cout << endl;
                cout << "The list of requests are: " << endl;
                QueueofPassengerRequested.showQueue();
                cout << endl;
            }
            ServiceQueueCurrent.seeNext();
        }
        
        //Add 2 seconds for the time of opening the door. Since I didn't put the add timer into the opendoor() function
        if(ServiceQueueUp.isIn(CurrentFloor)){
            ServiceQueueUp.dequeue();
        }
        else if(ServiceQueueDown.isIn(CurrentFloor)){
            ServiceQueueDown.dequeue();
        }
    }
    
    // 4. One state of movement, in a minimum unit of time (2 seconds)
    void MoveFromfloor2floor(){
        //We divide the conditions into 2, up and down trips
        ///////////////////UP CONDITION//////////////////
        if(tripDirection == "Up"){
            //If the Statetime starts at 0, which means the elevator is idle
            if(Statetimer.getTimer() == 0){
                //Moving and State changing
                State = 2;
                getState();//Accelerate
                //Increase the Statetimer for the purpose of keeping track
                Statetimer.add(2);
                
                CurrentFloor = CurrentFloor + 1;
                cout << "Accelerate" << endl;
                cout << "Next floor   : "  << ServiceQueueUp.peekHead() << endl;
                cout << "Current Floor: " << CurrentFloor<< endl;
//                cout << "Service Queue up is: " << endl;
//                showServiceQueueUp();
//                Statetimer.dispTime();
                cout << endl;
            }
            //After accelerating it's starting to move at constant speed
            else if (Statetimer.getTimer()>=2 && ((Statetimer.getTimer()/2)%2 == 1) && CurrentFloor !=ServiceQueueUp.peekHead()){
                //Moving and State changing
                State = 3;
                getState();//Moving constant speed
                //Increase the Statetimer for the purpose of keeping track
                Statetimer.add(2);
                
                cout << "Constant Motion 1" << endl;
                cout << "Next floor   : " << ServiceQueueUp.peekHead() << endl;
                cout << "Current Floor: " << CurrentFloor<< endl;
//                cout << "Service Queue up is: " << endl;
//                showServiceQueueUp();
//                Statetimer.dispTime();
                cout << endl;
            }
            //It takes 4 seconds to move through 1 floor
            else if (Statetimer.getTimer()>=2 && ((Statetimer.getTimer()/2)%2 == 0) && CurrentFloor !=ServiceQueueUp.peekHead()){
                //Moving and State changing
                State = 3;
                getState();
                //Increase the Statetimer for the purpose of keeping track
                Statetimer.add(2);//Moving constant speed
                CurrentFloor = CurrentFloor + 1; //Prepare to decelarate
                
                cout << "Constant Motion 2" << endl;
                cout << "Next floor   : " << ServiceQueueUp.peekHead() << endl;
                cout << "Current Floor: " << CurrentFloor<< endl;
//                cout << "Service Queue up is: " << endl;
//                showServiceQueueUp();
//                Statetimer.dispTime();
                cout << endl;
            }
            else if (Statetimer.getTimer()>=2 && CurrentFloor == ServiceQueueUp.peekHead()){
                //Moving and State changing
                //Moving and State changing
                State = 4;
                getState();//Decelerate
                Statetimer.setTimer(0); //Restart the state timer
                
                State = 1; //Stop and wait
                getState();
                //ServiceQueueUp.dequeue();
                cout << "Decelerate and stop" << endl;
                cout << "Next floor is  " << ServiceQueueUp.peekHead() << endl;
                cout << "Current Floor: " << CurrentFloor<< endl;
//                cout << "Service Queue up is: " << endl;
//                showServiceQueueUp();
//                Statetimer.dispTime();
                cout << endl;

            }
            
        }//End of conditional tripDirection = Up
        /////////DOWN CONDITION/////////////////////////////////////
        else if(tripDirection == "Down"){
            //If the Statetime starts at 0, which means the elevator is idle
            if(Statetimer.getTimer() == 0){
                //Moving and State changing
                State = 2;
                getState();//Accelerate
                //Increase the Statetimer for the purpose of keeping track
                Statetimer.add(2);
                
                CurrentFloor = CurrentFloor - 1;
                //cout << "StateTimer: " << Statetimer.getTimer() << endl;
                cout << "Accelerate" << endl;
                cout << "Next floor   : "  << ServiceQueueDown.peekHead() << endl;
                cout << "Current Floor: " << CurrentFloor<< endl;
//                cout << "Service Queue Down is: " << endl;
//                showServiceQueueDown();
//                Statetimer.dispTime();
                cout << endl;
            }
            //After accelerating it's starting to move at constant speed
            else if (Statetimer.getTimer()>=2 && ((Statetimer.getTimer()/2)%2 == 1) && CurrentFloor !=ServiceQueueDown.peekHead()){
                //Moving and State changing
                State = 3;
                getState();//Moving constant speed
                //Increase the Statetimer for the purpose of keeping track
                Statetimer.add(2);
                cout << "Constant Motion 1" << endl;
                cout << "Next floor   : "  << ServiceQueueDown.peekHead() << endl;
                cout << "Current Floor: " << CurrentFloor<< endl;
//                cout << "Service Queue Down is: " << endl;
//                showServiceQueueDown();
//                Statetimer.dispTime();
                cout << endl;
                //cout << "StateTimer: " << Statetimer.getTimer() << endl;
            }
            //It takes 4 seconds to move through 1 floor
            else if (Statetimer.getTimer()>=2 && ((Statetimer.getTimer()/2)%2 == 0) && CurrentFloor !=ServiceQueueDown.peekHead()){
                //Moving and State changing
                State = 3;
                getState();
                //Increase the Statetimer for the purpose of keeping track
                Statetimer.add(2);//Moving constant speed
                
                //cout << "Goes down one more floor"<< endl;
                CurrentFloor = CurrentFloor - 1; //Prepare to decelarate}
                //cout << CurrentFloor << endl;
            
                //cout << "StateTimer: " << Statetimer.getTimer() << endl;
                cout << "Constant Motion 2" << endl;
                cout << "Next floor   : "  << ServiceQueueDown.peekHead() << endl;
                cout << "Current Floor: " << CurrentFloor<< endl;
//                cout << "Service Queue Down is: " << endl;
//                showServiceQueueDown();
//                Statetimer.dispTime();
                cout << endl;
            }
            else if (Statetimer.getTimer()>=2 && CurrentFloor == ServiceQueueDown.peekHead()){
                //Moving and State changing
                State = 4;
                getState();//Decelerate
                MotorInteraction();
                
                //ServiceQueueDown.dequeue();
                State = 1; //Stop and wait
                getState();
                Statetimer.setTimer(0); //Restart the state timer
                //cout << "StateTimer: " << Statetimer.getTimer() << endl;
                cout << "Decelerate and stop" << endl;
                cout << "Next floor   : "  << ServiceQueueDown.peekHead() << endl;
                cout << "Current Floor: " << CurrentFloor<< endl;
//                cout << "Service Queue Down is: " << endl;
//                showServiceQueueDown();
//                Statetimer.dispTime();
                cout << endl;
            }
        }//End of Conditionals tripDirection == down
        MotorInteraction();
    }//End the function void Movefromfloor2floor
    
    // 5. Motor pull of push the car. The car software will send signals to the motors to control it
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
    
    //6. Time passes for all passengers.
    void timePassesPassengers(vector<Passenger> &PassengerVector){
        for(int i= 0; i< PassengerVector.size(); i++){
            if(ServiceQueueCurrent.isIn(PassengerVector[i])){
                PassengerVector[i].travelTimepasses();
            }
            else if(PassengerVector[i].getin_or_out_Car() == "Out" && QueueofPassengerRequested.isIn(PassengerVector[i])){
                PassengerVector[i].waitTimepasses();
            }
        }
    }
    
    /////////////////ELEVATOR RUNS///////////////////////
    //I. Beginning of the trip, decide if the trip's gonna be up or down, start the Hallway Timer
    void BeginningtoMoveUporDown(vector<Passenger> &PassengerVector){
        //Set the timer to equal the first timer of the passsenger in the vector
        Timer.setTimer(PassengerVector[0].getTimeRequest().getTimer());
        
        //All the passengers presseng the Hallway at the same time as the Timer start will be added into the GuestQueue
        for(int i = 0; i< PassengerVector.size(); i++){
            //cout << "checkin"<< endl;
            if(PassengerVector[i].getTimeRequest().getTimer() == Timer.getTimer()){
                QueueofPassengerRequested.appendNode(PassengerVector[i]);
                
                //If the person is on the floor the elevator is currently on
                if(PassengerVector[i].getoriginFloor() == CurrentFloor){
                    OpensDoor();
                    PassengerVector[i].GetIn();
                    //The people input the button
                    ControllerOrderProcessed(PassengerVector[i]);
                    ServiceQueueCurrent.appendNode(PassengerVector[i]);
                }
                else{
                    HallwayOrderProcessed(PassengerVector[i]);
                }
            }
        }
        

            // If at first the car goes both up and down, it will prioritize Up every time.
        if(QueueofPassengerRequested.seeAt(0).getoriginFloor() == CurrentFloor){
            // If there are bunch of people in side the elevator, it will prioritze the first
            if(QueueofPassengerRequested.seeAt(0).getoriginFloor() > QueueofPassengerRequested.seeAt(0).getdestFloor())
                tripDirection = "Down";
            else
                tripDirection = "Up";
                }
        else if(!ServiceQueueUp.isEmpty())
            tripDirection = "Up";
        else if(!ServiceQueueDown.isEmpty())
            tripDirection = "Down";
    }
    
    //II. 1 trip, either up or down
    void ElevatorSmallTrip(vector<Passenger> &PassengerVector){
        if (tripDirection == "Up"){
        while (!ServiceQueueUp.isEmpty()) {
            
            //Check if at this very moment anyone is pushing the hallway button
            for(int i = 0; i< PassengerVector.size(); i++){
                if( (PassengerVector[i].getTimeRequest().getTimer() <= Timer.getTimer()) && !QueueofPassengerRequested.isIn(PassengerVector[i]) && PassengerVector[i].getServed() == false ){
                    //Add request into the queue
                    QueueofPassengerRequested.appendNode(PassengerVector[i]);
                    cout << "Adding " << PassengerVector[i].getPID() << " order to the queue." << endl;
                    HallwayOrderProcessed(PassengerVector[i]);
                }
            }
            
            MoveFromfloor2floor();
            timePassesPassengers(PassengerVector);
            
            if(State == 1)
            checkCurrentFloorforRequests(PassengerVector);
        }
        }//Ending Up condition
        
        else if(tripDirection == "Down"){
            while (!ServiceQueueDown.isEmpty()) {
                
                //Check if at this very moment anyone is pushing the hallway button
                for(int i = 0; i< PassengerVector.size(); i++){
                    if( (PassengerVector[i].getTimeRequest().getTimer() <= Timer.getTimer()) && !QueueofPassengerRequested.isIn(PassengerVector[i]) && PassengerVector[i].getServed() == false ){
                        //Add request into the queue
                        QueueofPassengerRequested.appendNode(PassengerVector[i]);
                        cout << "Adding " << PassengerVector[i].getPID() << " order to the queue." << endl;
                        HallwayOrderProcessed(PassengerVector[i]);
                    }
                }
                
                MoveFromfloor2floor();
                timePassesPassengers(PassengerVector);

                if(State == 1)
                    checkCurrentFloorforRequests(PassengerVector);
            }
        }//Ending the Down condition
       TripCounter = TripCounter +1;
    }
    
    // III. Showing Customer profiles
    void GeneratePassengersProfiles(vector<Passenger> &PassengerVector){
        cout << "PASSENGERS REPORT" << endl;
        for(int i=0; i < PassengerVector.size(); i++){
            if(PassengerVector[i].getServed() == true){
                PassengerVector[i].GenerateReport();
            }
        }
    }
    
    // IV. Generate Elevator report
    void GenerateElevatorReport(vector<Passenger> &PassengerVector){
        cout << "ELEVATOR REPORT" << endl;
        
        double count = 0;
        cout << "List of Passengers served: " << endl;
        for(int i = 0; i<ListofPassengerServed.size(); i++){
            cout << ListofPassengerServed[i] << endl;
            count = count + 1;
        }
        cout << endl;
        cout << "1. The car has served: " << count << " people." << endl;
        cout << "2. The number of trips taken: " << TripCounter << endl;
        cout << endl;
        CalculatingMaxWaitTime(PassengerVector);
        CalculatingMaxTravelTime(PassengerVector);
        
        cout << "3a. The maximum wait time  : " << MaxWaitTime << endl;
        cout << "3b. The average wait time  : " << TotalWaitTime/count << endl;
        cout << endl;
        cout << "4a. The maximum travel time: " << MaxTravelTime << endl;
        cout << "4b. The average travel time: " << TotalTravelTime/count << endl;
        cout << endl;
    }
    
    //V. Multiple small trips, up and down and up and down
    void ElevatorBigTrip(vector<Passenger> &PassengerVector){
        BeginningtoMoveUporDown(PassengerVector);
        
        while(!QueueofPassengerRequested.isEmpty()){
            ElevatorSmallTrip(PassengerVector);
            switchTripDirection();
            cout << "The Trip Direction is: "<< tripDirection << endl;
        }
        
        GeneratePassengersProfiles(PassengerVector);
        GenerateElevatorReport(PassengerVector);
    }

};


    
#endif /* ElevatorCar_h */
