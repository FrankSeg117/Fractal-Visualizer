#pragma once

#include "ofMain.h"

using namespace glm;

class Fractal3D {
    private:
        ofMesh mesh;
        ofEasyCam* cam;
        bool currentMeshHasDetail = false;
        bool extrudeAllFaces = false;
        int depth;
    
    public:
        //Constructor predet
        Fractal3D() : cam(nullptr){this->depth=3;}

        //setter de el OFezcam para cuando se inicializa sin cam
        void setcam(ofEasyCam* Newcam){this->cam=Newcam;}

        Fractal3D(ofEasyCam* cam);
        ~Fractal3D();

        vec3 centerOf(vector<vec3>& points);

        void setdepth(int depth3D){this->depth=depth3D;reset();}
        int getDepth(){return this->depth;}

        void draw(map<string, float>);
        void generateTetrahedron(vector<vec3>& base, vec3 peak, int n);
        void reset();
        map<string, float> getDefaultConfig();
        void toggleDetail();
};