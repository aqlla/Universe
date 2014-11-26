//  God.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/22/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#ifndef __Universe__God__
#define __Universe__God__

#include <iostream>
#include <list>
#include "Planet.h"
#include "Star.h"
#include "Body.h"
#include "pair.h"

class God {
private:
    const static int numBodies;
    const static int maxV;
    const static int maxPx;
    const static int maxPy;
    const static int maxR;
    const static int minR;
    
    int windowWidth;
    int windowHeight;
    
    int randi(int min, int max);
public:
    God(int windowWidth, int windowHeight);
    virtual ~God();
    
    void checkCollisions();
    void processGravity();
    
    std::list<std::reference_wrapper<Body>> bodies;
};


#endif /* defined(__Universe__God__) */
