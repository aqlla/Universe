//
//  Planet.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/25/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#ifndef __Universe__Planet__
#define __Universe__Planet__

#include "Body.h"
#include "Physics.h"

class Planet: public Body {
private:
    static const float MAX_DENSITY;
    static const float MIN_DENSITY;
    static const float MAX_RADIUS;
    static const float MIN_RADIUS;
    static const float MAX_V;
    static const float MIN_V;
    
public:
    Planet(int x, int y);
};

#endif /* defined(__Universe__Planet__) */
