#pragma once

#include "ofMain.h"
#include "Fractal.h"

class AbstractFractal : public Fractal {
    protected:
        string name;
        int level;
        int maxLevel;
        int minLevel;
        int animationSpeed;

    // Esto se tiene que modificar para la fase 3
    public:
        AbstractFractal(){}
    //Constructor
        AbstractFractal(string name, int level, int maxLevel, int minLevel, int animationSpeed){
            this->name = name;
            this->level = level;
            this->maxLevel = maxLevel;
            this->minLevel  = minLevel;
            this->animationSpeed = animationSpeed;
        }

    // Getters
        string getName(){return name;}
        int getLevel(){return level;}
        int getMaxLevel(){return maxLevel;}
        int getMinLevel(){return minLevel;}
        int getAnimationSpeed(){return animationSpeed;}

    //Setters
        void setName(string name){this->name = name;}
        void setLevel(int level){this->level = level;}
        void setMaxLevel(int maxLevel){this->maxLevel = maxLevel;}
        void setMinLevel(int minLevel){this->minLevel = minLevel;}
        void setAnimationSpeed(int animationSpeed){this->animationSpeed = animationSpeed;}

        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void increaseLevel() = 0;
        virtual void decreaseLevel() = 0;
};