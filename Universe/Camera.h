//  Camera.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/19/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#ifndef __Universe__Camera__
#define __Universe__Camera__

#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
private:
    glm::vec3 _rotation;
    glm::vec3 _position;
    GLfloat _moveSpeed;
    GLfloat _rotateSpeed;
public:
    Camera();
};

#endif /* defined(__Universe__Camera__) */
