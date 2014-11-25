//  Body.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/19/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#ifndef __Universe__Body__
#define __Universe__Body__

#include "Physics.h"
#include "pair.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <list>

class Body {
private:
    static unsigned instanceCount;
    short segments;
    float segmentStep;
    
    float aspect;
    float dradius;
    

    pair_t cradius;     // Component radius to compensate for streching
    pair_t dPosition;   // Display position
    int vertexCount;
    
    void setBody();
    
    static pair_t centerOfMass(Body& b1, Body& b2);
    static pair_t postCollisionVelocity(Body& b1, Body& b2);
public:
    Body(double radius, float x, float y);
    Body(Body& b1, Body& b2);
    virtual ~Body();
    
    static const int viewWidth;
    static const int viewHeight;
    
    double radius;
    double mass;
    
    pair_t velocity;
    pair_t position;
    
    void accelerate(pair_t force);
    void setVelocity(double x, double y);
    void updatePosition(double deltaTime);
    bool collidesWith(Body& other);
    
    
    // Get body metrics
    double getMass();
    double getVolume();
    pair_t getMomentum();
    pair_t getForce(Body& other);
    pair_t getDistanceFrom(Body& other);
    double getDistanceFromSurface(Body& other);
    
    
    /* Getter functions providing information for OpenGL to display
    the bodies */
    short getNumSegments();
    void getVertices(float* bufferData);
    void getIndices(unsigned short* indexData);

    
    std::string toString() const;
};

#endif /* defined(__Universe__Body__) */



