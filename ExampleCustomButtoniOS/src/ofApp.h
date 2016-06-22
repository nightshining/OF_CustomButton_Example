#pragma once

#include "ofxiOS.h"
#include "ofxCustomButton.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define SENDPORT 7400

class ofApp : public ofxiOSApp {
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
    ofxCustomButton textButton, debugButton;
    
    bool bDraggable;
    void save();
    void load();
    
    ofXml xml;
    string xmlLabel;
    
    ofxOscSender sender;
    

};


