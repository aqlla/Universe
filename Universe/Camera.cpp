//
//  Camera.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/19/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#include "Camera.h"

Camera::Camera() {
    _position = glm::vec3(0.0, 0.0, 0.0);
    _rotation = glm::vec3(0.0, 0.0, 0.0);
    
    _moveSpeed = 2.0;
    _rotateSpeed = 5.0;
}