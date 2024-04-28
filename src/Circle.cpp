#include "Circle.h"

void Circle::update(){
    
    this->setAngle(this->getAngle()+s); //s = 0.01 (Cuan rapido dan vueltas)
    this->setAngle(fmod(this->getAngle(),TWO_PI));
}

void Circle::draw(){

    draw(ofGetWidth() / 2, ofGetHeight() / 2, r, level,0);

}

void Circle::draw(float x, float y, float r, int n, int colorindex){
    if (n == 0) return;

    ofSetColor(colores[colorindex]);
     
    int delta = r * 0.35;
    ofDrawCircle(x, y, r);
    ofSetColor(ofColor::white); //reset the color back to white
    
    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;

    draw(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1,colorindex+1);
    draw(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1,colorindex+1);
    draw(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1,colorindex+1);
    draw(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1,colorindex+1);
    draw(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1,colorindex+1);
    draw(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1,colorindex+1);

}