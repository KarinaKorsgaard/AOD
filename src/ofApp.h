#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 5000
//#define HOST "localhost"
#define HOST "192.168.0.14"
//#define HOST "192.168.0.116"
//#include <fstream>

#define TABS 12
#include "ofButton.h"
#include "ofTable.h"
#include "ofxFontStash.h"


#include "ofxXmlSettings.h"

class ofApp : public ofBaseApp{

	public:
    
   // 280*legendScale
		void setup();
		void update();
		void draw();
        void drawAllrects();
		
        void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        vector<int>specialSit;
        int BUTTONS = TABS*6;
        int type = 0;
        float finalAnswer=0;
        bool writeResults;
    
       // bool showText = true;
        bool inGrid=false;
    
        void sceneQuiz();
    
        void sceneMajority();
   
        void sceneFullAgree();
    int calculationFix = 0;
    void sceneCalculate();
    int theSum = 173;
    void sceneTableConcencus();
    void sceneDrugs();
    
    void exit();
    
    void theTimerFunction(int thres, float x, float y, int timerSize);
    ofImage egg;
    int currentSum = 0;
    int theTimer;
    string theName;

    ofxXmlSettings xml;
    
    vector<ofImage >leggins;
        string message;
    vector<ofImage>legend;
    vector<ofImage>legendAct2;
   
       // ofxOscSender sender;
        ofxOscReceiver receiver;
        ofTrueTypeFont fQuix;
    bool startOver = false;
        //-- for OSC naming
        vector<string> tablenames;
        vector<string> objnames;
        vector<string> retardnames;
        void nameStuff();
    void sceneTurnBack();
        //-- to get list of buttons present
        vector<ofButton>onButtons;
        void tableList(); //lists of objects on tables
    void sceneLogicGame();
        vector<ofButton> buttons;
        ofColor** colors;
        ofTable** tables;
    int timer =0;
    int secondTimer;
    bool showAnswer = false;
        int scene = 0;
        bool stageCounter = false;
        int stageC;
        vector<ofImage>images;
    
    void crossout();
    
    vector<ofColor>quizColors;
    string theAnswer;
    bool stageOne = true;
    int drawItHere = 280;
    string boyName = "NAME";
    
    
        string OSCstring;
        float OSCfloat;
        int OSCint;
        float OSCintx;
        float OSCinty;
    vector<ofImage>gridLegend;
    vector<ofImage>quizImage;
    vector<ofImage>puzzlePngs;
    void drawGridLegend();
    vector<int>spermTables;
        int wth = ofGetWidth()-100;
        int hth = ofGetHeight()-100;
    void scenePattern();
        float yes=0;
    float nos=0;
    
    int lorteTimer;
    int who;
    //ALIGN!!!
    int theTime = 0;
    int TRANSX=950+70;
    int TRANSY=150;
    
    int legendPosX=TRANSX;
    
    int legendPosY=7*70+TRANSY;
    int barHeight = TRANSY+6*70+35;
    
    float legendScale = 0.9;
    int explanationH = 3*70+TRANSY;
    ofImage background;
    //also explanation and quizanswers
    int leftAligner = 90;
    
    int questionAlignerX =90;
    int questionAlignerY =5*70+TRANSY+20+70;
   
    void flipCoin();
    bool showtext = true;
    vector<ofImage>flip;
    bool startScene = false;
    bool lockResults = false;
    bool testMode = false;
    
    float timerX = 70;
    float timerY = TRANSY+120;
    float timerFontSize = 200;
    
    void spermRace();
    bool spermStageTwo = true;
    
    vector<int>to;
    vector<int>tre;
    vector<int>fire;
    vector<int>fem;
    vector<int>seks;
    
    vector<int>syv;
    vector<int>otte;
    vector<int>ni;
    vector<int>ti;
    vector<int>elve;
    vector<int>tolv;
    
    int fontSize;
    ofxFontStash font;
    ofImage drug;
    int stageTwoTimer = 800;
    
    
    int xadjust = 0;
    int yafjust = 0;
    
    bool secondAct = false;
};
