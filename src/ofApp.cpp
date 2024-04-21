#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",23);
    Triangulitos.setcam(&cam); //Se le asigna al fractal3d la cam creada

    Fractals.push_back(new Circle("Circle Fractal", 2));
    Fractals.push_back(new Tree("Tree Fractal", 1));
    Fractals.push_back(new Triangle("Triangle Fractal", 2));

}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        Fractals[0]->draw();
        Fractals[0]->update(); //instead of using static_cast to increase angle, we use an update method for it
        text.drawString(Fractals[0]->getName(),25,60);

    } break;
    case '2': {
        // Tree //Default length is 0.31        
        Fractals[1]->draw();
        Fractals[1]->update();
        text.drawString(Fractals[1]->getName(),25,60);

    } break;
    case '3': {
        // Sierpinski Triangle
        Fractals[2]->draw();
        Fractals[2]->update();
        text.drawString(Fractals[2]->getName(),25,60);

    } break;
    case '4': {
        // Barnsley Fern
        drawMode4(0, 0, dm4depth * 1000);
        if(debug){
            text.drawString("Barnsley Fern Fractal",25,60);
        }
    }    break;
    case '5': {
        // Koch SnowFlake // Este se dibuja en el file de SnowFlake.cpp
        lanieve.draw();
        if(debug){
            text.drawString("Koch SnowFlake Fractal",25,60);
        }

    }   break;
    case '6': {
        //3d Fractal //Estese dibuja en el file de Fractal3D.cpp
        Triangulitos.draw({{"n", Triangulitos.getDepth()}, {"scale", 100}});
        if(debug){
            text.drawString("3D Fractal",25,60);
        }
       
    }   break;
    }
    if(debug){
        // Levels of different shapes
       dataText.drawString("1.Circle Level: " + to_string(Fractals[0]->getLevel()),25,240); 
       dataText.drawString("2.Tree Level: " + to_string(Fractals[1]->getLevel()),25,300); 
       dataText.drawString("3.Triangle Level: " + to_string(Fractals[2]->getLevel()),25,360); 
       dataText.drawString("4.Barnsley Level: " + to_string(dm4depth),25,420); 
       dataText.drawString("5.SnowFlake Level: " + to_string(lanieve.getDepth()),25,480); 
       dataText.drawString("6.3D Fractal Level: " + to_string(Triangulitos.getDepth()),25,540); 
    	
        // Información de como subir los niveles
        dataText.drawString("Press Right Arrow to Level up the Recursion",950,60);
        dataText.drawString("Press Left Arrow to Level up the Recursion",957,120);
       
    }
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
        if(mode == '1' && Fractals[0]->getLevel()<5){
            Fractals[0]->setLevel(Fractals[0]->getLevel()+1);
        }
        if(mode == '2' && Fractals[1]->getLevel()<15){
            Fractals[1]->setLevel(Fractals[1]->getLevel()+1);
        }
        if(mode == '3' && Fractals[2]->getLevel()<10){
            Fractals[2]->setLevel(Fractals[2]->getLevel()+1);
        }
        if(mode == '4' && dm4depth<50){
            dm4depth+=5;
        }
        if(mode == '5' && lanieve.getDepth()<6){
            lanieve.setLevel(lanieve.getDepth()+1);
        }
        if(mode == '6' && Triangulitos.getDepth()<9){
            Triangulitos.setdepth(Triangulitos.getDepth()+1);
        }                
    }
    //This will decrease 
    if(key == OF_KEY_LEFT){ 
        if(mode == '1' && Fractals[0]->getLevel()>1){
            Fractals[0]->setLevel(Fractals[0]->getLevel()-1);
        }
        if(mode == '2' && Fractals[1]->getLevel()>1){
            Fractals[1]->setLevel(Fractals[1]->getLevel()-1);
        }
        if(mode == '3' && Fractals[2]->getLevel()>1){
            Fractals[2]->setLevel(Fractals[2]->getLevel()-1);
        }
        if(mode == '4' && dm4depth>5){
            dm4depth-=5;
        }
        if(mode == '5' && lanieve.getDepth()>1){
            lanieve.setLevel(lanieve.getDepth()-1);
        }
        if(mode == '6' && Triangulitos.getDepth()>0){
            Triangulitos.setdepth(Triangulitos.getDepth()-1);
        }   
    }
    if(tolower(key) == 'd'){
        debug = !debug;
        // if(!debug){
        //     debug = true;
        // }
        // else{
        //     debug = false;
        // }
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