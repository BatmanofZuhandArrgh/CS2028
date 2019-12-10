// Data Structures Laboratory
// Section 004
// Homework
// 12/09/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens and Ayumi Mutoh
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
