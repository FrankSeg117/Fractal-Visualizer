#include "Triangle.h"

void Triangle::update(){}

void Triangle::draw(){

    draw((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, level,0);

}

void Triangle::draw(float x, float y, float size, int n, int colorindex){
    if (n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofSetColor(colores[colorindex]); 
    ofDrawTriangle(a, b, c);
    ofSetColor(ofColor::white);

    draw(x, y, size / 2, n - 1, colorindex);
    draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1, colorindex);
    draw((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1, colorindex+1);
}