

#include "ofTable.h"
#include "ofApp.h"
ofTable::ofTable(int _table, ofColor _color)
{
    
    
    table = _table;
    
    color = _color;
   
    min.push_back(1);
    min.push_back(1);
    min.push_back(1);
    min.push_back(1);
    min.push_back(1);
    min.push_back(1);
    min.push_back(1);
    min.push_back(1);

    
    max.push_back(30);
    max.push_back(30);
    max.push_back(30);
    max.push_back(30);
    max.push_back(30);
    max.push_back(30);
    max.push_back(30);
    max.push_back(30);
    max.push_back(30);
    max.push_back(30);
    
    
    
    transX =table/3*(ofGetWidth()-100)/4;
    transY =table%3*(ofGetHeight()-100)/3;
}

void ofTable::update(){
    
}


void ofTable::draw(){
    
}
float ofTable::distance(){
    float result = 0;
    if(butts.size()>0){
    for(int i = 0; i<butts.size(); i++){
        for(int u = 0; u<butts.size(); u++){
            result = result + ofDist(butts[i].x, butts[i].y, butts[u].x, butts[u].y);
        }
    }
    if(butts.size()<=min.size()){
        result = ofMap(result, min[butts.size()], max[butts.size()], 1, 0);
        return result;
    }
    }
    else{
        return 0;
    }
    
}

void ofTable::lines(){
    
    ofPushMatrix();
    ofTranslate(transX,transY);
    for(int i = 0; i<butts.size(); i++){
        ofCircle(butts[i].x*ofGetWidth()/4, butts[i].y*ofGetHeight()/3, distance()*10);
        
            ofLine(butts[i].x*ofGetWidth()/4, butts[i].y*ofGetHeight()/3, butts[(i+1)%butts.size()].x*ofGetWidth()/4, butts[(i+1)%butts.size()].y*ofGetHeight()/3);
        
    }
    ofPopMatrix();
}



void ofTable::collected(){
    for(int i = 0; i<butts.size();i++){
        colX += butts[i].x;
        colY += butts[i].y;
    }
    colX = colX/butts.size();
    colY = colY/butts.size();
}

void ofTable::squaresAndOverlaps(){
    maxX = 0;
    maxY = 0;
    minX = 1;
    minY = 1;
    areal = 0;
    if(butts.size()>0){
        for(int i = 0; i<butts.size()-1;i++){
            maxX=MAX(butts[i].x, butts[(i+1)%butts.size()].x);
            maxY=MAX(butts[i].y, butts[(i+1)%butts.size()].y);
            minX=MIN(butts[i].x, butts[(i+1)%butts.size()].x);
            minY=MIN(butts[i].y, butts[(i+1)%butts.size()].y);
        }
        if(minX<1&&minY<1&&maxX>0&&maxY>0){
            ofRect(minX*ofGetWidth(), minY*ofGetHeight(), (maxX-minX)*ofGetWidth(), (maxY-minY)*ofGetHeight());
            areal = (maxX-minX)*(maxY-minY);
            ofDrawBitmapString(ofToString(table), minX*ofGetWidth(),minY*ofGetHeight());
        }
    }
}

void ofTable::tPower(){
    float xes;
    float yes;
    tPow = 0;
    tableAnswer = 0;
    int v1 = 0;
    int v2 = 0;
    int v3 = 0;
    int v4 = 0;
    if(butts.size()>0){
        for(int i = 0; i<butts.size();i++){
            
            //xes+=butts[i].x;
            //yes+=butts[i].y;
            if(butts[i].x<0.5&&butts[i].y<0.5){butts[i].answer=1;v1++;}
            if(butts[i].x>0.5&&butts[i].y<0.5){butts[i].answer=2;v2++;}
            if(butts[i].x<0.5&&butts[i].y>0.5){butts[i].answer=3;v3++;}
            if(butts[i].x>0.5&&butts[i].y>0.5){butts[i].answer=4;v4++;}
            //xes+=butts[i].answer;
            //yes+=butts[i].y;

        }
        
        //-----tableAnswer;
        
        if(v1>v2&&v1>v3&&v1>v4){ //v1 major
            tableAnswer=1;
        }
        if(v2>v1&&v2>v3&&v2>v4){ //v2 major
            tableAnswer=2;
        }
        if(v3>v1&&v3>v2&&v3>v4){ //v3 major
            tableAnswer=3;
        }
        if(v4>v1&&v4>v2&&v4>v3){ //v4 major
            tableAnswer=4;
        }
    
    
        //-----table power (agreeness)
        for(int i = 0; i<butts.size();i++){
            for(int u = 0; u<butts.size();u++){
                if(u!=0){
                    if(butts[i].answer==butts[u].answer){
                        tPow++;
                    }
                }
            }
        }
        //cout<<tPow<<endl;
        tPow=ofMap(tPow, 0, butts.size()*2, 0, 1);
        //cout<<tableAnswer<<endl;
    }
}

bool ofTable::doWeAgree(){
    bool result = true;
    
    for(int i = 0; i<butts.size();i++){
        for(int u = 0; u<butts.size();u++){
            if(butts[i].answer!=butts[u].answer){
                result = false;
                
            }
        
        }
        
    }
    return result;

}

bool ofTable::doWeAgreeInt(){
    bool result = true;
    
    for(int i = 0; i<butts.size();i++){
        for(int u = 0; u<butts.size();u++){
            if(butts[i].answer!=butts[u].answer){
                result = false;
                
            }
            
        }
        
    }
    return result;
    
}

