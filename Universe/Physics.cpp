//  Physics.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/20/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include "Physics.h"

const double Physics::deg2rad = PI / 180;

float Physics::soh(float opposite, float hypoteneuse) {
    return opposite / hypoteneuse;
}

float Physics::cah(float adjacent, float hypoteneuse) {
    return adjacent / hypoteneuse;
}

float Physics::toa(float opposite, float adjacent) {
    return opposite / adjacent;
}

float Physics::volumeFromRadius(float radius) {
    return (4.0/3.0) * PI * std::pow(radius, 3);
}

float Physics::sphereRadiusFromVolume(float volume) {
    return std::pow(volume / ((4.0/3.0) * PI), 1.0/3.0);
}

float Physics::hypoteneuse(pair_t legs) {
    return std::sqrt(legs.x * legs.x + legs.y * legs.y);
}

