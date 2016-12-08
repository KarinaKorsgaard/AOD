//
//  ofPipe.cpp
//  PMOS
//
//  Created by Me//
//

#include "ofButton.h"
#include "ofApp.h"
ofButton::ofButton(int _table, int _ID, ofColor _color, string _name)
{
    
    ID= _ID;
    table = _table;
    name = _name;
    //ofColor color = ofColor::fromHex(0xFF0090);
    //color.setHex( 0x00FF00 );
    color = _color;
    onOff=false;
    decay = 1;//ofRandom(2);
    haveBeenOn=false;
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    point.push_back(0);
    
    float whattt = ID;
    myTail=(whattt+5)/100;
   // myTail = 0.05;
    
    if((ID%2)==0){
        xy="y";
        xyint = 1;
    }
    else if((ID%2)==1){
        xy="x";
        xyint =2;
    }
    pattern = (ID+1) + ((table / 3)+1);
    
    if(ID == 0){
        letter = "A";
    }
    if(ID == 1){
        letter = "B";
    }
    if(ID == 2){
        letter = "C";
    }
    if(ID == 3){
        letter = "D";
    }
    if(ID == 4){
        letter = "E";
    }
    if(ID == 5){
        letter = "F";
    }
}

void ofButton::update(){
    if(prot-rot<2*PI-0.5&&prot!=0&&prot!=rot){
        
            if(prot>rot){
                rotation++;
            }
        
        
            if(prot<rot){
                rotation--;
            }
        
    }
  
    //rot=prot;
    if(!onOff){
        rotation=minRotation;
        prevRot=minRotation;
        answer = 0;
    }
    prot=rot;
    
   // if(onOff&&xyint==2){
     //   rotation+=ofRandom(1);
   // }
    
    if(tailWiggle>=1&&swiths){
        what = -1;
        swiths = false;
    }
    if(tailWiggle<=0&&!swiths){
        what = 1;
        swiths = true;
    }
    tailWiggle+=(myTail*what);

    
}

void ofButton::draw(){
    
}

void ofButton::updateMinMax(float _x, float _y){
    if(x < minx)minx = x;
    if(x > maxx)maxx = x;
    if(y < miny)miny = y;
    if(y > maxy)maxy = y;
}


void ofButton::setMyAnswer(){
    
    if(prot-rot<2*PI-0.5&&prot!=0&&prot!=rot){
        
        if(prot>rot){
            rotation++;
            //answer = 1;
        }
        
        
        if(prot<rot){
            rotation--;
           // answer = 2;
        }
        
    }
    
    if(rotation>0){
        answer = 1;
    }
    if(rotation<0){
        answer = 2;
    }
    
    //rot=prot;
    if(!onOff){
        rotation=0;
       // prevRot=0;
        answer = 0;
    }
    prot=rot;
}