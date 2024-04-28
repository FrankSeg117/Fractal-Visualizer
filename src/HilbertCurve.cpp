#include "HilbertCurve.h"

void HilbertCurve::update(){}

void HilbertCurve::draw(){
    draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2, ofGetWindowWidth(), ofGetWindowHeight(),0, level,0);
}

void HilbertCurve::draw(float cx, float cy, float sizex, float sizey, int angle, int n, int colorindex){
    ofPushMatrix();
    ofTranslate(cx,cy);
    ofRotateDeg(angle);
    if(n > 1){
        draw(-sizex/4, -sizey/4, sizex/2, sizey/2, 0, n-1, colorindex + 1 );
        draw(sizex/4, -sizey/4, sizex/2, sizey/2, 0, n-1, colorindex + 2);
        draw(-sizex/4, sizey/4, sizex/2, sizey/2, 90, n-1, colorindex + 3);
        draw(sizex/4, sizey/4, sizex/2, sizey/2, -90, n-1, colorindex + 4);
    }
    float shrink = pow(2,n+1);
    ofSetColor(colores[colorindex]); 
    ofDrawLine({(-sizex/shrink), - sizey/shrink},{(sizex/shrink), - sizey/shrink});
    ofDrawLine({-(sizex/2-sizex/shrink), -(sizey/shrink)},{-(sizex/2-sizex/shrink), sizey/shrink});
    ofDrawLine({(sizex/2-sizex/shrink), -(sizey/shrink)},{(sizex/2-sizex/shrink), sizey/shrink});
    ofSetColor(ofColor::white);
    ofPopMatrix();
}