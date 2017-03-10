#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofxXmlSettings config;
    config.load("config.xml");
    config.pushTag("config");
    TABS = config.getValue("Num_tables", 0);
    secondAct = config.getValue("act_number", 0)==1?false:true;
    cout << TABS<< endl;
    cout << secondAct << endl;
    
  //  ofSetDataPathRoot("../Resources/data/");
    
    ofSetWindowPosition(3760, -30);
   // sender.setup(HOST, SENDTO);
    receiver.setup(PORT);
    ofSetFrameRate(30);
    fontSize = 40;
   
   // thread.startThread(); /////////////
    
    ofTrueTypeFont::setGlobalDpi(72);
    
//    egg = *new ofImage;
   if(TABS==10) egg.load("egg-02.png");
   else egg.load("egg-01.png");
    
    fQuix = *new ofTrueTypeFont;
    fQuix.load("GT.ttf", 30,true,true,true);
    fQuix.setLetterSpacing(fQuix.getLetterSpacing()-0.1);
    fQuix.setLineHeight(30.0f);

    
    colors  = new ofColor*[TABS];
    tables = new ofTable*[TABS];
   
    
    to.push_back(0);to.push_back(0);
    to={0,0};
    tre={0,1,0};
    fire={0,1,0,0};
    fem={0,3,0,3,0};
    
//    tre.push_back(0);to.push_back(1);to.push_back(0);
//    fire.push_back(0);fire.push_back(1);fire.push_back(0);fire.push_back(0);
//    fem.push_back(0);fem.push_back(3);fem.push_back(0);fem.push_back(3);fem.push_back(0);
    //seks.push_back(1);seks.push_back(2);seks.push_back(1);seks.push_back(0);seks.push_back(1);seks.push_back(2);
    
    //syv.push_back(3);syv.push_back(0);syv.push_back(0);syv.push_back(3);syv.push_back(0);syv.push_back(2);syv.push_back(1);
    //otte.push_back(0);otte.push_back(0);otte.push_back(0);otte.push_back(3);otte.push_back(0);otte.push_back(2);otte.push_back(1);otte.push_back(0);
    //ni.push_back(2);ni.push_back(0);ni.push_back(1);ni.push_back(0);ni.push_back(0);ni.push_back(1);ni.push_back(2);ni.push_back(0);ni.push_back(1);
    seks={1,2,1,0,1,2};
    syv={3,0,0,3,0,2,1};
    otte={0,0,0,3,0,2,1,0};
    ni={2,0,1,0,0,1,2,0,1};
    ti={32,32,24,14,16,16,38,28,41,25}; //wtf? -- drawing number. which makes more sense anyway. ...
   // ti.push_back(0);ti.push_back(1);ti.push_back(1);ti.push_back(2);ti.push_back(0);ti.push_back(2);ti.push_back(2);ti.push_back(2);ti.push_back(1);ti.push_back(3);
    elve.push_back(1);elve.push_back(0);elve.push_back(1);elve.push_back(2);elve.push_back(0);elve.push_back(1);elve.push_back(3);elve.push_back(0);elve.push_back(1);elve.push_back(0);elve.push_back(0);
    tolv.push_back(1);tolv.push_back(0);tolv.push_back(0);tolv.push_back(2);tolv.push_back(0);tolv.push_back(1);tolv.push_back(3);tolv.push_back(3);tolv.push_back(1);tolv.push_back(0);tolv.push_back(0);tolv.push_back(1);

    
    for(int i = 0; i<TABS;i++){
        colors[i]=new ofColor;
    }
    
    nameStuff();
    for(int i = 0; i<TABS;i++){
        
        tables[i]=new ofTable(i,*colors[i]);
        for(int u = 0; u<6;u++){
            
            string theName =ofToString(i)+"/"+ofToString(u);
            buttons.push_back(ofButton(i,u,*colors[i],theName));
            buttons.back().pattern = (i*6+u)%7;
            
          //  cout<<ofToString(i*6+u)+";"<<endl;
        }
    }
    string path ="puzzle";
    ofDirectory puzzleDir;
    puzzleDir.allowExt("png");
    puzzleDir.listDir(path);
    
   for(int u =0; u<puzzleDir.size();u++){

       ofImage img;
       puzzlePngs.push_back(img);
       puzzlePngs.back().load(puzzleDir.getPath(u));
       
    }
    

    drug.load("drugs/scale-01.png");
    
    for(int u =0; u<6;u++){
        
        ofImage img;
        legend.push_back(img);
        legend.back().load("QuizLegend/act1/0-0"+ofToString(u+1)+".png");
        
        
    }
    
    
    for(int u =0; u<6;u++){
        
        ofImage img;
        legendAct2.push_back(img);
        legendAct2.back().load("QuizLegend/act2/0-0"+ofToString(u+1)+".png");
    }
    
    
    path ="coin";
    ofDirectory coinDir;
    coinDir.allowExt("png");
    coinDir.listDir(path);
    
    for(int i = 0; i<coinDir.size();i++){
        ofImage img;
        flip.push_back(img);
        flip.back().load(coinDir.getPath(i));
    }
    
    for(int u =0; u<9;u++){
        string s = "legends/leg-0"+ofToString(u+1)+".png";
        ofImage img = *new ofImage;
        img.load(s);
        leggins.push_back(img);
    }
    for(int u =0; u<+12+6;u++){
        string s;
        if(u<9){
        s = "gridLeg/grid-0"+ofToString(u+1)+".png";
        }
        else if(u>8){
        s = "gridLeg/grid-"+ofToString(u+1)+".png";
        }
        ofImage img;
        gridLegend.push_back(img);
        gridLegend.back().load(s);
        
    }
    
    //QUIZCOLROS
    ofColor c = *new ofColor;
    
    c.setHex(0x76cab7);//c p√∏lle
    quizColors.push_back(c);
    c.setHex(0x3553a4);//d blue
    quizColors.push_back(c);
    c.setHex(0xef5122);//yelow
    quizColors.push_back(c);
    c.setHex(0xff9c40);//blue
    quizColors.push_back(c);
    
    background = *new ofImage;
    background.load("background.jpg");
    
    ofSetFrameRate(30);
    //REMEMBER
    font.setup("GT.ttf", 1.0, 1024, true, 8, 1.0);
    

    //legendPosX=950+ (12*70);

    
    vector<string>minmaxConfig;
    xml.loadFile("buttonConfig.xml");
    xml.pushTag("document");
    minmaxConfig = ofSplitString(xml.getValue("buttons",""), ";");
    xml.popTag();
    
//    for(int i = 0 ; i <BUTTONS ;i++){
//       // cout<<minmaxConfig[i*4+3];
//        if(i<BUTTONS && (i*4+3)<minmaxConfig.size()){
//            buttons[i].minx = ofToFloat(minmaxConfig[i*4]);
//            buttons[i].maxx = ofToFloat(minmaxConfig[i*4+1]);
//            buttons[i].miny = ofToFloat(minmaxConfig[i*4+2]);
//            buttons[i].maxy = ofToFloat(minmaxConfig[i*4+3]);
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::update(){

    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
       
        
    
        if (m.getAddress()=="/scene"){ //when changing scenes buttons scene point=0, answers = 0 and stageC = 0
            scene = m.getArgAsInt32(0);
            lockResults=false;
            for(int i = 0; i < BUTTONS; i++){
                buttons[i].scenePoints=0;
                buttons[i].onOff = false;
                buttons[i].answer=0;
                buttons[i].spermRace=true;
                buttons[i].spermRace2=true;
                buttons[i].rotation=0;
                buttons[i].minRotation = 0;
            }
            spermTables.clear();
            stageC=0;
            timer = 0;
            secondTimer = 0;
            stageOne = true;
            stageCounter = false;
            // writeResults = false;
            showAnswer = false;
            theTimer = 0;
            spermStageTwo = true;
            startScene = false;
            theAnswer ="";
         //   showText = true;
        }
        if (m.getAddress()=="/startScene"){
        
            if(m.getArgAsInt32(0)==0){
                startScene=false;
            }
            else if(m.getArgAsInt32(0)==1){
                startScene=true;
            }
        }
        if (m.getAddress()=="/ise"){
            
                theAnswer="Iseteadlik";
                lockResults=true;
  
        }
        
        
       if(!lockResults&&startScene){
        
           for(int i = 0; i<tablenames.size(); i++){
               for(int u = 0; u<retardnames.size(); u++){
                   
                   if (m.getAddress()==tablenames[i]+"/switch"+objnames[u]){
                       if(m.getArgAsInt32(0)==1){
                           buttons[i*6+u].haveBeenOn=true;
                           buttons[i*6+u].onOff=true;
                           
                       }else if(m.getArgAsInt32(0)==0){
                           buttons[i*6+u].onOff=false;
                           
                       }
                       
                   }
                   
                   else if (m.getAddress()==tablenames[i]+retardnames[u]){
                      //2 if(m.getArgTypeName(0)=="float")
                           buttons[i*6+u].x=(127-m.getArgAsFloat(0))/127;
                      // if(m.getArgType(1)==1)
                           buttons[i*6+u].y=(127-m.getArgAsFloat(1))/127;
                      // if(m.getArgType(2)==1)
                           buttons[i*6+u].rot=2*PI-m.getArgAsFloat(2);
                       
                       //cout<<msg->getArgAsFloat(0)<<endl;
                       //cout<<msg->getArgAsInt32(0)<<endl;
                   }
                   
                   
               }
           }
       }
    }

    
    onButtons.clear();
    int thatSum = 0;
    for(int i = 0; i<BUTTONS ; i++){
        if(buttons[i].haveBeenOn){
            thatSum++;
        }
        if(buttons[i].onOff){
            onButtons.push_back(buttons[i]);
        }
        buttons[i].update();
    }
    
    theSum = (2*(thatSum*9)/3)+6;
    
    if(!startScene){
        stageC=0;
        timer = 0;
        secondTimer = 0;
        stageOne = true;
        stageCounter = false;
        // writeResults = false;
        showAnswer = false;
        theTimer = 0;
        spermStageTwo = true;
        
        
    }
    //------------------------------------------------------------------------
    
    
    if(ofGetFrameNum()%10==0&&!lockResults&&testMode){
        int randomint =  ofRandom(72);
        buttons[randomint].rot=ofRandom(2*PI);
        buttons[randomint].rot=ofRandom(2*PI);
        buttons[randomint].rot=ofRandom(2*PI);
        
        for(int i = 0; i<BUTTONS;i++){
          buttons[i].rotation+=ofRandom(1);
        }
    }

   /* if(showText){
        theTime = 0;
        stageC=0;
        timer = 0;
        secondTimer = 0;
    }*/
    
    
}

