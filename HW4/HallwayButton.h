//
//  HallwayButton.h
//  ElevatorSimulation
//
//  Created by Macbook on 12/1/19.
//  Copyright © 2019 Anh Nguyen. All rights reserved.
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
