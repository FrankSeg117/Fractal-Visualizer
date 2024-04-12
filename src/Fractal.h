#pragma once

#include "ofMain.h"

class Fractal{
    public:
        virtual void draw() = 0;
        virtual string getName() = 0;
        virtual int getLevel() = 0;
        
        //No se si se van a utilizar
        virtual void setName() = 0;
        virtual void setLevel() = 0;

};