void ofApp::exit(){
//    xml.clear();
//    string minmax;
//    xml.addTag("document");
//    xml.pushTag("document");
//    
//    for(int i = 0 ; i< BUTTONS; i++){
//        minmax.append(ofToString(buttons[i].minx) + ";" + ofToString(buttons[i].maxx) + ";");
//        minmax.append(ofToString(buttons[i].miny) + ";" + ofToString(buttons[i].maxy) + ";");
//    }
//    xml.addTag("buttons");
//    xml.setValue("buttons",minmax);
//    xml.popTag();
//    xml.saveFile("buttonConfig.xml");
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    if(!testMode){
    ofBackground(0,197,0);
    }
    else if(testMode){
        ofSetColor(255);
        background.draw(0,0,ofGetWidth(),ofGetHeight());
    }
    //background.draw(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(255);
    //background.draw(0,0,ofGetWidth(),ofGetHeight());
    
    
    
   // ofSetColor(0);
 //   font.draw(ofToString(ofGetFrameRate()), 100, 1800,1000);
    finalAnswer = 0;
   // scene = 0;
   // theAnswer= "";
    
    if(scene==0){
        
        stageOne = false;
       
            ofSetColor(255);
        ofPushMatrix();
        
        ofTranslate(250, 0);
            spermRace();
        ofPopMatrix();
        
            ofSetColor(255);
            string s = (string)
        "Et tekiks uus elu, peab Pauli"
        +"\n"+
        "seemnerakk jõudma Tiiu"
        +"\n"+
        "munarakuni. Keera oma nuppu" +"\n"+
        "päripäeva, et Sinu juhitud"
        +"\n"+
        "seemnerakk sihtkoha poole teele" +"\n"+
        "asuks. Kiireim seemnerakk"
        +"\n"+
        "võidab! "
        +"\n"+"\n"+
        "Igast sektorist (lauast) jätkab "
        +"\n"+
        "võistlust ülima eesmärgi nimel "
        +"\n"+
        "vaid kiireim sektorist väljuja."
        +"\n"+"\n"+
        
        
        "Kui seemneraku ja tema piloodi "
        +"\n"+
        "vahel katkeb side (näiteks kui "
        +"\n"+
        "nupp laualt ära võtta või sellega "
         +"\n"+
        "liiga hullult rabistada), algab "
        +"\n"+
        "teekond algusest.";
        ofFill();
            font.draw("Looduslik valik:", fontSize+20, leftAligner, explanationH-170);
            font.drawMultiLine(s, fontSize, leftAligner, explanationH+fontSize+20-170);
            
        }
    //}

    if(scene==1){
        stageOne = false;
        ofSetColor(255);
        startScene = true;
        sceneFullAgree(); //draws lines, when all agree, it writes done.
        ofNoFill();
        drawAllrects();
        drawGridLegend();
        //LEGENDSZZZ
        leggins[scene].draw(legendPosX,legendPosY, leggins[scene].getWidth()*legendScale, leggins[scene].getHeight()*legendScale);
        
        string s = (string)
        "Et Paul ja Tiiu oma lapsele nime"
        +"\n"+
        "saaksid panna, tuleb neil langetada "
        +"\n"+
        "konsensuslik otsus. Et Paul ja Tiiu "
        +"\n"+
        "konsensusliku otsuseni jõuaksid, "
        +"\n"+
        "peate ka teie saalis jõudma meie "
        +"\n"+
        "tulevase peategelase nime asjus "
        +"\n"+
        "täielikule üksmeelele.";
        
        ofFill();
        font.draw("Konsensus:", fontSize+20, leftAligner, explanationH);
        font.drawMultiLine(s, fontSize, leftAligner, explanationH+fontSize+20);
        
    }
   
    
    if(scene==2){
        stageOne = false;
        ofSetColor(255);
        if(secondAct){
            theTimerFunction(60*30*2, timerX, timerY, timerFontSize); //tiiimers
        }
        else if(!secondAct){
            theTimerFunction(60*30*5, timerX, timerY, timerFontSize); //tiiimers
        }
        sceneLogicGame();
       
        string s = (string)
        "Kas " +theName +"it peaks rohkem kasvatama,"
        +"\n"+
        "keelama ja käskima või laskma tal rohkem"
        +"\n"+
        "iseseisev olla? Iseseisvuse saavutamiseks"
        +"\n"+
        "tuleb "+theName+"il endale ise kombinesoon"
        +"\n"+
        "õigesti selga saada."
        +"\n"+
        "\n"+
        "Et " +theName+" endale kombinesooni"
        +"\n"+
        "õigesti selga saaks, tuleb ette antud"
        +"\n"+
        "ajaraamis lahendada mosaiikmõistatus."
        +"\n"+
        "Igas lauas töötab vaid nupp A. Oma"
        +"\n"+
        "mosaiigitüki tunned ära lauanumbri abil."
        +"\n"+
        "\n"+
        theName+"i õnnestumisest sõltub, kas temast"
        +"\n"+
        "saab allaheitlik või iseteadlik inimene.";
        
        ofFill();
        font.draw("Kollektiivne probleem:", fontSize+20, leftAligner, explanationH);
        font.drawMultiLine(s, fontSize, leftAligner, explanationH+fontSize+20);
        
        
        //font.drawMultiLine(s, fontSize, leftAligner, questionAlignerY+200);
        

    }
    //scene 1, nothing. 
    
    if(scene==3){
        
        ofFill();
            string s = (string)
        "Vasta viktoriiniküsimustele õigesti "
        +"\n"+
        "ning Sinu häälel on "+ theName +"i saatuse"
        +"\n"+
        "üle rohkem kaalu.";
        
        if(!startScene){
        
        ofFill();
        font.draw("Kaalutud hääled:", fontSize+20, leftAligner, explanationH);
        font.drawMultiLine(s, fontSize, leftAligner, explanationH+fontSize+20);
        }
        
        if(startScene){
            ofFill();
            sceneQuiz();
            ofNoFill();
            drawAllrects();
            drawGridLegend();
        }
        
        if(!stageOne){
            ofFill();
            s = (string)
            "Kas "+theName+" läheb õppima eliitkooli või"
            +"\n"+"jääb edasi tavakooli?";
            font.drawMultiLine(s, fontSize, questionAlignerX, questionAlignerY);
        }
        if(stageOne&&!startScene){
            ofFill();
            s = (string)
            "Sinu mänguruudu sees olev number näitab"
            +"\n"+
            "Sinu punktisummat õigesti vastatud küsimuste"
            +"\n"+
            "eest. Iga punkt annab Sulle otsustamisel"
            +"\n"+
            "ühe hääle.";
            font.drawMultiLine(s, fontSize, questionAlignerX, questionAlignerY-30);
        }
    }
    
    //scene 3 and 4 not there yet.
    if(scene==4){
        stageOne = false;
        if(secondAct){
            theTimerFunction(30*30, timerX, timerY, timerFontSize); //tiiimers
        }
        else if (!secondAct){
            theTimerFunction(90*30, timerX, timerY, timerFontSize); //tiiimers
        }
        sceneMajority(); //two choises. yellow/blue
        
        crossout();
        
        leggins[scene].draw(legendPosX,legendPosY+70, leggins[scene].getWidth()*legendScale, leggins[scene].getHeight()*legendScale);
        ofSetColor(255);
        //LEGENDSZZZ
        
        ofFill();
        string s = (string)
        "Jõustub enamuse tahe";
        font.draw("Enamus:", fontSize+20, leftAligner, explanationH);
        font.drawMultiLine(s, fontSize, leftAligner, explanationH+fontSize+20);
        ofNoFill();
        drawAllrects();
        drawGridLegend();
        
        ofFill();
        s = (string)"Kas "+theName+" kolib ema ja Niklasega"
        +"\n"+"Rootsi või jääb isaga Eestisse?";
        
        font.drawMultiLine(s, fontSize, questionAlignerX, questionAlignerY-100);

    }
    if(scene==5){
        stageOne = false;
        if(secondAct){
            theTimerFunction(30*30, timerX, timerY, timerFontSize); //tiiimers
        }
        else if(!secondAct){
            theTimerFunction(60*30, timerX, timerY, timerFontSize); //tiiimers
        }
        sceneDrugs();
        crossout();
        ofSetColor(255);
        //LEGENDSZZZ
        leggins[scene].draw(legendPosX,legendPosY+70, leggins[scene].getWidth()*legendScale, leggins[scene].getHeight()*legendScale);
                //Explanation:
        string s = (string)
        theName+" peab otsustama, kas"
        +"\n"+
        "keelatud viljad on tema jaoks."
        +"\n"+
        "Keera oma nuppu ning proovi"
        +"\n"+
       theName+"it mõjutada tabletti sööma"
        +"\n"+
        "või sellest hoopis keelduma."
        +"\n"+
       theName+"i otsus on enim sõltuv"
        +"\n"+
        "nupust, mida liigutatakse saalis"
        +"\n"+
        "viimasena. Viimase hetke impulss"
        +"\n"+
        "ehk viimasena liigutatud nupp"
        +"\n"+
        "kisub endaga kaasa ka kõik teised."
        +"\n"+
        "Kas "+ theName+" paneb tableti suhu?";
        
        ofFill();
        font.draw("Viimase hetke impulss:", fontSize+20, leftAligner, explanationH);
        font.drawMultiLine(s, fontSize, leftAligner, explanationH+fontSize+20);
        ofNoFill();
        drawAllrects();
        drawGridLegend();
       // s = (string)"Kas "+theName+" proovib narkootikume?";
       // font.drawMultiLine(s, fontSize, questionAlignerX, questionAlignerY);
    }
    if(scene==6){
        stageOne = false;
        if(secondAct){
            theTimerFunction(30*30, timerX, timerY, timerFontSize);//HEREREREREJKFD
        }
        if(!secondAct){
            theTimerFunction(90*30, timerX, timerY, timerFontSize);//HEREREREREJKFD
        }
        sceneTableConcencus();
        crossout();
        leggins[scene].draw(legendPosX,legendPosY+70, leggins[scene].getWidth()*legendScale, leggins[scene].getHeight()*legendScale);
        ofSetColor(255);
        //LEGENDSZZZ
        
        //Explanation:
        string s = (string)
        "tulemusele omavad mõju vaid nende"
        +"\n"+
        "laudkondade hääled, mis saavutavad oma"
        +"\n"+
        "otsuses täieliku üksmeele";
        
        ofFill();
        font.draw("Grupeeritud üksmeel:", fontSize+20, leftAligner, explanationH);
        font.drawMultiLine(s, fontSize, leftAligner, explanationH+fontSize+20);
        ofNoFill();
        drawAllrects();
        drawGridLegend();
        s = (string)"Kas "+theName+" läheb ülikooli?";
        ofFill();
        font.drawMultiLine(s, fontSize, questionAlignerX, questionAlignerY);
    }
    if(scene==7){
        stageOne = false;
        if(secondAct){
            theTimerFunction(90*30, timerX, timerY, timerFontSize);//tiiimers
        }
        else if (!secondAct){
            theTimerFunction(150*30, timerX, timerY, timerFontSize);//tiiimers
        }
        sceneCalculate(); //two choises. yellow/blue
        //leggins[scene].draw(legendPosX,legendPosY, leggins[scene].width*legendScale, leggins[scene].height*legendScale);
        ofSetColor(255);
        //LEGENDSZZZ
        
        string s = (string)
        "Et " +theName+" oma korteri maha"
        +"\n"+
        "müüks, tuleb pisut arvutada."
        +"\n"+
        "Oma nuppu pöörates saad"
        +"\n"+
        "määrata oma liidetava suurust."
        +"\n"+
        "Korterimüük õnnestub juhul, kui"
        +"\n"+
        "kõikide liidetavate summaks"
        +"\n"+ 
        "tuleb " +ofToString(theSum);
        
        ofFill();
        font.draw("Kalkulatsioon:", fontSize+20, leftAligner, explanationH);
        font.drawMultiLine(s, fontSize, leftAligner, explanationH+fontSize+20);
        s = "="+ofToString(currentSum);
        font.draw(s, 70, TRANSX+20, barHeight+55);
        ofNoFill();
        drawAllrects();
        drawGridLegend();
    }

    if(scene==8){
        flipCoin();
        
        string s = (string)
        "Oskus mänguväljadelt enda mängunupule"
         +"\n"+
        "vastavaid tähiseid leida kergendab oluliselt"
         +"\n"+
        "Sinu osalemist lavastuse kulgemises."
         +"\n"+
        "Head harjutamist!"
         +"\n"+ "\n"+
        "Leia mänguväljalt enda lauanumbri (1-12)"
         +"\n"+
        "ja nuputähise (A-F) ristumiskohast enda"
         +"\n"+
        "nupule vastav ruuduke. Nuppu pöörates saad"
         +"\n"+
        "enda ruudukeses olevat mustrit muuta. Ära"
         +"\n"+
        "muretse, midagi erilist veel ei juhtu -"
         +"\n"+
        "tegu on pelga käeharjutuse ja võimalusega"
        +"\n"+
        "kõik koos mustrit joonistada.";
        
        ofFill();
        font.drawMultiLine(s, fontSize, leftAligner, explanationH);
        
        ofNoFill();
        drawAllrects();
        drawGridLegend();
    }
    
    if(scene==9){
        stageOne = false;
        sceneTurnBack();
       // leggins[8].draw(legendPosX,legendPosY-35, leggins[8].width*legendScale, leggins[8].height*legendScale);
        ofFill();
        theTimerFunction(30*60*20, timerX, timerY, timerFontSize); //tiiimers
        
        string s = (string)
        "Et kõik võiks minna teisiti, tuleb"
        +"\n"+
        "liikuda ajas tagasi. Millest algab"
        +"\n"+
        "meie teine võimalus (ehk teine vaatus)?";
        
        ofFill();
        font.drawMultiLine(s, fontSize, leftAligner, explanationH);
        ofNoFill();
        drawAllrects();
        drawGridLegend();
    }
    
    for(int i = 0; i<BUTTONS;i++){
        
            if(buttons[i].answer==finalAnswer&&finalAnswer!=0){
                buttons[i].point[scene]=1;
            }
            else if(buttons[i].answer!=finalAnswer||finalAnswer==0||buttons[i].answer==0){
                buttons[i].point[scene]=0;
     
            }
        
    }
    
   
    ofFill();
    ofSetColor(255, 255, 0);
   
    
    if(lockResults && startScene &&!stageOne ){
        ofFill();
        ofSetColor(0, 195, 0);
        
        ofDrawRectangle(0,0, ofGetWidth(), ofGetHeight());
        ofSetColor(255);
        ofFill();
        if(scene<9){
            ofRectangle re = font.getBBox(theAnswer, 300, 0, 0);
            font.draw(theAnswer,300,ofGetWidth()/2-re.width/2,ofGetHeight()/2);
        }
        else if(scene==9){
            ofRectangle re = font.getBBox(theAnswer, 100, 0, 0);
            font.draw(theAnswer,100,ofGetWidth()/2-re.width/2,ofGetHeight()/2);
        }
    }
    
    if(startOver){
        startOver = false;
        lockResults=false;
        timer = 0;
        secondTimer = 0;
        stageC = 0;
        stageOne = true;
        showAnswer = false;
        theTimer = 0;
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 's'){
        if(!lockResults){
            
            
            for(int i = 0; i<BUTTONS;i++){

                if(buttons[i].table<TABS){
                    buttons[i].x=ofRandom(1);
                    buttons[i].y=ofRandom(1);
                    // if(buttons[i].ID<4){
                    
                    buttons[i].onOff=!buttons[i].onOff;
                   // buttons[i].haveBeenOn=true;
                    //}
                    buttons[i].rot=ofRandom(2*PI);
                }
                //buttons[i].APP=buttons[i].ID+5;
                
            }
        }
    }
    
    
    if(key=='l'){
        lockResults=!lockResults;
    }
    if(key == 'm'){
        startOver = true;
    }
    
    if(key=='a'){
        startScene = !startScene;
    }
    
    if(key=='n'){
        spermTables.clear();
        scene = (scene+1)%10;
        lockResults=false;
        timer = 0;
        secondTimer = 0;
        stageC = 0;
        stageOne = true;
        showAnswer = false;
        startScene = false;
        theTimer = 0;
        for(int i = 0; i < BUTTONS; i++){
            buttons[i].scenePoints=0;
            buttons[i].answer=0;
            buttons[i].spermRace=true;
            buttons[i].spermRace2=true;
            buttons[i].rotation=0;
            buttons[i].minRotation = 0;
        }
        
        
        spermStageTwo = true;
      //  showText = true;
    }
    
    if(key=='m'){
        theName = "Martin";
    }
    if(key=='a'){
        theName = "Artur";
    }
    if(key=='e'){
        theName = "Evald";
    }
    if(key=='w'){
        theName = "Willem";
    }
    
    
    if(key=='w'&&scene==2){
        theAnswer = "Allaheitlik";
        theAnswer = "Iseteadlik";
        lockResults = true;
        //lockResults = true;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
   xadjust = x;
  yafjust= y;
    cout<<"x then y"<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::nameStuff(){
 /*   tablenames.push_back("/ONE");
    tablenames.push_back("/TWO");
    tablenames.push_back("/THREE");
    tablenames.push_back("/FOUR");
    tablenames.push_back("/FIVE");
    tablenames.push_back("/SIX");
    tablenames.push_back("/SEVEN");
    tablenames.push_back("/EIGHT");
    tablenames.push_back("/NINE");
    tablenames.push_back("/TEN");
    tablenames.push_back("/ELEVEN");
    tablenames.push_back("/TWELVE");
    
    objnames.push_back("/zero");
    objnames.push_back("/one");
    objnames.push_back("/two");
    objnames.push_back("/three");
    objnames.push_back("/four");
    objnames.push_back("/five");
    
    retardnames.push_back("/objZero");
    retardnames.push_back("/objOne");
    retardnames.push_back("/objTwo");
    retardnames.push_back("/objThree");
    retardnames.push_back("/objFour");
    retardnames.push_back("/objFive");
    */
    tablenames.push_back("/tableOne");
    tablenames.push_back("/tableTwo");
    tablenames.push_back("/tableThree");
    tablenames.push_back("/tableFour");
    tablenames.push_back("/tableFive");
    tablenames.push_back("/tableSix");
    tablenames.push_back("/tableSeven");
    tablenames.push_back("/tableEight");
    tablenames.push_back("/tableNine");
    tablenames.push_back("/tableTen");
    tablenames.push_back("/tableEleven");
    tablenames.push_back("/tableTwelve");
    
    objnames.push_back("/zero");
    objnames.push_back("/one");
    objnames.push_back("/two");
    objnames.push_back("/three");
    objnames.push_back("/four");
    objnames.push_back("/five");
    
    retardnames.push_back("/objZero");
    retardnames.push_back("/objOne");
    retardnames.push_back("/objTwo");
    retardnames.push_back("/objThree");
    retardnames.push_back("/objFour");
    retardnames.push_back("/objFive");

    colors[0]->setHex(0xfff200);
    colors[1]->setHex(0xfcb040);
    colors[2]->setHex(0xbf1e2d);//
    colors[3]->setHex(0xee80b3);
    colors[4]->setHex(0x662d91);
    colors[5]->setHex(0x86c654);
    colors[6]->setHex(0x12572c);
    colors[7]->setHex(0x25aae1);
    colors[8]->setHex(0x2d439c);
    colors[9]->setHex(0x764c28);
    //colors[10]->setHex(0x939598);
    //colors[11]->setHex(0x000000);
    
    
    
}

//--------------------------------------------------------------

void ofApp::sceneTableConcencus(){
    
    int oneWon = 0;
    int twoWon = 0;
    
    ofColor c = *new ofColor;
    

    
    for(int i = 0; i<BUTTONS;i++){
        //set answer
        buttons[i].answer=0;
        if(buttons[i].onOff){
            if( buttons[i].rot>PI){
                buttons[i].answer = 1;
            }
            if( buttons[i].rot<PI){
                buttons[i].answer = 2;
            }
        }
    }
    
    
    tableList();
    for(int i = 0; i<TABS;i++){
        //calculate table answer
        tables[i]->tableAnswer=0;
        
        if(tables[i]->butts.size()>0){
            if(tables[i]->doWeAgreeInt()){
                if(tables[i]->butts[0].answer==1){
                    tables[i]->tableAnswer = 1;
                    //oneWon++;
                }
                else if(tables[i]->butts[0].answer==2){
                    tables[i]->tableAnswer = 2;
                    //twoWon++;
                }
            }
        }
    }
    
    
   
    
    //draw
    for(int i = 0 ; i< BUTTONS;i++){
        int transX = buttons[i].table*70+TRANSX;
        int transY = buttons[i].ID*70+TRANSY;
        ofNoFill();
        ofSetColor(255);
        ofSetLineWidth(4);
        ofPushMatrix();
        int grid = buttons[i].table/4;
        ofTranslate(transX+grid*20, transY);
     
        
        ofSetLineWidth(0);
        
        
        if(buttons[i].onOff){
            if(buttons[i].answer==1)ofSetHexColor(0xef5122);
            if(buttons[i].answer==2)ofSetHexColor(0x77cedc);
            ofFill();
            ofDrawRectangle(0, 0, 70, 70);
        }
        
        ofPopMatrix();
    }
    
    
    ofNoFill();
    ofSetLineWidth(4);
    for(int i = 0;i<TABS;i++){
        int transX = i*70+TRANSX;
        int transY = barHeight;
        ofPushMatrix();
        int grid = i/4;
        ofTranslate(transX+grid*20, transY);
        ofNoFill();
        ofSetColor(255);
        ofDrawLine(10, 10, 60, 60);
        ofDrawLine(60, 10, 10, 60);
        ofFill();
        if(tables[i]->doWeAgreeInt()&&tables[i]->tableAnswer==1){
            c.setHex(0xef5122);
            oneWon++;
        }
        if(tables[i]->doWeAgreeInt()&&tables[i]->tableAnswer==2){
            c.setHex(0x77cedc);
            twoWon++;
        }
        if(tables[i]->doWeAgreeInt()&&tables[i]->tableAnswer!=0){
            ofSetColor(c);
            ofDrawRectangle(0, 0, 70, 70);
            
        }
        ofNoFill();
        ofSetLineWidth(4);
        ofSetColor(255);
        ofDrawRectangle(0, 0, 70, 70);
        
        
        ofPopMatrix();
    }
    ofSetColor(255);
    ofNoFill();
    
    if(oneWon>twoWon&&oneWon>0){
        finalAnswer=1;
        theAnswer = "Jah";
    }
    else if(oneWon<twoWon&&twoWon>0){
        finalAnswer=2;
        theAnswer = "Ei";
    }
    else if(oneWon==twoWon){
        finalAnswer=0;
        theAnswer = "Kull või kiri";
    }
   
    
}


//---------------------------------------------------------------------------------------
void ofApp::tableList(){ // retarded structure...

    for(int u = 0; u<TABS; u++){
        tables[u]->butts.clear();
        
        for(int i = 0; i<BUTTONS;i++){
        if(buttons[i].table == tables[u]->table && buttons[i].onOff){
            tables[u]->butts.push_back(buttons[i]);
            }
        }
    }
}


void ofApp::sceneQuiz(){
    vector<string>questions;
    string s ;
    int transparency =200;

    if(secondAct){
        s = (string)
        "Mis ajavahemikus olid või on omavalitsused"
        +"\n" +
        "kohustatud tasuma erakoolide õppekoha"
        + "\n" +
        "tegevuskulusid sarnaselt munitsipaalkoolidega:";
        questions.push_back(s);
        
        s = (string)
        "Õppemaksu suuruse eliitkoolis määrab erakooli"
        + "\n" +
        "pidaja ning seda ei muudeta õppeaasta jooksul."
        + "\n" +
        "Õppemaksu suurust võib tõsta kahe õppeaasta "
        + "\n" +
        "vahel?";
        questions.push_back(s);
        s = (string)
        "Klassi täitumuse ülemine piirnorm põhikoolis on:";
        questions.push_back(s);
        
        s = (string)
        "Milline neist ei ole hindamise eesmärk?";
        questions.push_back(s);
        
        s = (string)
        "Kes on täna Eesti Vabariigi haridusminister?";
        questions.push_back(s);
        
        s = "";
        questions.push_back(s);
        questions.push_back(s);
        questions.push_back(s);
        questions.push_back(s);
    }
    
    if(!secondAct){
        s = (string)
        "Pedagoogikas vaadeldakse lapse koolivalmidust"
        +"\n" +
        "läbi kolme arenguaspektiaspekti. Milline"
        + "\n" +
        "neljast pakutavast variandist ei kuulu nende hulka?";
        questions.push_back(s);
        
        s = (string)
        "Milline nimetatud Eesti koolidest oli ajavahemikus"
        + "\n" +
        "2005 - 2011 riigieksamite punktide põhjal"
        + "\n" +
        "koostatud pingereas igal aastal esikolmikus?";

        questions.push_back(s);
        s = (string)
        "Mitu protsenti Tallinna algkooli õpilastest"
        + "\n" +
        "õpib eliitkoolis? (2004-2015)";
        questions.push_back(s);
        
        s = (string)
        "Kui suur on 2. klassi õpilase suurim lubatud"
        + "\n" +
        "nädala õppekoormus õppetundides?";
        questions.push_back(s);
        
        s = (string)
        "Leia ebasobiv vastusevariant:"
        + "\n" + "\n" +
        "Õppe ja kasvatuse rõhuasetused I kooliastmes "
        + "\n" +
        "(1.-3. klass). Esimeses kooliastmes keskendutakse:";
        questions.push_back(s);
        
        s = "";
        questions.push_back(s);
        questions.push_back(s);
        questions.push_back(s);
        questions.push_back(s);
    }

    int secongTimerThres;
    
    int firstTimerThres; //tiiimers
    //#QUIZTIMERS
    if(secondAct){
        secongTimerThres = 30*5;
    
        firstTimerThres = 25*30; //tiiimers

   
        if(!stageOne/*||stageC==4*/){
            firstTimerThres = 45*30;
        }
    }
    else if(!secondAct){
        secongTimerThres = 30*5;
        
        firstTimerThres = 45*30; //tiiimers
        
        
        if(!stageOne||stageC==4){
            firstTimerThres = 60*30;
        }
    }
    
    vector<int>a;
    //answers
    if(secondAct){
        a.push_back(2);
        a.push_back(2);
        a.push_back(2);
        a.push_back(2);
        a.push_back(4);
    }
    if(!secondAct){
        a.push_back(3);
        a.push_back(3);
        a.push_back(2);
        a.push_back(2);
        a.push_back(4);
    }
    string timeString ;
    
    if(!showAnswer){
        timer++;
        
        int time =(firstTimerThres - timer)/ofGetFrameRate();
        //time = firstTimerThres/ofGetFrameRate() - time;
        if(time>9){
            timeString = "00:"+ofToString(time);
        }
        else if(time<=9){
            timeString ="00:0"+ ofToString(time);
        }
        
        if(timer>firstTimerThres){
            if(stageC<a.size()){
                stageC++;
            }
            timer=0;
            showAnswer = true;
        }
    }
    if(showAnswer){
        timeString="00:00";
    }
    
    if(showAnswer&&stageOne){
        secondTimer++;
        ofFill();
        if (secondTimer>secongTimerThres) {
            
            //give points
            for(int i = 0 ; i<BUTTONS;i++){
                if(buttons[i].answer==a[stageC-1]){
                    buttons[i].points++;
                    buttons[i].scenePoints+=buttons[i].scenePoints;
                    if(buttons[i].scenePoints==0){
                        buttons[i].scenePoints=1;
                    }
                    
                }
            }
            if(stageC==a.size()){
                stageOne = false;
            }
            secondTimer=0;
            
            showAnswer=false;
     
        }
    }
    ofImage currentLegend;
    if(secondAct)currentLegend = legendAct2[stageC];
    else currentLegend = legend[stageC];
    
    lockResults = showAnswer;
    ofSetColor(255);
    ofFill();
    font.draw(timeString,timerFontSize,timerX,timerY);
    
    if(!showAnswer){
        font.drawMultiLine(questions[stageC], fontSize, questionAlignerX, explanationH);
        
        if(!stageOne){
        currentLegend.draw(legendPosX,legendPosY+70, currentLegend.getWidth()*legendScale, currentLegend.getHeight()*legendScale);
        }
        else if(stageOne){
            currentLegend.draw(legendPosX,legendPosY, currentLegend.getWidth()*legendScale, currentLegend.getHeight()*legendScale);
        }
    }
    if(!stageOne&&showAnswer){
        currentLegend.draw(legendPosX,legendPosY+70, currentLegend.getWidth()*legendScale, currentLegend.getHeight()*legendScale);
    }
    
    if(showAnswer&&stageOne){
        
        font.drawMultiLine(questions[stageC-1], fontSize,  questionAlignerX, /*questionAlignerY+150*/explanationH);
        
        if(!secondAct)legend[stageC-1].draw(legendPosX,legendPosY, legend[stageC-1].getWidth()*legendScale, legend[stageC-1].getHeight()*legendScale);
        else legendAct2[stageC-1].draw(legendPosX,legendPosY, legendAct2[stageC-1].getWidth()*legendScale, legendAct2[stageC-1].getHeight()*legendScale);
        
        int stupidScale = 70*legendScale;
        if(a[stageC-1]==3){
            //ofSetColor(255,transparency);
            ofSetColor(255);
            ofSetLineWidth(5);
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*0+12, legendPosX+stupidScale-8, legendPosY+stupidScale*1-8); //1
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*1-8, legendPosX+stupidScale-8, legendPosY+stupidScale*0+12); //1
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*1+12, legendPosX+stupidScale-8, legendPosY+stupidScale*2-8); //2
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*2-8, legendPosX+stupidScale-8, legendPosY+stupidScale*1+12); //2
            // ofDrawLine(legendPosX+12, legendPosY+stupidScale*2+12, legendPosX+stupidScale-8, legendPosY+stupidScale*3-8); //3
            // ofDrawLine(legendPosX+12, legendPosY+stupidScale*3-8, legendPosX+stupidScale-8, legendPosY+stupidScale*2+12); //3
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*3+12, legendPosX+stupidScale-8, legendPosY+stupidScale*4-8); //4
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*4-8, legendPosX+stupidScale-8, legendPosY+stupidScale*3+12); //4
            //ofDrawRectangle(legendPosX, legendPosY, stupidScale, stupidScale*2);
            //ofDrawRectangle(legendPosX, legendPosY+stupidScale*3, stupidScale, stupidScale);
        }
        if(a[stageC-1]==4){
            ofSetColor(255);
            ofSetLineWidth(5);
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*0+12, legendPosX+stupidScale-8, legendPosY+stupidScale*1-8); //1
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*1-8, legendPosX+stupidScale-8, legendPosY+stupidScale*0+12); //1
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*1+12, legendPosX+stupidScale-8, legendPosY+stupidScale*2-8); //2
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*2-8, legendPosX+stupidScale-8, legendPosY+stupidScale*1+12); //2
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*2+12, legendPosX+stupidScale-8, legendPosY+stupidScale*3-8); //3
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*3-8, legendPosX+stupidScale-8, legendPosY+stupidScale*2+12); //3
            //ofDrawLine(legendPosX+12, legendPosY+stupidScale*3+12, legendPosX+stupidScale-8, legendPosY+stupidScale*4-8); //4
            //ofDrawLine(legendPosX+12, legendPosY+stupidScale*4-8, legendPosX+stupidScale-8, legendPosY+stupidScale*3+12); //4
        }
        if(a[stageC-1]==2){
            ofSetColor(255);
            ofSetLineWidth(5);
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*0+12, legendPosX+stupidScale-8, legendPosY+stupidScale*1-8); //1
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*1-8, legendPosX+stupidScale-8, legendPosY+stupidScale*0+12); //1
            //ofDrawLine(legendPosX+12, legendPosY+stupidScale*1+12, legendPosX+stupidScale-8, legendPosY+stupidScale*2-8); //2
            //ofDrawLine(legendPosX+12, legendPosY+stupidScale*2-8, legendPosX+stupidScale-8, legendPosY+stupidScale*1+12); //2
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*2+12, legendPosX+stupidScale-8, legendPosY+stupidScale*3-8); //3
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*3-8, legendPosX+stupidScale-8, legendPosY+stupidScale*2+12); //3
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*3+12, legendPosX+stupidScale-8, legendPosY+stupidScale*4-8); //4
            ofDrawLine(legendPosX+12, legendPosY+stupidScale*4-8, legendPosX+stupidScale-8, legendPosY+stupidScale*3+12); //4
        }
        
    }
    
    
    string ans;
    if(stageOne){
        
        for(int i = 0 ; i<BUTTONS;i++){
            if(buttons[i].onOff){
                
                int answer;
                answer = ofMap(buttons[i].rot, 0, 2*PI, 1, 5);
                buttons[i].answer=answer;
                
                ofPushMatrix();
                
                int transX = buttons[i].table*70+TRANSX;
                int transY = buttons[i].ID*70+TRANSY;
                int grid = buttons[i].table/4;
                ofTranslate(transX+grid*20, transY);
                
                ofFill();
                
                ofSetColor(quizColors[buttons[i].answer-1]);
                ofDrawRectangle(0,0,70,70);
                
                if(showAnswer&&buttons[i].answer!=a[stageC-1]){
                    ofSetColor(255);
                   
                    ofSetLineWidth(5);
                    ofDrawLine(10, 10, 60, 60);
                    ofDrawLine(10, 60, 60, 10);
                }
                
                ofSetColor(255);
                
                fQuix.drawString(ofToString(buttons[i].scenePoints), 26, 46);
                ofPopMatrix();
                
            }
        }
    }
    
    
    
    
    ofSetColor(255);
    //1
    
    
    //Draw Answer
    //  ofDrawBitmapString("stage "+ofToString(stageC), 10,20);
    
    //---------------stage 2!------------
    

    ofFill();
    if(!stageOne){
    
        float finAn=0;
        float finVotes=0;
        float v1 = 0; float v2 = 0;
        
        for(int i = 0 ; i<BUTTONS;i++){
            if(buttons[i].onOff){
                
                if(buttons[i].rot>PI){
                    buttons[i].answer = 2;
                    v1+=buttons[i].scenePoints;
                    
                    
                }
                if(buttons[i].rot<=PI){
                    buttons[i].answer =  1;
                    v2+=buttons[i].scenePoints;
                    
                }
                ofPushMatrix();
                int transX = buttons[i].table*70+TRANSX;
                int transY = buttons[i].ID*70+TRANSY;
                int grid = buttons[i].table/4;
                ofTranslate(transX+grid*20, transY);
                
                ofFill();
                if(buttons[i].answer>0){
                   // ofSetColor(0);
                   // ofDrawRectangle(0, 0, 70, 70);
                    ofSetColor(quizColors[buttons[i].answer]);
                    float rectSize = ofMap(sqrt(buttons[i].scenePoints), 0, 5, 0, 70);
                    
                    ofDrawRectangle(35-(rectSize/2),35-(rectSize/2),rectSize,rectSize);
                }
                
                ofSetColor(255);
               // if(buttons[i].scenePoints==0){
                fQuix.drawString(ofToString(buttons[i].scenePoints), 26, 44);
                //}
                ofPopMatrix();
            }
        }
        float v3=v1+v2;
        
        v1 = v1/v3;
        v2 = v2/v3;
        
        string eet = ofToString(v1*100,1);
        string too = ofToString(v2*100,1);
        
        ofSetColor(quizColors[1]);
        ofDrawRectangle(TRANSX, barHeight, v2*(70*TABS+40), 70);
        ofFill();
        ofSetColor(255);
        font.draw(too, 70, TRANSX+30,barHeight+55);
        
        ofSetColor(quizColors[2]);
        ofDrawRectangle(TRANSX+(v2*(70*TABS+40)), barHeight, v1*(70*TABS+40), 70);
       
        ofSetColor(255);
        font.draw(eet, 70, TRANSX+(70*TABS+40)-160, barHeight+55);
    
        
        ofNoFill();
        ofSetLineWidth(5);
        ofSetColor(255);
        
        ofDrawRectangle(TRANSX, barHeight, v2*(70*TABS+40), 70);
        ofDrawRectangle(TRANSX+(v2*(70*TABS+40)), barHeight, v1*(70*TABS+40), 70);
        
        if(v1>v2){
            finalAnswer = 2;
            theAnswer = "Tavakooli";
        }
        else if(v1<v2){
            finalAnswer = 1;
            theAnswer = "Eliitkooli";
        }
        else if(v1==v2){
            finalAnswer = 0;
            theAnswer = "Kull või kiri";
        }
      
    }
    ofSetColor(255);

    
}



