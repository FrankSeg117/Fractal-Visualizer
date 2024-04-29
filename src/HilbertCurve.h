#pragma once

#include "ofMain.h"
#include "AbstractFractal.h"

class HilbertCurve : public AbstractFractal {

    public:

    HilbertCurve(string name, int level, int maxLevel, int minLevel, int animationSpeed) : AbstractFractal(name, level, maxLevel, minLevel, animationSpeed){}

    virtual void update();
    virtual void draw();
    virtual void draw(float cx, float cy, float sizex, float sizey, int angle, int n, int colorindex);

    virtual void increaseLevel(){
        if(this->getLevel()<this->getMaxLevel()){
        this->setLevel(this->getLevel()+1);}
        }
    virtual void decreaseLevel(){
        if(this->getLevel()>this->getMinLevel()){
        this->setLevel(this->getLevel()-1);}
    }

    vector<ofColor> colores = {ofColor::silver, ofColor::tomato, ofColor::turquoise, ofColor::goldenRod,ofColor::mediumPurple, 
                               ofColor::silver, ofColor::tomato, ofColor::turquoise, ofColor::goldenRod,ofColor::mediumPurple, 
                               ofColor::silver, ofColor::tomato, ofColor::turquoise, ofColor::goldenRod,ofColor::mediumPurple, 
                               ofColor::silver, ofColor::tomato, ofColor::turquoise, ofColor::goldenRod,ofColor::mediumPurple, 
                               ofColor::silver, ofColor::tomato, ofColor::turquoise, ofColor::goldenRod,ofColor::mediumPurple}; 

};