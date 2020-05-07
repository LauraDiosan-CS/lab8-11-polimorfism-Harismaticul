#ifndef IE_H
#define IE_H

#include "IE.h"
#include <stdlib.h>

class IE{
public:
    virtual IE* clone() = 0;
    virtual void copy(IE*) = 0;
    virtual bool equals(IE*) = 0;
    virtual int compareTo(IE*) = 0;
    virtual char* toString() = 0;
    virtual ~IE(){};
};


#endif