void ofApp::sceneDrugs(){
    int time_thres = 700;
    int minTime = 700;
    int who = 1000;
    int whi=1000;
    
    float green=0;
    float blue=0;
    int howManeAreHere=0;
    
    for(int i = 0; i<BUTTONS;i++){
        //set the answer
        
        if(buttons[i].onOff){

            howManeAreHere++;
            if(buttons[i].rot>=PI&&buttons[i].answer!=2){
                buttons[i].answer=2;
                buttons[i].blue=255;
                buttons[i].green=0;
                buttons[i].timeSinceLastVote = 0;

            }
            if (buttons[i].rot<PI&&buttons[i].answer!=1){
                buttons[i].answer=1;
                buttons[i].blue=0;
                buttons[i].green=255;
                buttons[i].timeSinceLastVote = 0;

            }
            if(buttons[i].timeSinceLastVote<time_thres){
                buttons[i].timeSinceLastVote++;
            }
            if(buttons[i].timeSinceLastVote<minTime){
                minTime = buttons[i].timeSinceLastVote;
                who = buttons[i].answer;
                whi=i;
            }
        }
    }

    for(int i = 0; i<BUTTONS;i++){
        ofFill();
        if(buttons[i].onOff && !lockResults){

            int num = 1;
            if(who==2)num =-1;
            buttons[i].blue=CLAMP(buttons[i].blue+((num*-1)*(1*(buttons[i].timeSinceLastVote/300))),0,255);
            buttons[i].green=CLAMP(buttons[i].green+(num*(1*(buttons[i].timeSinceLastVote/300))),0,255);

            int transX = buttons[i].table*70+TRANSX;
            int transY = buttons[i].ID*70+TRANSY;
            int grid = buttons[i].table/4;
            
            ofPushMatrix();
            ofTranslate(transX+grid*20, transY);
            
            if(buttons[i].answer==1)ofSetColor(255, 150, 0);
            if(buttons[i].answer==2)ofSetColor(0, 150, 255);
            
            ofDrawRectangle(0, 0, 70, 70);
            
            ofSetColor(buttons[i].green,150,buttons[i].blue);
            
            blue +=buttons[i].blue;
            green+=buttons[i].green;
            
            ofDrawRectangle(10,10,50,50);
            ofPopMatrix();
        }
    }
    
    int theline = 0;
    theline = (green/(blue+green))*(70*12+40);
    
    if(theline>(70*TABS+40)/2)theAnswer = "Paneb";
    
    if(theline<(70*TABS+40)/2)theAnswer = "Ei pane";
    
    else if(theline==(70*TABS+40)/2){
        finalAnswer = 0;
       // theAnswer = "Kull või kiri";
    }
    ofSetColor(255);
    
    drug.draw(TRANSX, barHeight,70*TABS+40,70);
    
    ofNoFill();
    ofSetLineWidth(5);
    
    ofDrawRectangle(TRANSX,barHeight, 70*TABS+40, 70);
    ofDrawLine(theline+TRANSX, barHeight, theline+TRANSX, barHeight+70);
}



