//
//  ofPipe.h
//  PMOS
//
//  Created by Matti Niinimäki on 10/9/14.
//
//

#ifndef _OF_BUTTON
#define _OF_BUTTON

#include "ofMain.h"

class ofButton {
    
public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    float myTail=0.0;
    // variables
    float x=0.;        // position
    float y=0.;
    float rot=0.;
    bool onOff=false;
    int ID;
    bool haveBeenCounted = true;
    int APP;
    int table;// number of the pipe
    ofColor color;
    int points = 0;
    string letter;
    bool haveBeenOn;
    float answer = 0;
    int intAnswer = 0;
    int scenePoints = 0;
    float power = 10;
    string name;
    float timePercent = 0;
    //drug variables
    float timeSinceLastVote=0;
    float decay;
    float rotation = 0.0;
    float prot = 0;
    float radius = 15;
    // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    ofButton(int _table, int _ID, ofColor _color, string _name);
    bool spermStageOne = true;
    int previousAnswer;
    float previousRot;
    string xy = "";
    int xyint = 0;
    float blue=50;
    float green=50;
    float prevRot;
    void setMyAnswer();
    float spermRotFreeze = 0.0;
    bool spermRace = true;
    bool spermRace2 = true;
    int minRotation = 0;
    int what = 1;
    bool swiths = false;
    float tailWiggle = 0.0;
    int pattern;
    vector<int>point;
    
    void setAnswer(int choises){
        if(onOff)answer = int(floorf(ofMap(rot,0,2*PI,1,choises+1)));
        else answer = 0;
    }
    
    void updateMinMax(float x,float y);
    float minx = 1;
    float maxx = 0;
    float miny = 1;
    float maxy = 0;
private: // place private functions or variables declarations here
    
}; // dont't forget the semicolon!!

#endif /* defined(_OF_PIPE) */
