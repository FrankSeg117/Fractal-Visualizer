#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",23);

    Fractals.push_back(new Circle("Circle Fractal", 2,5,1,50));
    Fractals.push_back(new Tree("Tree Fractal", 1,15,1,25));
    Fractals.push_back(new Triangle("Triangle Fractal", 2,10,1,25));
    Fractals.push_back(new Fern("Barnsley Fern", 10,50,5,25));
    Fractals.push_back(new SnowFlake("Koch SnowFlake", 2,6,1,25));
    Fractals.push_back(new Fractal3D("3D Fractal", 3, 9, 0, 25, &cam));
    Fractals.push_back(new HilbertCurve("Hilbert Curve",2,6,1,50));
}

//--------------------------------------------------------------
void ofApp::update() {
    if(this->Fractals[index-1]->getName() != "3D Fractal"){
            Fractals[index-1]->update(); //instead of using static_cast to increase angle, we use an update method for it
    }
    if(animation){
        if(startAnimation || (Fractals[index-1]->getLevel() == Fractals[index-1]->getMaxLevel() && animationCounter%150 == 0 )){
            this->Fractals[index-1]->setLevel(this->Fractals[index-1]->getMinLevel());
            if(this->Fractals[index-1]->getName() == "3D Fractal"){
                Fractals[index-1]->update();
            }
            startAnimation = false;
        }
        animationCounter++;
        if(animationCounter%this->Fractals[index-1]->getAnimationSpeed() == 0){
            this->Fractals[index-1]->increaseLevel();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    Fractals[index-1]->draw();
    text.drawString(Fractals[index-1]->getName(),25,60);

    if(debug){
        // Levels of different shapes
        for(int i = 1; i <=7; i++){
            dataText.drawString(to_string(i) +"." + Fractals[i-1]->getName() + ": " + to_string(Fractals[i-1]->getLevel()),25,240+60*(i-1)); 
        } 
    	
       // Información de como subir los niveles
       dataText.drawString("Press Right Arrow to Level up the Recursion",ofGetWindowWidth()*0.6875,ofGetWindowHeight()*0.0375);
       dataText.drawString("Press Left Arrow to Level down the Recursion",ofGetWindowWidth()*0.6875,ofGetWindowHeight()*0.075);
       
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '7'){
        mode = key;
        index = key - '0'; //Convertimos el character a int
    }
    //This will increase level
    if(key == OF_KEY_RIGHT){
        Fractals[index-1]->increaseLevel();            
    }
    //This will decrease level
    if(key == OF_KEY_LEFT){ 
        Fractals[index-1]->decreaseLevel(); 
    }
    if(tolower(key) == 'd'){
        debug = !debug;
    }
    if(key == ' '){
        animation = !animation;
        startAnimation = true; 
        animationCounter = 0;
    }
    else{
        animation = false;
        startAnimation = false; 
        animationCounter = 0;
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