void ofApp::drawAllrects(){
    for(int i = 0 ; i< BUTTONS;i++){
    int transX = buttons[i].table*70+TRANSX;
    int transY = buttons[i].ID*70+TRANSY;
        ofNoFill();
        ofSetColor(255);
        ofSetLineWidth(4);
    ofPushMatrix();
   // ofTranslate(transX, transY);
        int grid = buttons[i].table/4;
        ofTranslate(transX+grid*20, transY);
        if(buttons[i].haveBeenOn){
            ofDrawRectangle(0, 0, 70, 70);
        }
        ofPopMatrix();
    }

}



void ofApp::sceneMajority(){
 
    float red = 0.0;
    float blue = 0.0;
    
    ofFill();
    ofSetLineWidth(0);
    for(int i = 0; i<BUTTONS;i++){
       
        
        if(buttons[i].onOff){
            
            if(buttons[i].rot>PI){
                buttons[i].answer=1;
                red++;
                ofSetHexColor(0x3554a4);
            }
            else{
                buttons[i].answer=2;
                blue++;
                ofSetHexColor(0xffda40);
            }

            int transX = buttons[i].table*70+TRANSX;
            int transY = buttons[i].ID*70+TRANSY;
            int grid = buttons[i].table/4;
            
            ofPushMatrix();
            ofTranslate(transX+grid*20, transY);
            ofDrawRectangle(0,0,70,70);
            ofPopMatrix();
        }
    }
 
    if(blue>red){
        finalAnswer = 2;
        theAnswer = "Rootsi";
    }
    else if(blue<red){
        finalAnswer = 1;
        theAnswer = "Eesti";
    }
    else if(blue==red){
        finalAnswer = 0;
        theAnswer = "Kull või kiri";
    }
    
    string eet = ofToString(blue);
    string too = ofToString(red);
    float tot = blue+red;
    
    blue = blue/(tot);
    red = red/(tot);
    
    ofSetHexColor(0xffda40);
    ofDrawRectangle(TRANSX, barHeight, blue*(70*TABS+40), 70);

    ofSetHexColor(0x3554a4);
    ofDrawRectangle(TRANSX+(blue*(70*TABS+40)), barHeight, red*(70*TABS+40), 70);
    
    ofSetColor(255);
    font.draw(too, 70, TRANSX+(70*TABS+40)-100, barHeight+55);
    font.draw(eet, 70, TRANSX+30, barHeight+55);
    
    ofNoFill();
    ofSetLineWidth(5);
    ofSetColor(255);
    
    ofDrawRectangle(TRANSX, barHeight, blue*(70*TABS+40), 70);
    ofDrawRectangle(TRANSX+(blue*(70*TABS+40)), barHeight, red*(70*TABS+40), 70);

    drawAllrects();

}

