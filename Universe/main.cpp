//  main.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/17/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include <list>
#include <algorithm>
#include <iostream>
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>
#include "GLException.h"
#include "Window.h"
#include "Shader.h"
#include "Body.h"
#include "God.h"

const int WIN_WIDTH  = 2500;
const int WIN_HEIGHT = 1440;

void draw(Window*, ShaderProgram*);
void scrollFunc(GLFWwindow*, double x, double y);

int main(int argc, const char * argv[]) {
    // Initialize window
    Window* window = new Window(WIN_WIDTH, WIN_HEIGHT, "OpenGL");
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
    GLuint vbo, ebo, vao;
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    glGenVertexArrays(1, &vao);
    
    // Get where position is located in the shader program
    GLint colorLoc = program->getUniformLocation("color");
    
    GLint viewWidth  = window->getFrameBufferWidth(),
          viewHeight = window->getFrameBufferHeight();
    
    God* god = new God(viewWidth, viewHeight);
    std::list<std::reference_wrapper<Body>> bodies = god->bodies;
    
    while (!window->shouldClose()) {
        viewWidth  = window->getFrameBufferWidth();
        viewHeight = window->getFrameBufferHeight();
        glViewport(0, 0, viewWidth, viewHeight);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Set color
        glUniform4f(colorLoc, 1.0, 1.0, 1.0, 1.0);
        
        std::list<std::reference_wrapper<Body>>::iterator b;
        std::for_each(std::begin(bodies), std::end(bodies), [&window, &vbo, &ebo, &vao] (std::reference_wrapper<Body> b) {
            Body* body = &b.get();
            short segCount = body->getNumSegments();
            
            float bufferData[(segCount + 1) * 2 + 2];
            body->getVertices(bufferData);
            
            // Add verts to buffer then unbind VBO
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, NULL);
            
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            unsigned short indexData[segCount*3];
            body->getIndices(indexData);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);
            
            glBindVertexArray(vao);
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
            glBindBuffer(GL_ARRAY_BUFFER, NULL);
            glBindVertexArray(NULL);
            
            // Render objects
            glBindVertexArray(vao);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glDrawElements(GL_TRIANGLE_FAN, segCount*3, GL_UNSIGNED_SHORT, nullptr);
            glBindVertexArray(NULL);
            
            body->updatePosition(window->getDeltaTime());
        });
        
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



