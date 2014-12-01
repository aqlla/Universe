//  God.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/22/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include "God.h"

const int God::numBodies = 3000;
const int God::maxR = 2000;
const int God::minR = 300;

God::God(int windowWidth, int windowHeight)
: windowWidth(windowWidth), windowHeight(windowHeight) {
    Body* sun = new Star();
    bodies.push_back(std::ref(*sun));
    
    for (int i = 0; i < numBodies; ++i) {
        int x = randi(-maxR, maxR);
        int y = randi(-maxR, maxR);

        while (std::sqrt(x*x + y*y) < minR || std::sqrt(x*x + y*y) > maxR) {
            x = randi(-maxR, maxR);
            y = randi(-maxR, maxR);
        }
        
        Body* planet = new Planet(x, y);
        bodies.push_back(std::ref(*planet));
    }
}

God::~God() {
    this->bodies.clear();
}

void God::processGravity() {
    std::list<std::reference_wrapper<Body>>::iterator b;
    std::for_each(std::begin(bodies), std::end(bodies), [this] (std::reference_wrapper<Body> b1) {
        Body& body1 = b1.get();
        pair_t netF {0, 0};
        
        std::for_each(std::begin(bodies), std::end(bodies), [&body1, &netF] (std::reference_wrapper<Body> b2) {
            Body& body2 = b2.get();
            
            if (&body1 != &body2) {
                pair_t f = body1.getForce(body2);
                netF.x += f.x;
                netF.y += f.y;
            }
        });
        
        body1.accelerate(netF);
    });
}

void God::checkCollisions() {
    std::list<std::reference_wrapper<Body>>::iterator b1 = bodies.begin();
    std::list<std::reference_wrapper<Body>>::iterator b2 = bodies.begin();
    
    while (b1 != bodies.end()) {
        while (b2 != bodies.end()) {
            if ((*b1).get().collidesWith(*b2) && b1 != b2) {
                bodies.push_back(std::ref(* new Body((*b1).get(), (*b2).get())));
                
                b2 = bodies.erase(b2);
                b1 = bodies.erase(b1);
                break;
            }
            
            b2++;
        }
        
        b2 = bodies.begin();
        b1++;
    }
}

int God::randi(int min, int max) {
    return min + random() % (max - min + 1);
}