void ofApp::sceneFullAgree(){

    ofSetColor(255);
    ofSetLineWidth(5);
    vector<string>names;
    names.push_back("Artur");
    names.push_back("Willem");
    names.push_back("Evald");
    names.push_back("Martin");
    
    bool done = true;
    int listen;
    

    int lastAnswer = -1;
    int thres = 0 ;
    for(int i = 0; i<BUTTONS;i++){
        buttons[i].answer = CLAMP(ofMap(int(buttons[i].rot), 0, 2*PI, 1, 5),1,4);
        
        if(buttons[i].onOff){
            thres++;
            if(lastAnswer == -1) lastAnswer=buttons[i].answer;
            if(buttons[i].answer != lastAnswer) done = false;
        }
    }
    if(thres < 4 )done = false;
    
    if(done){
        lockResults=true;
        OSCstring = boyName;
        theName = boyName;
        theAnswer = boyName;
    }
    
    for(int i = 0; i<BUTTONS;i++){

        if(buttons[i].onOff){
            boyName = names[buttons[i].answer-1];
            ofSetColor(255);

            ofSetLineWidth(5);
            ofNoFill();
            int transX = buttons[i].table*70+TRANSX;
            int transY = buttons[i].ID*70+TRANSY;
            
            ofPushMatrix();
            
            int grid = buttons[i].table/4;
            ofTranslate(transX+grid*20, transY);
            if(buttons[i].answer == 1)ofDrawLine(35, 0, 35, 70);
            if(buttons[i].answer == 2)ofDrawLine(0, 0, 70, 70);
            if(buttons[i].answer == 3)ofDrawLine(0, 35, 70, 35);
            if(buttons[i].answer == 4)ofDrawLine(0, 70, 70, 0);

            ofPopMatrix();
        }
    }
    drawAllrects();
}


