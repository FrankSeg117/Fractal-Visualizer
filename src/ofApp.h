#pragma once

#include <cmath>
#include "SnowFlake.h"
#include "Fractal3D.h"

#include "ofMain.h"

class ofApp : public ofBaseApp {
  private:
    char mode = '1';
    float angle = 0;

  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void drawMode1(float x, float y, float r, int n);
    void drawMode2(float x, float y, int n, float length, float rad);
    void drawMode3(float x, float y, float size, int n);
    void drawMode4(float x, float y, float n);

    int dm1depth = 3;
    int dm2depth = 10;
    int dm3depth = 7;
    int dm4depth = 10;
    int dm5depth = 3;
    int dm6depth = 3;
    
    SnowFlake lanieve;
    // Fractal3D Triangulitos;

    ofEasyCam cam;
    ofTrueTypeFont text;
    ofTrueTypeFont dataText;
};
