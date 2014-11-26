//  Physics.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/20/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#ifndef __Universe__Physics__
#define __Universe__Physics__

#include <cmath>
#include "pair.h"

#define PI 3.14159265358979323846
#define G 6.67e-5

class Physics {
public:
    static const double deg2rad;
    
    static double soh(double opposite, double hypoteneuse);
    static double cah(double adjacent, double hypoteneuse);
    static double toa(double opposite, double adjacent);
    static double hypoteneuse(pair_t legs);
    
    static double volumeFromRadius(double radius);
    static double sphereRadiusFromVolume(double volume);
};


#endif /* defined(__Universe__Physics__) */
