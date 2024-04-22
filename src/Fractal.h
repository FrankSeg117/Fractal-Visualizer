#pragma once

#include "ofMain.h"

class Fractal{
    public:
       
        virtual string getName() = 0;
        virtual int getLevel() = 0;
        
        //No se si se van a utilizar //Si se usan :)
        virtual void setName(string name) = 0; //este env q no
        virtual void setLevel(int level) = 0; //por lo menos este es esencial mano

        virtual void increaseLevel() = 0;
        virtual void decreaseLevel() = 0;
        
        virtual void draw() = 0;
        virtual void update() = 0;
};