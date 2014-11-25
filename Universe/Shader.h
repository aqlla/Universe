//  Shader.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#ifndef __Universe__Shader__
#define __Universe__Shader__

#include <iostream>
#include <fstream>
#include <GLFW/glfw3.h>
#include "GLException.h"

class Shader {
private:
    GLuint _shaderID;
public:
    Shader(std::string path, GLenum type);
    virtual ~Shader();
    
    GLuint getID();
};

#endif /* defined(__Universe__Shader__) */
