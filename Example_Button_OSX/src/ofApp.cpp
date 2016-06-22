#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(ofColor::black);
    ofDisableAntiAliasing();
    
    //SETUP BUTTONS//
    
    textButton.setSize(300,150);
    ofPoint pos = ofPoint(ofGetWidth() * 0.25f, ofGetHeight() * 0.5f);
    textButton.setPosition(pos);
    textButton.setBorderColor(ofColor::white);
    textButton.setHighlightColor(ofColor(50,200,150));
    
    //Enter some text to display in button//
    
    ofFile fontPath = ofFile("fonts/Verdana.ttf");
    textButton.loadFont(fontPath.getAbsolutePath(), 14, "Test Button");
    
    //Enter an image file as an icon//
    
    //    ofFile imgPath = ofFile("images/play.png");
    //    textButton.loadImage(imgPath.getAbsolutePath());
    
    bDraggable = false;
    
    //Load XML and OSC//
    
    xml.load("settings.xml");
    xmlLabel = "BUTTON";
    
    load();
    
    sender.setup( HOST, SENDPORT );
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    textButton.draw();
    
}
void ofApp::save(){
    
    if(xml.exists(xmlLabel)) {
        
        xml.setValue("//X", ofToString(textButton.getPosition().x));
        xml.setValue("//Y", ofToString(textButton.getPosition().y));
        
    } else {
        
        ofXml point;
        point.addChild(xmlLabel);
        point.setTo(xmlLabel);
        
        point.addValue("X", textButton.getPosition().x);
        point.addValue("Y", textButton.getPosition().y);
        
        xml.addXml(point);
    }
    
    xml.save("settings.xml");
    ofLog(OF_LOG_NOTICE, "Saving XML...");
}
void ofApp::load(){
    
    xml.load("settings.xml");
    ofLog(OF_LOG_NOTICE, "Loading XML...");
    
    if (xml.exists(xmlLabel)) {
        ofPoint pos = ofPoint(ofToInt(xml.getValue("//X")), ofToInt(xml.getValue("//Y")));
        textButton.setPosition(pos);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'd') {
        
        bDraggable = !bDraggable;
        textButton.setDraggable(bDraggable);
    }
    
    if (key == 's') {
        
        save();
    }
    
    if (key == 'l') {
        
        load();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    textButton.setDragPosition(ofPoint(x,y));
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    textButton.triggerOn(x, y);
    
    if (textButton.getIsPressed()) {
        
        ofxOscMessage m;
        m.setAddress( "/textButton/test" );
        sender.sendMessage( m );
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    textButton.triggerOff();
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
