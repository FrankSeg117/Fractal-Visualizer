#pragma once

#include "ofMain.h"
#include "AbstractFractal.h"

class Tree : public AbstractFractal {
    protected:
        float length = 0.31 * ofGetHeight();

    public:

    Tree(string name, int level, int maxLevel, int minLevel, int animationSpeed) : AbstractFractal(name, level, maxLevel, minLevel, animationSpeed){}

    virtual void update();
    virtual void draw();
    virtual void draw(float x, float y, int n, float length, float rad, int colorindex);

    virtual void increaseLevel(){
        if(this->getLevel()<this->getMaxLevel()){
        this->setLevel(this->getLevel()+1);}
        }
    virtual void decreaseLevel(){
        if(this->getLevel()>this->getMinLevel()){
        this->setLevel(this->getLevel()-1);}
    }

    vector<ofColor> colores = {ofColor::brown, ofColor::rosyBrown, ofColor::burlyWood, ofColor::sandyBrown, ofColor::olive,
                               ofColor::green, ofColor::limeGreen, ofColor::forestGreen, ofColor::seaGreen, ofColor::springGreen,
                               ofColor::paleGreen,ofColor::darkGreen,ofColor::greenYellow,ofColor::ghostWhite,ofColor::hotPink, //<-End point
                               ofColor::lightGoldenRodYellow,ofColor::lime,ofColor::lemonChiffon}; //<-Extra locations in case of a big oof
};