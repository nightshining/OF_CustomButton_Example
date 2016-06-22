#pragma once

#include "ofMain.h"
#include "ofxCustomButton.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define SENDPORT 7400


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxCustomButton textButton;
    
    bool bDraggable;
    void save();
    void load();
    
    ofXml xml;
    string xmlLabel;
    
    ofxOscSender sender;
    
};




