//
//  Planet.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/25/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#include "Planet.h"

const float Planet::MIN_DENSITY = 500;
const float Planet::MAX_DENSITY = 1000;
const float Planet::MIN_RADIUS = 1;
const float Planet::MAX_RADIUS = 8;
const float Planet::MIN_V = 30;
const float Planet::MAX_V = 85;

Planet::Planet(int x, int y): Body(randi(MIN_RADIUS, MAX_RADIUS), x, y, randi(Planet::MIN_DENSITY, Planet::MAX_DENSITY))
{
    pair_t v {
        std::abs(position.y),
        std::abs(position.x)
    };
    
    double r = Physics::hypoteneuse(v);
    
    if (position.x > 0 && position.y > 0) {
        v.x = -v.x;
    } else if (position.x < 0 && position.y > 0) {
        v.x = -v.x;
        v.y = -v.y;
    } else if (position.x < 0 && position.y < 0) {
        v.y = -v.y;
    }
    
    
    setVelocity((v.x * randi(MIN_V, MAX_V)) / r, (v.y * randi(MIN_V, MAX_V)) / r);
}