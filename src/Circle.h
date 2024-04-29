#pragma once

#include "ofMain.h"
#include "AbstractFractal.h"

class Circle : public AbstractFractal {
    protected:
    float angle = 0;
    float r = 0.31 * ofGetHeight();
    float s = 0.01;

    public:

    Circle(string name, int level, int maxLevel, int minLevel, int animationSpeed) : AbstractFractal(name, level, maxLevel, minLevel, animationSpeed){}

    Circle(string name, int level, int maxLevel, int minLevel, int animationSpeed, float angle, float r) : AbstractFractal(name, level, maxLevel, minLevel, animationSpeed){
        this->angle = angle;
        this->r = r;
    }

    virtual void update();
    virtual void draw();
    virtual void draw(float x, float y, float r, int level, int colorindex);

    virtual void increaseLevel(){
        if(this->getLevel()<this->getMaxLevel()){
        this->setLevel(this->getLevel()+1);}
        }
    virtual void decreaseLevel(){
        if(this->getLevel()>this->getMinLevel()){
        this->setLevel(this->getLevel()-1);}
    }
    void setAngle(float angle){ this->angle = angle;}
    float getAngle(){return this->angle;}

    vector<ofColor> colores = {ofColor::springGreen, ofColor::turquoise, ofColor::lightGoldenRodYellow, ofColor::hotPink, ofColor::cyan};

};