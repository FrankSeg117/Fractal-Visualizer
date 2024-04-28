#include "Tree.h"

void Tree::update(){}

void Tree::draw(){

    draw(ofGetWidth() / 2, ofGetHeight() - 20, level, length, 1.5 * PI,0);
    draw(ofGetWidth() / 2 + 700, ofGetHeight() + 100, level, length/2, 1.5 * PI,0);
    draw(ofGetWidth() / 2 - 700, ofGetHeight() + 100, level, length/2, 1.5 * PI,0);
}

void Tree::draw(float x, float y, int n, float length, float rad, int colorindex){
    if (n == 0) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofSetColor(colores[colorindex]); 
    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::white); //reset the color back to white

    draw(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI,colorindex+1);
    draw(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI,colorindex+1);

}