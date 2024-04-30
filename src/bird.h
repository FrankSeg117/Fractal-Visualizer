#pragma once

#include "ofMain.h"
#include "AbstractFractal.h"

class Bird : public AbstractFractal {

    public:
    long double x;
    long double y;
    long double r;

    Bird(string name, int level, int maxLevel, int minLevel, int animationSpeed) : AbstractFractal(name, level, maxLevel, minLevel, animationSpeed){}

    virtual void update();
    virtual void draw();
    virtual void draw(int n, int colorindex);

    virtual void increaseLevel(){
        if(this->getLevel()>this->getMaxLevel()){
        this->setLevel(this->getLevel()-5000);}
        }
    virtual void decreaseLevel(){
        if(this->getLevel()<this->getMinLevel()){
        this->setLevel(this->getLevel()+5000);}
    }

    //vector<ofColor> colores = {ofColor::green, ofColor::green, ofColor::skyBlue, ofColor::red,ofColor::red}; 
    // vector<ofColor> colores = {ofColor::skyBlue, ofColor::red, ofColor::red,ofColor::red, ofColor::red,ofColor::red,ofColor::red, 
    //                            ofColor::skyBlue, ofColor::red,ofColor::red, ofColor::skyBlue, ofColor::red,ofColor::red, ofColor::skyBlue, 
    //                            ofColor::red,ofColor::red, ofColor::skyBlue, ofColor::red,ofColor::red, ofColor::skyBlue,ofColor::red,ofColor::red, 
    //                            ofColor::skyBlue, ofColor::green, ofColor::green, ofColor::green, ofColor::green, ofColor::green, ofColor::green,
    //                            ofColor::green, ofColor::green, ofColor::green, ofColor::green, ofColor::green, ofColor::green }; 
        vector<ofColor> colores = {ofColor::skyBlue, ofColor::red, ofColor::red,ofColor::red, ofColor::red,ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue,
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue,
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue,
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue,
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue, 
                               ofColor::red, ofColor::red,ofColor::red, ofColor::red, ofColor::skyBlue,ofColor::skyBlue}; 

};