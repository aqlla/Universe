//  GLException.cpp
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.

#include "GLException.h"

GLException::GLException(std::string what)
: _what(what) {}

GLException::~GLException() throw() {
    std::exception::exception();
}

const char* GLException::what() {
    return this->_what.c_str();
}

