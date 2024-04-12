#pragma once

#include "ofMain.h"
#include "Fractal.h"

class AbstractFractal : public Fractal {
    public:
    // Esto se tiene que modificar para la fase 3
        string name;
        int level;

        AbstractFractal(string name, int level){
            this->name = name;
            this->level = level;
        }

    // Getters
        string getName(){return name;}
        int getLevel(){return level;}

    //Setters
        string setName(string name){this->name = name;}
        int setLevel(int level){this->level = level;}

        virtual void draw() = 0;

};