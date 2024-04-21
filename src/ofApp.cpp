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
    Fractals.push_back(new Fern("Barnsley Fern", 10));
    Fractals.push_back(new SnowFlake("Koch SnowFlake", 3));

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
        Fractals[3]->draw();
        Fractals[3]->update();
        text.drawString(Fractals[3]->getName(),25,60);

    }    break;
    case '5': {
        // Koch SnowFlake // Este se dibuja en el file de SnowFlake.cpp
        Fractals[4]->draw();
        Fractals[4]->update();
        text.drawString(Fractals[4]->getName(),25,60);

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
       dataText.drawString("4.Barnsley Level: " + to_string(Fractals[3]->getLevel()),25,420); 
       dataText.drawString("5.SnowFlake Level: " + to_string(Fractals[4]->getLevel()),25,480); 
       dataText.drawString("6.3D Fractal Level: " + to_string(Triangulitos.getDepth()),25,540); 
    	
        // Información de como subir los niveles
        dataText.drawString("Press Right Arrow to Level up the Recursion",950,60);
        dataText.drawString("Press Left Arrow to Level up the Recursion",957,120);
       
    }
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
        if(mode == '4' && Fractals[3]->getLevel()<50){
            Fractals[3]->setLevel(Fractals[3]->getLevel()+5);
        }
        if(mode == '5' && Fractals[4]->getLevel()<6){
            Fractals[4]->setLevel(Fractals[4]->getLevel()+1);
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
        if(mode == '4' && Fractals[3]->getLevel()>5){
            Fractals[3]->setLevel(Fractals[3]->getLevel()-5);
        }
        if(mode == '5' && Fractals[4]->getLevel()>1){
            Fractals[4]->setLevel(Fractals[4]->getLevel()-1);
        }
        if(mode == '6' && Triangulitos.getDepth()>0){
            Triangulitos.setdepth(Triangulitos.getDepth()-1);
        }   
    }
    if(tolower(key) == 'd'){
        debug = !debug;
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