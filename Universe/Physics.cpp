//  Physics.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/20/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include "Physics.h"

const double Physics::deg2rad = PI / 180;

double Physics::soh(double opposite, double hypoteneuse) {
    return opposite / hypoteneuse;
}

double Physics::cah(double adjacent, double hypoteneuse) {
    return adjacent / hypoteneuse;
}

double Physics::toa(double opposite, double adjacent) {
    return opposite / adjacent;
}

double Physics::volumeFromRadius(double radius) {
    return (4.0/3.0) * PI * std::pow(radius, 3);
}

double Physics::sphereRadiusFromVolume(double volume) {
    return std::pow(volume / ((4.0/3.0) * PI), 1.0/3.0);
}

double Physics::hypoteneuse(pair_t legs) {
    return std::sqrt(legs.x * legs.x + legs.y * legs.y);
}

