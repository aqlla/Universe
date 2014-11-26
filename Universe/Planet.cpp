//
//  Planet.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/25/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#include "Planet.h"

const float Planet::MIN_DENSITY = 3;
const float Planet::MAX_DENSITY = 10;
const float Planet::MIN_RADIUS = 1;
const float Planet::MAX_RADIUS = 8;
const float Planet::MIN_V = 50;
const float Planet::MAX_V = 200;

Planet::Planet(int x, int y)
:Body(randi(MIN_RADIUS, MAX_RADIUS), x, y, randi(Planet::MIN_DENSITY, Planet::MAX_DENSITY)) {
    if (x == 0) x = 1;
    if (y == 0) y = 1;
    setVelocity(randi(-MAX_V, MAX_V), randi(-MAX_V, MAX_V));
}