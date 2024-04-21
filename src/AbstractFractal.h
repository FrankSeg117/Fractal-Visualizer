#pragma once

#include "ofMain.h"
#include "Fractal.h"

class AbstractFractal : public Fractal {
    protected:
        string name;
        int level;

    // Esto se tiene que modificar para la fase 3
    public:

    //Constructor
        AbstractFractal(string name, int level){
            this->name = name;
            this->level = level;
        }

    // Getters
        string getName(){return name;}
        int getLevel(){return level;}

    //Setters
        void setName(string name){this->name = name;}
        void setLevel(int level){this->level = level;}

        virtual void draw() = 0;
        virtual void update() = 0;
};