void ofApp::sceneLogicGame(){
    //create array of usefull things
    if(!lockResults){
        theAnswer = "Allaheitlik";
    }
    vector<ofButton>zeros;
    for(int i =0;i<BUTTONS;i++){
        if(buttons[i].ID==0&&buttons[i].haveBeenOn){
            zeros.push_back(buttons[i]);
        }
    }
    
    
    for(int i = 0 ; i<zeros.size();i++){
        int orientation = 0;
        float xscale = 70;
        
        float ypos = TRANSX-50;
        float xpos = TRANSY+40;
        ofNoFill();
        ofSetColor(255);
        ofSetLineWidth(6);
     /*
        if(zeros.size()==1){
            orientation = 1;
            
        }
        else if(zeros.size()==2){
            orientation = to[i];
            ofDrawRectangle(ypos, xpos, 3*xscale, 2*xscale);
        }
        else if(zeros.size()==3){
            orientation = tre[i];
            ofDrawRectangle(ypos, xpos, 4*xscale, 2*xscale);
        }

        else if(zeros.size()==4){
            orientation = fire[i];
            ofDrawRectangle(ypos, xpos, 4*xscale, 3*xscale);
        }

        else if(zeros.size()==5){
            orientation = fem[i];
            ofDrawRectangle(ypos, xpos, 4*xscale, 4*xscale);
            
        }

        else if(zeros.size()==6){
            orientation = seks[i];
            ofDrawRectangle(ypos, xpos, 5*xscale, 4*xscale);
            
        }

        else if(zeros.size()==7){
            orientation = syv[i];
            ofDrawRectangle(ypos, xpos, 6*xscale, 4*xscale);
            
        }

        else if(zeros.size()==8){
            orientation = otte[i];
            ofDrawRectangle(ypos, xpos, 7*xscale, 4*xscale);
            
        }

        else if(zeros.size()==9){
            orientation = ni[i];
            ofDrawRectangle(ypos, xpos, 6*xscale, 5*xscale);
            
        }

        else if(zeros.size()==10){
      orientation = ti[i];
      ofDrawRectangle(ypos, xpos, 7*xscale, 5*xscale);
      
        }

        else if(zeros.size()==11){
            orientation = elve[i];
            ofDrawRectangle(ypos, xpos, 7*xscale, 6*xscale);
            
        }
*/
       // else if(zeros.size()==12){
       //     orientation = tolv[i];
       //     ofDrawRectangle(ypos, xpos, 9*xscale, 5*xscale);
      //  }
        if(TABS == 10){
            orientation = ti[i];
            ofDrawRectangle(ypos, xpos, 8*xscale, 5*xscale);
            
        }else{
            orientation = tolv[i];
            ofDrawRectangle(ypos, xpos, 9*xscale, 5*xscale);
        }
        
        ofSetColor(255);
        if(zeros.size()>0){
            
            if(TABS==10){
                float whereX = (zeros[i].x*(ofGetWidth()-840))-puzzlePngs[orientation].getWidth()/2+(ypos-200);
                float whereY=(zeros[i].y*(ofGetHeight()-200))-puzzlePngs[orientation].getHeight()/2+100;
                
                puzzlePngs[orientation].draw(whereX,whereY,puzzlePngs[orientation].getWidth(),puzzlePngs[orientation].getHeight());
                ofSetColor(255);
                ofFill();
                font.draw(ofToString(zeros[i].table+1), 38,
                          (zeros[i].x*(ofGetWidth()-840))+(ypos-210),//goes up if font does
                          (zeros[i].y*(ofGetHeight()-200))+110);//goes up if font goes up
                ofSetColor(255);
            }
            else{
                
                float whereX = (zeros[i].x*(ofGetWidth()-840))-puzzlePngs[i*4+orientation].getWidth()/2+(ypos-200);
                float whereY=(zeros[i].y*(ofGetHeight()-200))-puzzlePngs[i*4+orientation].getHeight()/2+100;
                
                puzzlePngs[i*4+orientation].draw(whereX,whereY,puzzlePngs[i*4+orientation].getWidth(),puzzlePngs[i*4+orientation].getHeight());
                ofSetColor(255);
                ofFill();
                font.draw(ofToString(zeros[i].table+1), 38,
                          (zeros[i].x*(ofGetWidth()-840))+(ypos-210),//goes up if font does
                          (zeros[i].y*(ofGetHeight()-200))+110);//goes up if font goes up
                ofSetColor(255);
            }
        }
    }

}

