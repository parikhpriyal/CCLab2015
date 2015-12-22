#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(20);
    hound.load("Greyhound (Original Mix).mp3");
    
    hound.setMultiPlay(true);
    
    ang = 1;
    
    ofBackground(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    string tempStr = "click to 's' to start music";
    ofDrawBitmapString(tempStr, ofGetWindowWidth()-250,ofGetWindowHeight()-100);
    string temStr = "click to 'p' to pause music";
    ofDrawBitmapString(temStr, ofGetWindowWidth()-250,ofGetWindowHeight()-75);
    string teStr = "click to 'r' to resume music";
    ofDrawBitmapString(teStr, ofGetWindowWidth()-250,ofGetWindowHeight()-50);
    
    r = ofRandom(255);
    g = ofRandom(255);
    b = ofRandom(255);
    
    
    for(int i = 0; i<ofGetWindowHeight() && i<ofGetWindowWidth(); i+=100){
        ofRotate(ang);
        ofSetColor(r, g, b, 150);
        ofRect(0, 0, ang+i, ang+i);
        ang++;
    }
    
    
    ofSetHexColor(0x0cb0b6);
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    ofBeginShape();
    for (int i = 0; i < 10; i++){
        ofVertex(ofRandom(0,ofGetWindowHeight()), ofRandom(ofGetWidth(),0));
    }
    ofEndShape();
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        hound.play();
    }
    if(key == 'p'){
        hound.setPaused(true);
    }
    if(key == 'r'){
        hound.setPaused(false);
    }
    if(key == 'e'){
        hound.stop();
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
