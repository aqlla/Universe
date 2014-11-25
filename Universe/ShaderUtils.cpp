//  ShaderUtils.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include "ShaderUtils.h"

GLuint ShaderUtils::createShaderFromFile(const GLchar* path, GLenum shaderType) {
    GLuint shaderID = glCreateShader(shaderType);
    
    // Open input stream from ShaderProgram
    std::ifstream fin;
    fin.open(path);
    
    if (!fin.is_open()) {
        fin.close();
        std::cout << "file not found: " << path << std::endl;
        return 0;
    }
    
    
    // Read shader program into string
    std::string source((std::istreambuf_iterator<GLchar>(fin)), std::istreambuf_iterator<GLchar>());
    fin.close();
    
    // Cast source to C string
    const GLchar* shaderSource = source.c_str();
    
    #ifdef _DEBUG
    std::cout << "Source Open: " << path << std::endl;
    std::cout << shaderSource << std::endl << std::endl;
    #endif
    
    // Set and compile source code
    glShaderSource(shaderID, 1, &shaderSource, NULL);
    glCompileShader(shaderID);
    
    // Get status of source compilation
    GLint compileStatus;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
    
    #ifdef _DEBUG
    std::cout << "Source Compile Status: " << path << std::endl;
    std::cout << compileStatus << std::endl << std::endl;
    #endif
    
    if (compileStatus != GL_TRUE) {
        std::cout << "Shader failed to compile: " << path << std::endl;
        
        GLint infoLogLength;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        GLchar* infoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shaderID, infoLogLength, NULL, infoLog);
        
        std::cout << infoLog << std::endl;
        delete infoLog;
        
        return 0;
    }
    
    return shaderID;
}

GLuint ShaderUtils::createProgramFromShaders(const GLuint vertexShader, const GLuint fragmentShader) {
    GLint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    
    // Bind fragment data location
    glBindFragDataLocation(shaderProgram, 0, "fragData");
    glLinkProgram(shaderProgram);
    
    GLint linkStatus;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkStatus);
    
    if (linkStatus != GL_TRUE) {
        std::cout << "Program link failed!" << std::endl;
        
        GLint infoLogLength;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        GLchar* infoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, infoLog);
        
        std::cout << infoLog << std::endl;
        delete infoLog;
        
        return 0;
    }
    
    return shaderProgram;
}