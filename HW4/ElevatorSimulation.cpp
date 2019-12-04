//
//  main.cpp
//  ElevatorSimulation
//
//  Created by Macbook on 12/1/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#include <iostream>
#include "Passenger.h"
#include "Car.h"
#include "Motor.h"
#include "HallwayButton.h"
#include "ServiceQueue.h"

using namespace std;

int main() {
    
    Passenger P1("P1", 3, 7);
    Passenger P2("P2", 2, 1);
    Passenger P3("P3", 2, 6);
    Passenger P4("P4", 3, 9);
    Passenger P5("P5", 4, 2);
    Passenger P6("P6", 7, 6);
    Passenger P7("P7", 4, 8);
    Passenger P8("P8", 3, 2);
    Passenger P9("P9", 3, 6);
    Passenger P10("P10", 2, 12);
    Passenger P11("P11", 1, 2);
    Passenger P12("P12", 5, 8);
    
    
    Car C1 ("C1", 3);
    
    //////TESTING Car function
    //Step 1: A bunch of people push the Hallway Button
    C1.HallwayButtonPushed(P1);
    C1.HallwayButtonPushed(P2);
    C1.HallwayButtonPushed(P3);
    C1.HallwayButtonPushed(P4);
    C1.HallwayButtonPushed(P5);
    C1.HallwayButtonPushed(P6);
    C1.HallwayButtonPushed(P7);
    C1.HallwayButtonPushed(P8);
    C1.HallwayButtonPushed(P9);
    C1.HallwayButtonPushed(P10);
    C1.HallwayButtonPushed(P11);
    C1.HallwayButtonPushed(P12);
    
    C1.MovingUporDown();
    
    cout << "The trip direction is: " << C1.getTripDirection() << endl;
    
    C1.HallwayOrderProcessed(P1);
    C1.HallwayOrderProcessed(P2);
    C1.HallwayOrderProcessed(P3);
    C1.HallwayOrderProcessed(P4);
    C1.HallwayOrderProcessed(P5);
    C1.HallwayOrderProcessed(P6);
    C1.HallwayOrderProcessed(P7);
    C1.HallwayOrderProcessed(P8);
    C1.HallwayOrderProcessed(P9);
    C1.HallwayOrderProcessed(P10);
    C1.HallwayOrderProcessed(P11);
    C1.HallwayOrderProcessed(P12);
    
    cout << "The service queue up is: " << endl;
    C1.getServiceQueueUp();
    cout << endl;
    
    cout << "The service queue down is: " << endl;
    C1.getServiceQueueDown();
    cout << endl;
    
    cout << "Car moves to floor 3 to 4: " << endl;
    C1.Carmovesbetweenfloor(1);

    
    return 420;
}
