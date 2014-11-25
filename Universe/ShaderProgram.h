//  ShaderProgram.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#ifndef __Universe__ShaderProgram__
#define __Universe__ShaderProgram__

#include <vector>
#include <istream>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "Shader.h"
#include "GLException.h"

class ShaderProgram {
private:
    GLint _programID;
public:
    ShaderProgram();
    ShaderProgram(std::vector<Shader*> shaders);
    virtual ~ShaderProgram();
    
    void attachShader(Shader* shader);
    void bindFragDataLocation(GLuint colorAttachment, std::string name);
    void link();
    void use();
    
    GLint getAttributeLocation(std::string name);
    GLint getUniformLocation(std::string name);
};

#endif /* defined(__Universe__ShaderProgram__) */
