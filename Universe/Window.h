//  Window.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#ifndef __Universe__Window__
#define __Universe__Window__

#include <iostream>
#include <GLFW/glfw3.h>
#include "GLException.h"

#define _black 0.0, 0.0, 0.0, 1.0
#define _white 1.0, 1.0, 1.0, 1.0
#define _green 0.0, 1.0, 0.0, 1.0
#define clr(color) glClearColor(color)

class Window {
private:
    static GLint instanceCount;
    GLFWwindow* _window;
    
    GLdouble lastBufferSwapTime;
    GLdouble deltaDime;

    GLint initialWidth;
    GLint initialHeight;

    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    
public:
    Window(GLint width, GLint height, std::string title);
    virtual ~Window();
    
    void makeContextCurrent();
    bool shouldClose();
    GLint getFrameBufferWidth();
    GLint getFrameBufferHeight();
    void swapBuffers();
    GLdouble getDeltaTime();
    GLFWwindow* getWindow();
    
    GLint getInitialWidth();
    GLint getInitialHeight();
};

#endif /* defined(__Universe__Window__) */
