#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){	

    ofBackground(ofColor::black);
    ofDisableAntiAliasing();
    
    //SETUP BUTTONS//
    
    textButton.setSize(300,150);
    ofPoint pos = ofPoint(ofGetWidth() * 0.5f, ofGetHeight() * 0.5f);
    textButton.setPosition(pos);
    textButton.setBorderColor(ofColor::white);
    textButton.setHighlightColor(ofColor(50,200,150));
    
    debugButton.setSize(50,50);
    ofPoint debugButtonPos = ofPoint(ofGetWidth() * 0.05f, ofGetHeight() * 0.05f);
    debugButton.setPosition(debugButtonPos);
    debugButton.setBorderColor(ofColor::white);
    debugButton.setHighlightColor(ofColor::salmon);
    
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
    
    //load();
    
    sender.setup( HOST, SENDPORT );

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
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    textButton.draw();
    debugButton.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
//    
//    if (key == 'd') {
//        
//        bDraggable = !bDraggable;
//        textButton.setDraggable(bDraggable);
//    }
//    
//    if (key == 's') {
//        
//        save();
//    }
//    
//    if (key == 'l') {
//        
//        load();
//    }
    
    textButton.triggerOn(touch.x, touch.y);
    
    if (textButton.getIsPressed()) {
        
        ofxOscMessage m;
        m.setAddress( "/textButton/test" );
        sender.sendMessage( m );
    }
    
    debugButton.triggerOn(touch.x, touch.y);
    
    if (debugButton.getIsPressed()) {
        bDraggable = !bDraggable;
        textButton.setDraggable(bDraggable);
        
    }
    
}
//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
    
    textButton.triggerOff();
    debugButton.triggerOff();
    
}
//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

    textButton.setDragPosition(ofPoint(touch.x, touch.y));

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
