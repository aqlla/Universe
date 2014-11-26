//
//  Star.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/25/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#include "Star.h"

const float Star::DENSITY = 80;
const float Star::MIN_RADIUS = 40;
const float Star::MAX_RADIUS = 70;

Star::Star()
:Body(MAX_RADIUS, 0, 0, Star::DENSITY) {}