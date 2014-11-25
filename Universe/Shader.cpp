//  Shader.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include "Shader.h"

Shader::Shader(std::string path, GLenum type) {
    this->_shaderID = glCreateShader(type);
    
    // Open input stream from ShaderProgram
    std::ifstream fin;
    fin.open(path.c_str());
    
    if (!fin.is_open()) {
        fin.close();
        throw GLException("file not found: " + path);
    }
    
    // Read shader program into string
    std::string source((std::istreambuf_iterator<GLchar>(fin)), std::istreambuf_iterator<GLchar>());
    fin.close();
    
    // Cast source to C string
    const GLchar* shaderSource = source.c_str();
    
    // Set and compile source code
    glShaderSource(this->_shaderID, 1, &shaderSource, NULL);
    glCompileShader(this->_shaderID);
    
    // Get status of source compilation
    GLint compileStatus;
    glGetShaderiv(this->_shaderID, GL_COMPILE_STATUS, &compileStatus);
    
    if (compileStatus != GL_TRUE) {
        GLint infoLogLength;
        glGetShaderiv(this->_shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        GLchar* infoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(this->_shaderID, infoLogLength, NULL, infoLog);
        
        std::cout << infoLog << std::endl;
        delete infoLog;
        
        throw GLException("Shader failed to compile: " + path);
    }
}

Shader::~Shader() {
    glDeleteShader(this->_shaderID);
}

GLuint Shader::getID() {
    return this->_shaderID;
}