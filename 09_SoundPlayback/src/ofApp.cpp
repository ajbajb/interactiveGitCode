#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
//    sound1.load("23646_loofa_A_002.wav");
//    sound2.load("23646_loofa_A_002.wav");
    sound1.load("chomsky1.mp3");
    sound2.load("chomsky1.mp3");
    
    sound1.setLoop(true);
    sound1.setPan(-1);
    sound2.setLoop(true);
    sound2.setPan(1);
    
    bPlay = false;
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSoundUpdate();
    
    float time = ofGetElapsedTimef();
    float sineSpeed = ofGetMouseX() * 0.02;
    float noiseStep = ofGetMouseY() * 0.02;
    
    // we will set pitches with noise func and vol with a sin func
    
    pitch1 = ofNoise(time * noiseStep) * 4 - 2;
    pitch2 = ofNoise(time * noiseStep + 5.5) * 4 - 2;
    
    vol1 = 0.5 + 0.5 * sin(time * sineSpeed * 1.0);
    vol2 = 0.5 + 0.5 * sin(time * sineSpeed * 1.25);
    
    sound1.setSpeed(pitch1);
    sound1.setVolume(vol1);
    sound2.setSpeed(pitch2);
    sound2.setSpeed(vol2);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(25);
    
    float xpos1 = ofMap(pitch1, -2, 2, 0.0, ofGetWidth());
    float ypos1 = ofMap(vol1, 0.0, 1.0, 0.0, ofGetHeight());
    
    float xpos2 = ofMap(pitch2, -2, 2, 0.0, ofGetWidth());
    float ypos2 = ofMap(vol2, 0.0, 1.0, 0.0, ofGetHeight());
    
    if (sound1.getPosition() < 0.2)
    {
        ofSetColor(255, 255, 0);
    }
    else
    {
         ofSetColor(255, 10, 100);
    }
    ofDrawCircle(xpos1, ypos1, 10);
    
    if (sound2.getPosition() < 0.2)
    {
        ofSetColor(255, 255, 0);
    }
    else
    {
        ofSetColor(255, 10, 100);
    }
    ofDrawCircle(xpos2, ypos2, 10);
    
    ofSetColor(255);
    ofDrawBitmapString("1", xpos1, ypos1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == ' ')
    {
        bPlay =! bPlay;
    }
    
    if (bPlay)
    {
        sound1.play();
        sound2.play();
    }
    else
    {
        sound1.stop();
        sound2.stop();
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
