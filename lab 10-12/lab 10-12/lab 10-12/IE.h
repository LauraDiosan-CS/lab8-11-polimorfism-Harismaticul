#ifndef IE_H
#define IE_H

#include "IE.h"
#include <stdlib.h>
#include <cstring>
using namespace std;


class IE{
public:
    virtual IE* clone() = 0;
    virtual void copy(IE*) = 0;
    virtual bool equals(IE*) = 0;
    virtual string toString() = 0;
    virtual ~IE(){};
};


#endif

