//
//  Window.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#include "Window.h"

GLint Window::instanceCount = 0;

Window::Window(const GLint width, const GLint height, const std::string title) {
    if (Window::instanceCount == 0) {
        GLint glfwStatus = glfwInit();
        
        // Set error callback
        glfwSetErrorCallback(Window::error_callback);
        
        if (glfwStatus != GL_TRUE) {
            glfwTerminate();
            throw GLException("Failed to initialize GLFW.");
        }
        
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    }
    
    // Create a windowed mode window & its OpenGL context
    this->_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    
    if (this->_window == nullptr) {
        glfwTerminate();
        throw GLException("Failed to create window");
    } else {
        // Set key callback
        glfwSetKeyCallback(this->_window, Window::key_callback);
        
        clr(_black);
        
        Window::instanceCount++;
        
        this->initialWidth  = this->getFrameBufferWidth();
        this->initialHeight = this->getFrameBufferHeight();
    }
}

Window::~Window() {
    glfwDestroyWindow(this->_window);
    this->instanceCount--;
    
    if (Window::instanceCount == 0) {
        glfwTerminate();
        std::cout << "GLFW Terminated." << std::endl;
    }
}

void Window::makeContextCurrent() {
    glfwMakeContextCurrent(this->_window);
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(this->_window);
}

GLint Window::getFrameBufferWidth() {
    GLint width;
    glfwGetFramebufferSize(this->_window, &width, nullptr);
    return width;
}

GLint Window::getFrameBufferHeight() {
    GLint height;
    glfwGetFramebufferSize(this->_window, nullptr, &height);
    return height;
}

void Window::swapBuffers() {
    glfwSwapBuffers(this->_window);
    GLdouble currentTime = glfwGetTime();
    this->deltaDime = currentTime - this->lastBufferSwapTime;
    this->lastBufferSwapTime = currentTime;
}

GLdouble Window::getDeltaTime() {
    return this->deltaDime;
}

GLFWwindow* Window::getWindow() {
    return this->_window;
}

GLint Window::getInitialWidth() {
    return this->initialWidth;
}

GLint Window::getInitialHeight() {
    return this->initialHeight;
}

void Window::error_callback(int error, const char* description) {
    fputs(description, stderr);
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}