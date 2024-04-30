#include "Bird.h"

void Bird::update(){}

void Bird::draw(){
    draw(level,0);
}

void Bird::draw(int n, int colorindex){
    if(n == 20000){
            return;
        }
      x = ofGetWindowWidth()/2.0 + ((3.0*n)/45'000.0 + sin((17.0*PI/20.0)*pow((n/20'000.0),5.0))*pow(cos((41.0*PI*n)/20'000.0),6.0) + ((1.0/3.0)*pow(cos((41.0*PI*n)/20'000.0),16.0)+(1.0/3.0)*pow(cos((41.0*PI*n)/20'000.0),80.0))*pow(cos((PI*n)/40'000.0),12.0)*sin((6.0*PI*n)/20'000.0))*-381.25;
      y= ofGetWindowHeight()*0.3625 + (15.0/30.0*(pow(n/20'000.0,4.0)) - cos((17.0*PI)/20.0*pow(n/20'000.0,5.0))*(11.0/10.0 + 45.0/20.0*pow(cos((PI*n)/40'000.0),8.0)*pow(cos((3.0*PI*n)/40'000.0),6.0))*pow(cos((41.0*PI*n)/20'000.0),6.0) + 12.0/20.0*pow(cos((3.0*PI*n)/200'000.0),10.0)*pow(cos((9.0*PI*n)/200'000.0),10.0)*pow(cos((18.0*PI*n)/200'000.0),10.0))*-381.25;
      r = (0.02 + 0.025*pow(sin(41.0*PI*n/20000.0),2.0)*pow(sin(9.0*PI*n/200000.0),2.0) + 1.0/17.0*pow(cos(41.0*PI*n/20000.0),2.0)*pow(cos(PI*n/40000.0),10.0))*381.25;
    
      if(colorindex == colores.size()){
        draw(n+1,0);
      }
      else if(n%83 == 0){
        ofSetColor(colores[colorindex]);
        ofDrawCircle(x,y,r);
        ofSetColor(ofColor::white);
        draw(n+1,colorindex+1);
      }else{
      ofSetColor(colores[colorindex]);
      ofDrawCircle(x,y,r);
      ofSetColor(ofColor::white);
      draw(n+1, colorindex);
      }
}
