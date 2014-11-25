//
//  ShaderProgram.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
    this->_programID = glCreateProgram();
}

ShaderProgram::ShaderProgram(std::vector<Shader*> shaders) {
    this->_programID = glCreateProgram();
    
    for (int i = 0; i < shaders.size(); i++) {
        glAttachShader(this->_programID, shaders[i]->getID());
    }
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->_programID);
}

void ShaderProgram::attachShader(Shader* shader) {
    glAttachShader(this->_programID, shader->getID());
}

void ShaderProgram::bindFragDataLocation(GLuint colorAttachment, std::string name) {
    // Bind fragment data location
    glBindFragDataLocation(this->_programID, 0, name.c_str());
}

void ShaderProgram::link() {
    GLint linkStatus;
    
    glLinkProgram(this->_programID);
    glGetProgramiv(this->_programID, GL_LINK_STATUS, &linkStatus);
    
    if (linkStatus != GL_TRUE) {
        GLint infoLogLength;
        glGetProgramiv(this->_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        GLchar* infoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(this->_programID, infoLogLength, NULL, infoLog);
        
        std::cout << infoLog << std::endl;
        delete infoLog;
        
        throw GLException("Program link failed!");
    }
}

void ShaderProgram::use() {
    glUseProgram(this->_programID);
}

GLint ShaderProgram::getAttributeLocation(std::string name) {
    return glGetAttribLocation(this->_programID, name.c_str());
}

GLint ShaderProgram::getUniformLocation(std::string name) {
    return glGetUniformLocation(this->_programID, name.c_str());
}