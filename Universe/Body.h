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

#define SCALE_MAX 2.0
#define SCALE_MIN 0.1

class Body {
private:
    static unsigned instanceCount;
    short segments;
    float segmentStep;
    
    float aspect;
    float dradius;

    pair_t cradius;     // Component radius to compensate for streching
    int vertexCount;
    
    void setBody();
    
    static pair_t centerOfMass(Body& b1, Body& b2);
    static pair_t postCollisionVelocity(Body& b1, Body& b2);
    
    static float viewScale;
    static float bodyScale;
    
public:
    Body(float radius, float x, float y, float density);
    Body(float radius, float x, float y);
    Body(Body& b1, Body& b2);
    virtual ~Body();
    
    static const int viewWidth;
    static const int viewHeight;
    
    pair_t dPosition;   // Display position
    float radius;
    float mass;
    
    pair_t velocity;
    pair_t position;
    
    static void setViewScale(float change);
    static void setBodyScale(float change);
    
    void accelerate(pair_t force);
    bool collidesWith(Body& other);
    void setVelocity(float x, float y);
    void updatePosition(double deltaTime);
    void processGravity(std::list<std::reference_wrapper<Body>>& others);
    
    
    // Get body metrics
    virtual bool isStar();
    float getMass();
    float getVolume();
    pair_t getMomentum();
    pair_t getForce(Body& other);
    pair_t getDistanceFrom(Body& other);
    float getDistanceFromSurface(Body& other);
    
    /* Getter functions providing information for OpenGL to display
    the bodies */
    short getNumSegments();
    void getVertices(float* bufferData);
    void getIndices(unsigned short* indexData);

    std::string toString() const;
    
    int randi(int min, int max);
};

#endif /* defined(__Universe__Body__) */



