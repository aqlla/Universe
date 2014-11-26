//
//  GLException.h
//  Universe
//
//  Created by Aquilla Sherrock on 11/18/14.
//  Copyright (c) 2014 Aquilla Sherrock. All rights reserved.
//

#ifndef __Universe__GLException__
#define __Universe__GLException__

#include <iostream>

class GLException : public std::exception
{
private:
    std::string _what;
public:
    GLException(std::string what);
    virtual ~GLException() throw();
    virtual const char* what();
};

#endif /* defined(__Universe__GLException__) */
