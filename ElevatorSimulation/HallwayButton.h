// Data Structures Laboratory
// Section 004
// Homework
// 12/09/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens and Ayumi Mutoh
//

#ifndef HallwayButton_h
#define HallwayButton_h

#include <stdio.h>
#include <string>

using namespace std;

struct HallwayButton{
    bool UpButton;
    bool DownButton;
    
    HallwayButton(){
        UpButton = false;
        DownButton = false;
    }
};

#endif /* HallwayButton_h */
