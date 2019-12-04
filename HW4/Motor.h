//
//  Motor.hpp
//  ElevatorSimulation
//
//  Created by Macbook on 12/1/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
//

#ifndef Motor_hpp
#define Motor_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct Motor{
    string accelerateUp(){
        return "Accelerate Upwards";
    }
    
    string accelerateDown(){
        return "Accelerate Downwards";
    }
    
    string decelerateUp(){
        return "Decelerate Upwards";
    }
    
    string decelerateDown(){
        return "Decelerate Downwards";
    }
    
    string MoveConstantSpeedDown(){
        return "Move Downwards at Constant Speed";
    }
    
    string MoveConstantSpeedUp(){
        return "Move Upwards at Constant Speed";
    }
    
    string stop(){
        return "Stop";
    }
};

#endif /* Motor_hpp */
