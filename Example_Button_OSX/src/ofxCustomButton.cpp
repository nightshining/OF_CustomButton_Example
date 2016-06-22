
#include "ofxCustomButton.h"


ofxCustomButton::ofxCustomButton() {
    
    bTrigger = false;
    bDraggable = false;
    bFont = false;
    bImage = false;
    rectPos = ofPoint(0,0);
    rectW = 0;
    rectH = 0;

    cHighlight = ofColor(50);
    cHighlight.a = 0;

}

ofxCustomButton::~ofxCustomButton() {
    
}

void ofxCustomButton::loadFont(string fontfile, int fontsize, string label){
    
    bFont = true;

    if (bFont) {
        
        font.load(fontfile, fontsize);
        rectTitle = label;
    }
}

void ofxCustomButton::loadImage(string imgfile){
    
    bImage = true;
    
    if (bImage){
        
        img.load(imgfile);
    }
    
}
void ofxCustomButton::setDragPosition(ofPoint pos){
    
    if (bDraggable && rect.inside(pos.x, pos.y)) {

        rectPos = pos;
        rect.setFromCenter(rectPos, rectW, rectH);
    }
    
}
void ofxCustomButton::triggerOn(int x, int y){
    
    bTrigger = rect.inside(x, y);
    
    if (bTrigger) {
        
        cHighlight.a = 220;
        
    }
}
void ofxCustomButton::triggerOff(){

    bTrigger = false;
    
    if (!bTrigger) {
        cHighlight.a = 0;
    }
}
void ofxCustomButton::draw(){
    
    drawButton();
    
    if ( !bDraggable ) {
        
        rect.setFromCenter(rectPos, rectW, rectH);
        
    } else {

        drawDebug();

    }
}


void ofxCustomButton::drawButton(){
    
    int w = rect.getWidth();
    int h = rect.getHeight();
    
    ofPushStyle();
    ofPushMatrix();
    
    ofTranslate(rect.getPosition());
    if (bImage){
        
        ofSetColor(cImg);
        img.draw(0,0,w, h);
    }
    //FILL//
    ofSetColor(cHighlight);
    ofFill();
    ofDrawRectangle(0,0, w, h);
    //BORDER//
    ofSetColor(cBorder);
    ofNoFill();
    ofDrawRectangle(0,0, w, h);

    
    ofPopMatrix();
    ofPopStyle();

    if (bFont) {
        
        float x = rectPos.x;
        float y = rectPos.y;
        
        ofRectangle tempRect = font.getStringBoundingBox(rectTitle, x, y);
        ofPoint centerDiff = tempRect.getCenter() - ofPoint(x, y);

        ofPushStyle();
        ofSetColor(cLabel);
        ofPushMatrix();
        ofTranslate(x,y);
        font.drawString(rectTitle, -centerDiff.x, -centerDiff.y);
        ofPopMatrix();
        ofPopStyle();
        
    }
    
}
void ofxCustomButton::drawDebug(){
    
    ofPushStyle();
    ofPushMatrix();
    ofSetLineWidth(0.1f);
    ofSetColor(ofColor::red);
    ofDrawLine(0,rectPos.y, ofGetWidth(), rectPos.y);
    ofDrawLine(rectPos.x, 0, rectPos.x, ofGetHeight());
    ofDrawCircle(rectPos, 5);
    ofDrawBitmapString("X % ofGetWidth: " + ofToString(rect.getCenter().x / ofGetWidth(), 2), rect.getCenter().x, rect.getCenter().y - 10);
    ofDrawBitmapString("Y % ofGetHeight: " + ofToString(rect.getCenter().y / ofGetHeight(), 2), rect.getCenter().x, rect.getCenter().y);
    ofPopMatrix();
    ofPopStyle();
    
}




