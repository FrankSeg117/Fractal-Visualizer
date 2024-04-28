#pragma once

#include "ofMain.h"
#include "AbstractFractal.h"

class Fern : public AbstractFractal {
    protected:
        float size = 0.88 * ofGetHeight();

    public:

    Fern(string name, int level) : AbstractFractal(name, level){}

    virtual void update();
    virtual void draw();
    virtual void draw(float x, float y, float n);

    virtual void increaseLevel(){
        if(this->getLevel()<50){
        this->setLevel(this->getLevel()+5);}
        }
    virtual void decreaseLevel(){
        if(this->getLevel()>5){
        this->setLevel(this->getLevel()-5);}
    }

    vector<ofColor> colores = {
        ofColor(255, 0, 0),     // Red
        ofColor(0, 255, 0),     // Green
        ofColor(0, 0, 255),     // Blue
        ofColor(255, 255, 0),   // Yellow
        ofColor(255, 0, 255),   // Magenta
        ofColor(0, 255, 255),   // Cyan
        ofColor(255, 127, 0),   // Orange
        ofColor(127, 0, 255),   // Purple
        ofColor(255, 255, 255), // White
        ofColor(255, 192, 203)  // Pink
    };

};