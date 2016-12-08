//
//  ofPipe.h
//  PMOS
//
//  Created by Matti Niinimäki on 10/9/14.
//
//

#ifndef _OF_TABLE
#define _OF_TABLE

#include "ofMain.h"
#include "ofButton.h"

class ofTable {
    
public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    
    int table;
    ofColor color;
    vector<ofButton>butts;
    // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    ofTable(int _table, ofColor _color);
    bool doWeAgree();
    bool doWeAgreeInt();
    int tableAnswer = 0;
    float distance();
    void collected();
    float colX;
    float colY;
    void lines();
    void lines2();
    vector<float>min;
    vector<float>max;
    int transX;
    int transY;
    void squaresAndOverlaps();
    float maxX = 0;
    float maxY = 0;
    float minX = 1;
    float minY = 1;
    void tPower();
    float tPow = 0;
    float areal=0;
    
    bool spermStageOne = true;
private: // place private functions or variables declarations here
    
}; // dont't forget the semicolon!!

#endif /* defined(_OF_PIPE) */
