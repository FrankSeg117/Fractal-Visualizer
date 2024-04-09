#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",15);
    Triangulitos.setcam(&cam); //Se le asigna al fractal3d la cam creada
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    text.drawString("(Insert Fractal Name Here)",25,60);

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        float r = 0.31 * ofGetHeight();
        angle += 0.01;
        drawMode1(ofGetWidth() / 2, ofGetHeight() / 2, r, dm1depth,0);
    } break;
    case '2': {
        // Tree
        float length = 0.31 * ofGetHeight();
        drawMode2(ofGetWidth() / 2, ofGetHeight() - 20, dm2depth, length, 1.5 * PI,0);
    } break;
    case '3': {
        // Sierpinski Triangle
        float size = 0.88 * ofGetHeight();
        drawMode3((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, dm3depth,0);
    } break;
    case '4': {
        // Barnsley Fern
        drawMode4(0, 0, dm4depth * 1000);
    }    break;
    case '5': {
        // Koch SnowFlake // Este se dibuja en el file de SnowFlake.cpp
        lanieve.draw();
        text.drawString(to_string(lanieve.getDepth()),25,120); //debug para ver si cambia depth

    }   break;
    case '6': {
        //3d Fractal //Estese dibuja en el file de Fractal3D.cpp
        Triangulitos.draw({{"n", Triangulitos.getDepth()}, {"scale", 100}});
        text.drawString(to_string(Triangulitos.getDepth()),25,120); //debug para ver si cambia depth
       
    }   break;
    }
}

//Drawing method for Circle
void ofApp::drawMode1(float x, float y, float r, int n, int colorindex) {
    if (n == 0) return;
    vector<ofColor> colores = {ofColor::blue, ofColor::red, ofColor::green, ofColor::yellow, ofColor::cyan};

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
    drawMode1(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1,colorindex+1);
    drawMode1(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1,colorindex+1);
    drawMode1(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1,colorindex+1);
    drawMode1(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1,colorindex+1);
    drawMode1(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1,colorindex+1);
    drawMode1(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1,colorindex+1);
}

//Drawing method for Tree
void ofApp::drawMode2(float x, float y, int n, float length, float rad, int colorindex) {
    if (n == 0) return;             //0                 //1                 2                   3               4               
    vector<ofColor> colores = {ofColor::brown, ofColor::rosyBrown, ofColor::burlyWood, ofColor::sandyBrown, ofColor::olive,
                               ofColor::green, ofColor::limeGreen, ofColor::forestGreen, ofColor::seaGreen, ofColor::springGreen,
                               ofColor::paleGreen,ofColor::darkGreen,ofColor::yellow,ofColor::purple,ofColor::greenYellow,
                               ofColor::lightGoldenRodYellow,ofColor::lime,ofColor::lemonChiffon};
    // if(colorindex>=colores.size()){
    //     colorindex=4;
    // }
    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofSetColor(colores[colorindex]); 
    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::white); //reset the color back to white

    drawMode2(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI,colorindex+1);
    drawMode2(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI,colorindex+1);
}

//Drawing method for Sierpinski Triangle
void ofApp::drawMode3(float x, float y, float size, int n, int colorindex) {
    if (n == 0) {
        return;
    }
    vector<ofColor> colores = {ofColor::brown, ofColor::rosyBrown, ofColor::burlyWood, ofColor::sandyBrown, ofColor::olive,
                               ofColor::green, ofColor::limeGreen, ofColor::forestGreen, ofColor::seaGreen, ofColor::springGreen,
                               ofColor::paleGreen,ofColor::darkGreen,ofColor::yellow,ofColor::purple,ofColor::greenYellow,
                               ofColor::lightGoldenRodYellow,ofColor::lime,ofColor::lemonChiffon};   

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofSetColor(colores[colorindex]); 
    ofDrawTriangle(a, b, c);
    ofSetColor(ofColor::white);

    drawMode3(x, y, size / 2, n - 1, colorindex+1);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1, colorindex+1);
}

//Drawing method for Barnsley Fern
void ofApp::drawMode4(float x, float y, float n) {
    if (n <= 0) return;
    int colorindex=0;

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

    ofSetColor(LoColores[colorindex]);
    // ofSetColor(ofColor::green);
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        drawMode4(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        drawMode4(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        drawMode4(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        drawMode4(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '6'){
        mode = key;
    }
    if(key == OF_KEY_RIGHT){
        if(mode == '1' && dm1depth<5){
            dm1depth++;
        }
        if(mode == '2' && dm2depth<15){
            dm2depth++;
        }
        if(mode == '3' && dm3depth<10){
            dm3depth++;
        }
        if(mode == '4' && dm4depth<50){
            dm4depth+=5;
        }
        if(mode == '5' && lanieve.getDepth()<6){
            lanieve.setDepth(lanieve.getDepth()+1);
        }
        if(mode == '6' && Triangulitos.getDepth()<9){
            Triangulitos.setdepth(Triangulitos.getDepth()+1);
        }                
    }
    //This will decrease 
    if(key == OF_KEY_LEFT){ 
        if(mode == '1' && dm1depth>1){
            dm1depth--;
        }
        if(mode == '2' && dm2depth>1){
            dm2depth--;
        }
        if(mode == '3' && dm3depth>1){
            dm3depth--;
        }
        if(mode == '4' && dm4depth>5){
            dm4depth-=5;
        }
        if(mode == '5' && lanieve.getDepth()>1){
            lanieve.setDepth(lanieve.getDepth()-1);
        }
        if(mode == '6' && Triangulitos.getDepth()>0){
            Triangulitos.setdepth(Triangulitos.getDepth()-1);
        }   
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}