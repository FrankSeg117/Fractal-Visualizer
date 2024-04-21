#pragma once

#include "ofMain.h"
#include <cmath>

/**
 * @brief Koch SnowFlake Fractal
 *
 */

class SnowFlake {
  private:
    glm::vec2 start;
    glm::vec2 end;

    int SFdrawdepth = 5;
  public:
    SnowFlake();
    SnowFlake(glm::vec2 start, glm::vec2 end);

    glm::vec2 getStart() const { return start; }
    glm::vec2 getEnd() const { return end; }
    void setStart(glm::vec2 start) { this->start = start; }
    void setEnd(glm::vec2 end) { this->end = end; }

    void setLevel(int depth){this->SFdrawdepth=depth;}
    int getDepth(){return this->SFdrawdepth;}

    void draw();
    void draw(int n, SnowFlake *flake,int colorindex);

    glm::vec2 getA();
    glm::vec2 getB();
    glm::vec2 getC();
    glm::vec2 getD();
    glm::vec2 getE();

vector<ofColor> colors = {
    ofColor::blue,               
    ofColor::cornflowerBlue,     
    ofColor::deepSkyBlue,        
    ofColor::dodgerBlue,         
    ofColor::lightSkyBlue,       
    ofColor::mediumTurquoise,
    ofColor::skyBlue,             
    ofColor::steelBlue,           
    ofColor::royalBlue,           
    ofColor::powderBlue,          
    ofColor::lightSteelBlue,      
    ofColor::turquoise             
};



};