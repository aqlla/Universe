//
//  Star.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/25/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#include "Star.h"

const float Star::DENSITY = 10000;
const float Star::MIN_RADIUS = 50;
const float Star::MAX_RADIUS = 65;

Star::Star()
:Body(MAX_RADIUS, 0, 0, Star::DENSITY) {}

bool Star::isStar() {
    return true;
}