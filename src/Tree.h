#pragma once

#include "ofMain.h"
#include "AbstractFractal.h"

class Tree : public AbstractFractal {
    protected:
        float length = 0.31 * ofGetHeight();

    public:

    Tree(string name, int level) : AbstractFractal(name, level){}

    virtual void update();
    virtual void draw();
    virtual void draw(float x, float y, int n, float length, float rad, int colorindex);

    vector<ofColor> colores = {ofColor::brown, ofColor::rosyBrown, ofColor::burlyWood, ofColor::sandyBrown, ofColor::olive,
                               ofColor::green, ofColor::limeGreen, ofColor::forestGreen, ofColor::seaGreen, ofColor::springGreen,
                               ofColor::paleGreen,ofColor::darkGreen,ofColor::greenYellow,ofColor::ghostWhite,ofColor::hotPink, //<-End point
                               ofColor::lightGoldenRodYellow,ofColor::lime,ofColor::lemonChiffon}; //<-Extra locations in case of a big oof
};