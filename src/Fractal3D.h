#pragma once

#include "ofMain.h"
#include "AbstractFractal.h"

using namespace glm;

class Fractal3D : public AbstractFractal{
    protected:
        ofMesh mesh;
        ofEasyCam* cam;
        bool currentMeshHasDetail = false;
        bool extrudeAllFaces = false;
    public:
        //Constructor 
        Fractal3D(string name, int level, ofEasyCam* cam) : AbstractFractal(name, level), cam(cam) {}
   
        ~Fractal3D();

        vec3 centerOf(vector<vec3>& points);

        void update();
        void draw();
        void draw(map<string, float>);

        virtual void increaseLevel(){
            if(this->getLevel()<9){
                this->setLevel(this->getLevel()+1);
                reset();
            }
        }
        virtual void decreaseLevel(){
            if(this->getLevel()>0){
                this->setLevel(this->getLevel()-1);
                reset();
            }
        }
        void generateTetrahedron(vector<vec3>& base, vec3 peak, int n);
        void reset();
        map<string, float> getDefaultConfig();
        void toggleDetail();
};