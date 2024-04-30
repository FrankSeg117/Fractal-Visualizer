#pragma once
#include <cmath>
#include "ofMain.h"
#include "Fractal.h"
#include "AbstractFractal.h"
#include "Circle.h"
#include "Tree.h"
#include "Triangle.h"
#include "Fern.h"
#include "SnowFlake.h"
#include "Fractal3D.h"
#include "HilbertCurve.h"
#include "bird.h"

class ofApp : public ofBaseApp {
  private:
    char mode = '1';
    int index = 1;
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

    void drawMode4(float x, float y, float n);
    void drawmode5(int n, int colorindex);

    vector<Fractal*> Fractals;

    ofEasyCam cam;
    ofTrueTypeFont text;
    ofTrueTypeFont dataText;

    bool debug = false;//Toggle with 'D'// Utilizado para saber cuando se requiere enseñar la información de "debugging"
    bool animation = false;
    bool startAnimation = false;
    int animationCounter = 0;
};
