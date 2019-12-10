// Data Structures Laboratory
// Section 004
// Homework
// 12/09/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens and Ayumi Mutoh
//

#ifndef Passenger_hpp
#define Passenger_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "HallwayButton.h"
#include "Clock.h"

using namespace std;

class Passenger{
private:
    // Inherent information
    string PID;
    int originFloor;
    int destFloor;
    bool Served;
    
    // Operation-related information
    string in_or_out_Car = "Out";
    HallwayButton HBttn; //HallwayButton
    
    // Time-related information
    Clock TimeRequested;
    Clock WaitTimer;
    Clock TravelTimer;
    
public:
    //////////////Constructors&Destructors for Passenger/////////////
    //The beginning passengers doesn't have a floor, and wanting to go into the elevator car
    Passenger(){
        PID = "";
        originFloor = 0;
        destFloor = 0;
        TimeRequested.setTimer(0);
        Served = false;
    }
    
    Passenger(string a, int b, int c, int d){
        PID = a;
        originFloor = b;
        destFloor = c;
        TimeRequested.setTimer(d);
        Served = false;
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
    
    void setServed(bool a){
        Served = a;
    }
    
    bool getServed(){
        return Served;
    }
    
    //Changing the status of served boolean
    void changeStatusofServed(){
        if(Served == false)
            Served = true;
    }
    
    //Time-related functions
    void waitTimepasses(){
        WaitTimer.add(2);
    }
    
    void travelTimepasses(){
        TravelTimer.add(2);
    }
    
    void setWaitTime(int a){
        WaitTimer.setTimer(a);
    }
    
    Clock getWaitTime(){
        return WaitTimer;
    }
    
    void showWaitTime(){
        cout << WaitTimer.getTimer() << endl;
    }
    
    void setTravelTime(int a){
        TravelTimer.setTimer(a);
    }
    
    Clock getTravelTime(){
        return TravelTimer;
    }
    
    void showTravelTime(){
        cout << TravelTimer.getTimer() << endl;
    }
    
    void setTimeRequest(int a, int b, int c){
        TimeRequested.setHours(a);
        TimeRequested.setMinutes(b);
        TimeRequested.setSeconds(c);
    }
    
    Clock getTimeRequest(){
        return TimeRequested;
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
    HallwayButton pushHallwayButton(){
        setHallwayButton();
        return HBttn;
    }
    
    //Get in the car
    void GetIn(){
        in_or_out_Car = "In";
        cout << "Passenger " << PID << " gets in the elevator, wanting to go to the " << destFloor << " floor." << endl;
    }
    
    //Get out of the car
    void GetOut(){
        in_or_out_Car = "Out";
        setServed(true);
        cout << "The passenger is served " << getServed() << endl;
        cout << "Passenger " << PID << " gets out of the elevator" << endl;
    }
    
    //Overload
    bool operator == (const Passenger & obj){
        if(PID == obj.PID)
            return true;
        else
            return false;}
    
    bool operator != (const Passenger & obj){
        if(PID != obj.PID)
            return true;
        else
            return false;}
    
    friend ostream& operator<<(ostream &output, const Passenger& a)
    {
        output << a.PID << ":" << a.originFloor << "->" << a.destFloor<< endl;
        return output;
    }
    
    //Time related report
    void GenerateReport(){
        cout << "Profile " << PID << ":" << endl;
        
        Clock temp = TimeRequested;
        temp.add(WaitTimer.getTimer()+TravelTimer.getTimer());
        
        cout << "Moving from floor: " << originFloor << " at ";
        TimeRequested.dispTime();
        cout << "To floor: " << destFloor << " at " << endl;
        temp.dispTime();

        cout << "1. Wait Time  : "<< WaitTimer.getTimer() << " seconds." << endl;
        cout << "2. Travel Time: "<< TravelTimer.getTimer() << " seconds." << endl;
        cout << endl;
    }
    
};


#endif /* Passenger_hpp */
