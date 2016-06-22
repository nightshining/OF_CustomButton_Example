#pragma once

#include "ofMain.h"

class ofxCustomButton {
    
public:
    ofxCustomButton();
    ~ofxCustomButton();

    void draw();

    void loadFont(string fontfile, int fontsize, string label);
    void loadImage(string imgfile);
    void setPosition(ofPoint pos){ rectPos = pos; };
    void setSize(int w, int h){ rectW = w; rectH = h; };
    
    void setBorderColor(ofColor c){cBorder = c;};
    void setHighlightColor(ofColor c){cHighlight = c; cHighlight.a = 0;};
    void setLabelColor(ofColor c){cLabel = c;};
    
    void setDraggable(bool toggle){bDraggable = toggle;};
    void setDragPosition(ofPoint pos);


    void triggerOn(int x, int y);
    void triggerOff();
    
    bool getIsPressed(){return bTrigger;};
    ofPoint getPosition(){return rectPos;}

    
private:
    
    void drawDebug();
    void drawButton();
    void drawLabel();
    
    //BUTTON//
    
    ofRectangle rect;
    ofPoint rectPos;
    int rectW, rectH;
    ofColor cHighlight, cBorder, cLabel, cImg;
    bool bTrigger, bDraggable;
    float fade;
    
    //FONT//
    
    ofTrueTypeFont font;
    string rectTitle;
    bool bFont;
    
    //IMAGE//
    
    ofImage img;
    bool bImage;
    

    
    
};
