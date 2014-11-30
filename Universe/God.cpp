//  God.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/22/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include "God.h"

const int God::numBodies = 2000;
const int God::maxR = 1500;
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
    for (std::list<std::reference_wrapper<Body>>::iterator b1 = bodies.begin(); b1 != bodies.end(); ++b1) {
//        (*b1).get().processGravity(ref(bodies));
        pair_t netForce {0,0};
        
        for (std::list<std::reference_wrapper<Body>>::iterator b2 = bodies.begin(); b2 != bodies.end(); ++b2) {
            if (b1 != b2) {
                pair_t force = (*b1).get().getForce(*b2);
                netForce.x += force.x;
                netForce.y += force.y;
            }
        }
        
        (*b1).get().accelerate(netForce);
    }
    
//    std::list<std::reference_wrapper<Body>>::iterator b;
//    std::for_each(std::begin(bodies), std::end(bodies), [this] (std::reference_wrapper<Body> b1) {
//        pair_t netF {0, 0};
//        std::for_each(std::begin(bodies), std::end(bodies), [b1] (std::reference_wrapper<Body> b2) {
//            if (b1.get() != b2.get()) {
//                pair_t f = (*b1).get().getForce();
//                
//            }
//        });
//    });
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
