#pragma once

#include "ofMain.h"

class Fractal{
    public:
       
        virtual string getName() = 0;
        virtual int getLevel() = 0;
        virtual int getMaxLevel() = 0;
        virtual int getMinLevel() = 0;
        virtual int getAnimationSpeed() = 0;
        
        //No se si se van a utilizar //Si se usan :)
        virtual void setName(string name) = 0; //este env q no
        virtual void setLevel(int level) = 0; //por lo menos este es esencial mano
        virtual void setMaxLevel(int maxLevel) = 0;
        virtual void setMinLevel(int minLevel) = 0;
        virtual void setAnimationSpeed(int animationSpeed) = 0;

        //Metodos abstractos para cambiar profundidad en todos los fractales
        virtual void increaseLevel() = 0;
        virtual void decreaseLevel() = 0;
        
        virtual void draw() = 0;
        virtual void update() = 0;
};