void ofApp::spermRace(){
    

        
        // for(auto b:buttons)b.rotation+=ofRandom(1);
        
        ofSetCircleResolution(500);
        float posX;
        float posY;
        int outerRim = 280;
        int innerEgg = 100;
        float degree = 0.0;
        int maxSize = 390;
        float lenght=0.0;
        
        // draw
        egg.draw(ofGetWidth()/2-egg.getWidth()/2,ofGetHeight()/2-egg.getHeight()/2,egg.getWidth(),egg.getHeight());
        
        
        tableList();
        
        for(int i = 0; i<BUTTONS;i++){
            //     buttons[i].rotation+=ofRandom(1);
            //     buttons[i].onOff = true;
            //     buttons[i].haveBeenOn = true;
            
            ofButton b = buttons[i];
            if(b.onOff){
                
                if(b.rotation>=maxSize){
                    b.rotation=maxSize;
                }
                
                //stop the first loosers
                if(b.rotation+b.radius>maxSize-outerRim && b.spermRace && b.haveBeenCounted){
                    
                    // girls
                    if(b.xyint==2 && b.haveBeenCounted){
                        b.haveBeenCounted = false;
                        specialSit.push_back(0);
                        cout <<specialSit.size()<<endl;
                    }
                    
                    // stopping girls if only girls have won.
                    if(specialSit.size()<TABS||b.xyint==1){
                        
                        b.minRotation = maxSize-(outerRim-20);
                        for(int u = 0; u<BUTTONS;u++){
                            if(buttons[u].spermRace && i!=u && b.table == buttons[u].table && buttons[u].spermRace){
                                buttons[u].spermRotFreeze = buttons[u].rotation;
                                buttons[u].spermRace = false;
                                buttons[u].spermRace2 = false;
                                spermTables.push_back(b.table);
                            }
                        }
                    }
                    
                    if(specialSit.size()>12&&b.xyint==2){
                        b.spermRotFreeze = buttons[i].rotation;
                        b.spermRace = false;
                        b.spermRace2 = false;
                        //b.haveBeenCounted = false;
                    }
                }
                
                //stop the second loosers
                if(b.rotation+b.radius>maxSize-innerEgg && b.xyint==1 && b.spermRace){
                    
                    spermStageTwo=false;
                    for(int j = 0; j<BUTTONS;j++){
                        if(i!=j){
                            if(buttons[j].spermRace2){
                                buttons[j].spermRotFreeze = buttons[j].rotation;
                            }
                            buttons[j].spermRace = false;
                            buttons[j].spermRace2 = false;
                        }
                    }
                }
                
                
                
                if(b.rotation+b.radius>maxSize-innerEgg && b.xyint==2 && b.spermRace){
                    b.spermRace = false;
                    b.spermRotFreeze = b.rotation;
                }
                
                if(b.spermRace&&buttons[i].spermRace2&&b.rotation+b.radius>maxSize-innerEgg){
                    b.rotation+=2;
                    if(b.rotation>maxSize-10){
                        lockResults=true;
                        theAnswer = buttons[i].letter+ofToString(b.table+1) +"="+ b.xy+"x";
                    }
                }
                
                if(TABS==10)degree = (b.table*36)+(b.ID*(30/6) + 3);
                else degree = (b.table*30)+(b.ID*(27/6) );
                degree = ofDegToRad(degree);
                
                if(!b.spermRace||!b.spermRace2){
                    lenght =(maxSize-buttons[i].spermRotFreeze);
                    posX = cos(degree)*lenght;
                    posY = sin(degree)*lenght;
                    ofSetColor(0);
                    
                }
                
                
                if(b.spermRace && b.spermRace2){
                    
                    lenght =(maxSize-buttons[i].rotation);
                    posX = cos(degree)*(maxSize-buttons[i].rotation);
                    posY = sin(degree)*(maxSize-buttons[i].rotation);
                    ofSetColor(255);
                }
                
                
                ofSetColor(255);
                ofSetLineWidth(7);
                ofNoFill();
                if(!spermStageTwo){
                    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, innerEgg);
                }
                
                for(int i = 0; i<spermTables.size();i++){
                    ofPolyline p = *new ofPolyline;
                    ofPoint point2(ofGetWidth()/2,ofGetHeight()/2);
                    p.arc(point2, outerRim, outerRim, spermTables[i]*30-3, (spermTables[i]+1)*30-7, 200);
                    p.draw();
                }
                
                ofPushMatrix();
                ofTranslate(ofGetWidth()/2+posX, ofGetHeight()/2+posY);
                ofNoFill();
                ofSetLineWidth(5);
                ofFill();
                
                ofDrawCircle(0, 0, b.radius);
                
                for(int u = 0; u<10;u++){
                    
                    float de = 0.1*((u-5)*(b.tailWiggle-0.5));
                    ofDrawCircle((cos(degree+de)*(b.radius+3*u)), sin(degree+de)* (b.radius+3*u), (10-u)/2);
                    
                }
                ofSetColor(0,195,0);
                font.draw(ofToString(buttons[i].letter), 26, -13, +8);
                font.draw(buttons[i].xy, 26,0, +8);
                ofPopMatrix();
                buttons[i]=b;
            }
        }
        
        
        
    
    

    
    /*
    ofSetCircleResolution(500);
    float posX;
    float posY;
    int outerRim = 280;
    int innerEgg = 100;
    float degree = 0.0;
    int maxSize = 390;
    float lenght=0.0;
    
    // draw
    egg.draw(ofGetWidth()/2-egg.getWidth()/2,ofGetHeight()/2-egg.getHeight()/2,egg.getWidth(),egg.getHeight());
    
    
    tableList();

    for(int i = 0; i<BUTTONS;i++){
        ofButton b = buttons[i];
        if(b.onOff){
            
            if(b.rotation>=maxSize){
                b.rotation=maxSize;
            }
            
            //stop the first loosers
            if(b.rotation+b.radius>maxSize-outerRim && b.spermRace && b.haveBeenCounted){
                
                if(b.xyint==2 && b.haveBeenCounted){
                    b.haveBeenCounted = false;
                    specialSit.push_back(0);
                }
                
                // stopping girls if only girls have won.
                if(specialSit.size()<12||b.xyint==1){

                    b.minRotation = maxSize-(outerRim-20);
                    for(int u = 0; u<BUTTONS;u++){
                        if(buttons[u].spermRace && i!=u && b.table == buttons[u].table && buttons[u].spermRace){
                            buttons[u].spermRotFreeze = buttons[u].rotation;
                            buttons[u].spermRace = false;
                            buttons[u].spermRace2 = false;
                            spermTables.push_back(b.table);
                        }
                    }
                }
                
                if(specialSit.size()>12&&b.xyint==2){
                    b.spermRotFreeze = buttons[i].rotation;
                    b.spermRace = false;
                    b.spermRace2 = false;
                }
            }
            
            //stop the second loosers
            if(b.rotation+b.radius>maxSize-innerEgg && b.xyint==1 && b.spermRace){
                
                spermStageTwo=false;
                for(int j = 0; j<BUTTONS;j++){
                    if(i!=j){
                        if(buttons[j].spermRace2){
                            buttons[j].spermRotFreeze = buttons[j].rotation;
                        }
                        buttons[j].spermRace = false;
                        buttons[j].spermRace2 = false;
                    }
                }
            }
            
            
            
            if(b.rotation+b.radius>maxSize-innerEgg && b.xyint==2 && b.spermRace){
                b.spermRace = false;
                b.spermRotFreeze = b.rotation;
            }
            
            if(b.spermRace&&buttons[i].spermRace2&&b.rotation+b.radius>maxSize-innerEgg){
                b.rotation+=2;
                if(b.rotation>maxSize-10){
                    lockResults=true;
                    theAnswer = buttons[i].letter+ofToString(b.table+1) +"="+ b.xy+"x";
                }
            }
            
            if(TABS==10)degree = (b.table*36)+(b.ID*(30/6) + 3);
            else degree = (b.table*30)+(b.ID*(27/6) );
            degree = ofDegToRad(degree);
            
            if(!b.spermRace||!b.spermRace2){

                
                lenght =(maxSize-buttons[i].spermRotFreeze);
                posX = cos(degree)*lenght;
                posY = sin(degree)*lenght;
                ofSetColor(0);
               
            }

            
            if(b.spermRace && b.spermRace2){
                
                lenght =(maxSize-buttons[i].rotation);
                posX = cos(degree)*(maxSize-buttons[i].rotation);
                posY = sin(degree)*(maxSize-buttons[i].rotation);
                ofSetColor(255);
            }
            

            ofSetColor(255);
            ofSetLineWidth(7);
            ofNoFill();
            if(!spermStageTwo){
                ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, innerEgg);
            }
            
            for(int i = 0; i<spermTables.size();i++){
                ofPolyline p = *new ofPolyline;
                ofPoint point2(ofGetWidth()/2,ofGetHeight()/2);
                p.arc(point2, outerRim, outerRim, spermTables[i]*30-3, (spermTables[i]+1)*30-7, 200);
                p.draw();
            }
            
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2+posX, ofGetHeight()/2+posY);
            ofNoFill();
            ofSetLineWidth(5);
            ofFill();
            
            ofDrawCircle(0, 0, b.radius);

            for(int u = 0; u<10;u++){
                
                float de = 0.1*((u-5)*(b.tailWiggle-0.5));
                ofDrawCircle((cos(degree+de)*(b.radius+3*u)), sin(degree+de)* (b.radius+3*u), (10-u)/2);
                
            }
            ofSetColor(0,195,0);
            font.draw(ofToString(buttons[i].letter), 26, -13, +8);
            font.draw(buttons[i].xy, 26,0, +8);
            ofPopMatrix();
        }
    }*/
    
    

}

