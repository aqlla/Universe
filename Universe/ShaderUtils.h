//  ShaderUtils.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#ifndef __Universe__ShaderUtils__
#define __Universe__ShaderUtils__

// #define _DEBUG

#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

class ShaderUtils
{
public:
    static GLuint createShaderFromFile(const GLchar* path, GLenum shaderType);
    static GLuint createProgramFromShaders(const GLuint vertexShader, const GLuint fragmentShader);
};

#endif /* defined(__Universe__ShaderUtils__) */
