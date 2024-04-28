#include "Fern.h"

void Fern::update(){}

void Fern::draw(){

    draw(0, 0, level * 1000);

}

void Fern::draw(float x, float y, float n){
    if (n <= 0) return;
    int colorindex=0;

    //With this method we set groups of particles to be of a certaint color
    if(n>45000){
        colorindex=0;
    }
    else if(n>40000){
        colorindex=4;
    }
    else if(n>35000){
        colorindex=5;
    }
    else if(n>30000){
        colorindex=6;
    }
    else if(n>25000){
        colorindex=7;
    }
    else if(n>20000){
        colorindex=7;
    }
    else if(n>15000){
        colorindex=8;
    }
    else if(n>10000){
        colorindex=9;
    }
    else if(n>5000){
        colorindex=10;
    }
    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    ofFill();

    ofSetColor(colores[colorindex]);
    // ofSetColor(ofColor::green);
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        draw(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        draw(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        draw(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        draw(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}