void ofApp::sceneCalculate(){
    
    currentSum=0;

    for(auto b : buttons)b.answer=int(ofMap(b.rot, 0, 2*PI, 10, 0));
    
    for(int i = 0 ; i<BUTTONS;i++){
        if(buttons[i].onOff){
            ofPushMatrix();
            
            int transX = buttons[i].table*70+TRANSX;
            int transY = buttons[i].ID*70+TRANSY;
            int grid = buttons[i].table/4;
            ofTranslate(transX+grid*20, transY);
            
            ofFill();
            
            ofSetColor(0);
            ofDrawRectangle(0,0,70,70);
            
            ofSetColor(255);
            
            fQuix.drawString(ofToString(buttons[i].answer), 26, 44);
            ofPopMatrix();
            currentSum+=buttons[i].answer;
        }
    }
    
    float red = ofMap(currentSum, 0, 10*onButtons.size(), 0, 70*TABS+40);
    float blue = ofMap(theSum, 0, 10*onButtons.size(), 0, 70*TABS+40);
    
    
    // ofSetColor(255);
    ofSetColor(255,150,20);
    ofDrawRectangle(TRANSX, barHeight, 70*TABS+40, 70);
    ofSetColor(0);
    ofDrawRectangle(TRANSX, barHeight, red, 70);
    
    ofNoFill();
    ofSetLineWidth(5);
    // ofSetColor(255,150,20);
    ofSetColor(255);
    ofDrawLine(TRANSX+blue, barHeight, TRANSX+blue, barHeight+70);
    
    ofDrawRectangle(TRANSX, barHeight, 70*TABS+40, 70);
    
    // buffer
    if(currentSum==theSum)calculationFix++;
    else calculationFix=0;

    if(calculationFix>30*8){
        lockResults = true;
        theAnswer = "Müüb";
    }
    if(!lockResults){
        theAnswer = "Ei müü";
    }
    
    
}

void ofApp::drawGridLegend(){
    ofSetColor(255);
    
    for(int i = 0;i<TABS;i++){
        int transX = tables[i]->table*70+TRANSX;
        int transY = TRANSY-70;
        ofPushMatrix();
        int grid = i/4;
        ofTranslate(transX+grid*20, transY);
        gridLegend[i].draw(0,0, 70, 70);
        ofPopMatrix();
    
    }
    for(int i = 0;i<objnames.size();i++){
        int transX = TRANSX-70;
        int transY = i*70+TRANSY;
        ofPushMatrix();
        ofTranslate(transX, transY);
        
        //12 not TABS because there are that many image loaded.
        gridLegend[i+12].draw(0,0, 70, 70);
        ofPopMatrix();
        
    }

}

//------------------------------------------------------------------------------------------------------
//----------------table agrees, their power depends on the amount of agreeing, final answer depends on all tables

void ofApp::theTimerFunction(int thres, float x, float y, int timerSize){
    if(theTimer<thres){
        theTimer++;
    }
    
    string timeString;
    
    if(!lockResults)theTime = (thres-theTimer)/30;
    if(theTimer>=thres)lockResults = true;
    
    if(thres>60*30){
        int minutuet = theTime/60;
        int seconds = theTime-(minutuet*60);
        timeString = ofToString(minutuet, 2, '0')+":"+ofToString(seconds, 2, '0');
    }else{
        timeString = ofToString(int(theTime),2,'0');
    }

    ofSetColor(255);
    font.draw(timeString, timerSize, x, y);
}

void ofApp::crossout(){
    if(lockResults&&startScene){
        for(int i = 0 ; i< BUTTONS;i++){
            if(buttons[i].answer!=finalAnswer&&buttons[i].onOff&&!stageOne){
                int transX = buttons[i].table*70+TRANSX;
                int transY = buttons[i].ID*70+TRANSY;
                
                ofNoFill();
                ofSetColor(255);
                ofSetLineWidth(4);
                
                ofPushMatrix();
                int grid = buttons[i].table/4;
                ofTranslate(transX+grid*20, transY);
                
                ofSetLineWidth(5);
                
                ofDrawLine(10, 10, 60, 60);
                ofDrawLine(10, 60, 60, 10);
                
                ofPopMatrix();
            }
        }
    }
}


void ofApp::flipCoin(){
    startScene=true;
    for(int i = 0; i<BUTTONS;i++){
        
        ofFill();
        if(buttons[i].onOff){

            int transX = buttons[i].table*70+TRANSX;
            int transY = buttons[i].ID*70+TRANSY;
            ofPushMatrix();
            int grid = buttons[i].table/4;

            ofTranslate(transX+grid*20+35, transY+35);
            int  whatImage = CLAMP(ofMap(buttons[i].rot, 0, 2*PI, 0, 16), 0, 15);
            flip[whatImage].draw(-35,-35,0,70,70);
            
            ofNoFill();
            ofPopMatrix();
        }
    }
}

void ofApp::sceneTurnBack(){

    vector<int>abc;
    abc.resize(7);
    string temp = "A;B;C;D;E;F;G";
    vector<string>AB = ofSplitString(temp, ";");
    
    for(int i = 0; i<BUTTONS;i++){
        if(buttons[i].onOff){

            string s;

            buttons[i].answer = CLAMP(int(ofMap(buttons[i].rot, 0, 2*PI, 0, 7)), 0, 6);
            for(int u = 0; u<abc.size();u++){
                if(buttons[i].answer == u){
                    abc[u]++;
                    s=AB[u];
                }
            }

            
            int transX = buttons[i].table*70+TRANSX;
            int transY = buttons[i].ID*70+TRANSY;
            int grid = buttons[i].table/4;
            
            ofPushMatrix();
            ofTranslate(transX+grid*20, transY);
            ofFill();
            ofSetColor(0);
            ofDrawRectangle(0, 0, 70, 70);
            
            ofSetColor(255);
            font.draw(s, 40, 24, 46);
            
            ofPopMatrix();
        }
    }

    vector<string>whatever;
    whatever.push_back("A    Nimepanekust:");
    whatever.push_back("B    Riietumisväljakutsest:");
    whatever.push_back("C    Valikust eliit- ja tavakooli vahel:");
    whatever.push_back("D    Valikust Rootsi ja Eesti vahel:");
    whatever.push_back("E    Tabletisöömisest räpases peldikus:");
    whatever.push_back("F    Otsusest minna ülikooli või mitte:");
    whatever.push_back("G    Isa surmast ja korterimüügist:");

    int maxNumber = 0;
    int whoIsIt = -1;
    for(int i =0 ; i<abc.size();i++){
        if(abc[i]>maxNumber){
            maxNumber = abc[i];
            whoIsIt = i;
        }
    }
    for(int i =0 ; i<abc.size();i++){
        if(maxNumber==abc[i]){
            theAnswer=whatever[i];
            finalAnswer = i+1;
        }
    }


    for(int i = 0; i<abc.size();i++){
        if(maxNumber==abc[i] && i!=whoIsIt){ // means we have two of the same number, a draw!
            theAnswer = "Kull või kiri";
        }
    }
    
    for(int i = 0; i<abc.size();i++){
        ofPushMatrix();
        ofTranslate(TRANSX, i*50*legendScale + legendPosY);
        ofRectangle re = font.getBBox("E.   Tabletisöömisest räpases peldikus:", 40, 0, 0);
        ofSetColor(0);
        ofFill();
        ofDrawRectangle(0, 0, 50, 50);
        ofSetColor(255);
        font.draw(whatever[i], 40, 14, 35);
        font.draw(ofToString(abc[i]), 40, 14+re.width+10, 35);
        ofNoFill();
        ofSetLineWidth(4);
        ofDrawRectangle(0,0, 50, 50);
        ofPopMatrix();
    }
    
   // font.draw(ofToString(a)+":"+ofToString(b)+":"+ofToString(c)+":"+ofToString(d)+":"+ofToString(e)+":"+ofToString(f)+":"+ofToString(g), 20, 20, 50);
}


