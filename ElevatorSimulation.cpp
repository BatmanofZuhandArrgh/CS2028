// Data Structures Laboratory
// Section 004
// Homework
// 12/09/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens and Ayumi Mutoh
//

#include <iostream>
#include <vector>
#include "Passenger.h"
#include "Car.h"
#include "Motor.h"
#include "HallwayButton.h"
#include "ServiceQueue.h"
#include "Clock.h"
#include "ElevatorCar.h"

using namespace std;

int changeTimetoSecond(int hour, int minute, int second){
    return 3600*hour + 60*minute + second;
}

int main() {
    
    Passenger P1("P1", 6, 8,changeTimetoSecond(7, 0, 0));
    Passenger P2("P2", 3, 6,changeTimetoSecond(7, 0, 5));
    Passenger P3("P3", 6, 8,changeTimetoSecond(7, 0, 2));
    Passenger P4("P4", 6, 1,changeTimetoSecond(7, 0, 5));
    Passenger P5("P5", 2, 5,changeTimetoSecond(7, 0, 1));
    Passenger P6("P6", 7, 6,changeTimetoSecond(7, 0, 12));
    Passenger P7("P7", 4, 8,changeTimetoSecond(7, 0, 15));
    Passenger P8("P8", 3, 2,changeTimetoSecond(7, 0, 17));
    Passenger P9("P9", 3, 1,changeTimetoSecond(7, 0, 18));
    Passenger P10("P10", 2, 12,changeTimetoSecond(8, 6, 0));
    Passenger P11("P11", 1, 2,changeTimetoSecond(9, 10, 5));
    Passenger P12("P12", 5, 8,changeTimetoSecond(9, 10, 7));
    
    ElevatorCar C1 ("C1", 3);
    
    vector<Passenger> PassengerVector1;
    vector<Passenger> PassengerVector2;

    vector<Passenger> PassengerVector3;

    
    PassengerVector1.push_back(P1);
    PassengerVector1.push_back(P2);
    PassengerVector1.push_back(P3);
    PassengerVector1.push_back(P4);
    PassengerVector1.push_back(P5);
    PassengerVector1.push_back(P6);
    PassengerVector1.push_back(P7);
    PassengerVector1.push_back(P8);
    PassengerVector1.push_back(P9);
    
    PassengerVector2.push_back(P10);
    
    PassengerVector3.push_back(P11);
    PassengerVector3.push_back(P12);

    
    
    C1.ElevatorBigTrip(PassengerVector2);

    
    return 420;
}
