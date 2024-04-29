#pragma once

#include "ofMain.h"
#include <cmath>

#include "AbstractFractal.h"

/**
 * @brief Koch SnowFlake Fractal
 *
 */

class SnowFlake : public AbstractFractal{
  private:
    glm::vec2 start;
    glm::vec2 end;

    // int SFdrawdepth = 5;
  public:
    //Overloaded Constructors
    SnowFlake() {}
    SnowFlake(string name, int level, int maxLevel, int minLevel, int animationSpeed) : AbstractFractal(name, level, maxLevel, minLevel, animationSpeed){}
    SnowFlake(glm::vec2 start, glm::vec2 end) {
        this->start = start;
        this->end = end;
    }
    //Deconstructor
    virtual ~SnowFlake() {}

    //Methods for draw
    glm::vec2 getStart() const { return start; }
    glm::vec2 getEnd() const { return end; }
    void setStart(glm::vec2 start) { this->start = start; }
    void setEnd(glm::vec2 end) { this->end = end; }

    // void setLevel(int depth){this->SFdrawdepth=depth;}
    // int getDepth(){return this->SFdrawdepth;}
    void update();
    void draw();
    void draw(int n, SnowFlake *flake,int colorindex);

    virtual void increaseLevel(){
        if(this->getLevel()<this->getMaxLevel()){
        this->setLevel(this->getLevel()+1);}
        }
    virtual void decreaseLevel(){
        if(this->getLevel()>this->getMinLevel()){
        this->setLevel(this->getLevel()-1);}
    }

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