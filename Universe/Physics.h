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
    
    static float soh(float opposite, float hypoteneuse);
    static float cah(float adjacent, float hypoteneuse);
    static float toa(float opposite, float adjacent);
    static float hypoteneuse(pair_t legs);
    
    static float volumeFromRadius(float radius);
    static float sphereRadiusFromVolume(float volume);
};


#endif /* defined(__Universe__Physics__) */
