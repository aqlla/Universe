//
//  Star.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/25/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#ifndef __Universe__Star__
#define __Universe__Star__

#include "Body.h"
#include "Physics.h"

class Star: public Body {
    static const float DENSITY;
    static const float MIN_RADIUS;
    static const float MAX_RADIUS;
public:
    Star();
    
    bool isStar();
};

#endif /* defined(__Universe__Star__) */
