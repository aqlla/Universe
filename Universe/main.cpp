//  main.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/17/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include <list>
#include <cmath>
#include <iostream>
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>
#include "GLException.h"
#include "Window.h"
#include "Shader.h"
#include "Body.h"
#include "God.h"

const int WIN_WIDTH  = 2200;
const int WIN_HEIGHT = 1440;

void draw(Window*, ShaderProgram*);
void scrollFunc(GLFWwindow*, double x, double y);

God* god;
Window* window;

int main(int argc, const char * argv[]) {
    // Initialize window
    window = new Window(WIN_WIDTH, WIN_HEIGHT, "OpenGL");
    window->makeContextCurrent();
    
    try {
        // Load Shader Programs
        ShaderProgram* program;
        Shader* vertexShader   = new Shader("ShaderProgram.vs", GL_VERTEX_SHADER);
        Shader* fragmentShader = new Shader("ShaderProgram.fs", GL_FRAGMENT_SHADER);
        
        program = new ShaderProgram(std::vector<Shader*> {vertexShader, fragmentShader});
        program->bindFragDataLocation(0, "fragData");
        program->link();
        program->use();
        
        delete vertexShader;
        delete fragmentShader;
        
        window->setScrollCallback(scrollFunc);
        
        draw(window, program);
        
        delete program;
    } catch (GLException e) {
        e.std::exception::what();
    }
    
    delete window;
    
    return 0;
}


void draw(Window* window, ShaderProgram* program) {
    GLuint vbo;
    glGenBuffers(1, &vbo);
    GLuint ebo;
    glGenBuffers(1, &ebo);
    GLuint vao;
    glGenVertexArrays(1, &vao);
    
    // Get where position is located in the shader program
    GLint positionLoc = program->getAttributeLocation("position");
    GLint colorLoc = program->getUniformLocation("color");
    
    GLint viewWidth  = window->getFrameBufferWidth();
    GLint viewHeight = window->getFrameBufferHeight();
    
    god = new God(viewWidth, viewHeight);
    std::list<std::reference_wrapper<Body>> bodies = god->bodies;
    
    while (!window->shouldClose()) {
        viewWidth  = window->getFrameBufferWidth();
        viewHeight = window->getFrameBufferHeight();
        glViewport(0, 0, viewWidth, viewHeight);
        glClear(GL_COLOR_BUFFER_BIT);
        
        for (std::list<std::reference_wrapper<Body>>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
            short segCount = (*it).get().getNumSegments();
            
            float bufferData[(segCount + 1) * 2 + 2];
            (*it).get().getVertices(bufferData);
            
            // Add verts to buffer then unbind VBO
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, NULL);
            
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            unsigned short indexData[segCount*3];
            (*it).get().getIndices(indexData);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);
            
            glBindVertexArray(vao);
            
            glEnableVertexAttribArray(positionLoc);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glVertexAttribPointer(positionLoc, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
            glBindBuffer(GL_ARRAY_BUFFER, NULL);
            glBindVertexArray(NULL);
            
            // Set color
            glUniform4f(colorLoc, 1.0, 1.0, 1.0, 1.0);
            
            // Render objects
            glBindVertexArray(vao);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glDrawElements(GL_TRIANGLE_FAN, segCount*3, GL_UNSIGNED_SHORT, nullptr);
            glBindVertexArray(NULL);
            
            (*it).get().updatePosition(window->getDeltaTime());
        }
        
        god->processGravity();
        god->checkCollisions();
        bodies = god->bodies;
        
        glfwPollEvents();
        window->swapBuffers();
        //        std::cout << "FPS: " << 1 / window->getDeltaTime() << std::endl;
    }
    
    // delete the stuff
    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void scrollFunc(GLFWwindow* window, double x, double y) {
    Body::setViewScale(y);
    Body::setBodyScale(x);
}



