#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    sampleRate = 44100;
    int bufferSize = 512;
    phase = 0.0;
  
    lAudio.assign(bufferSize, 0.0);
    rAudio.assign(bufferSize, 0.0);
    
    ofSoundStreamSettings settings;
    
    settings.setOutListener(this);
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.sampleRate = sampleRate;
    settings.bufferSize = bufferSize;
    settings.numBuffers = 4;
    stream.setup(settings);
}

//--------------------------------------------------------------
void ofApp::update()
{
    frequency = ofMap(ofGetMouseX(), 0, ofGetWidth(), 30, 1000, true);
    volume = ofMap(ofGetMouseY(), 0.0, ofGetHeight(), 0.0, 1.0, true);
    
    phaseAddr = (float)(frequency * twopi)/(float)sampleRate;

}

//--------------------------------------------------------------
void ofApp::draw()
{
    string frameStr = "Framerate:: " + ofToString(ofGetFrameNum());
    ofDrawBitmapString(frameStr, 20, 20);
}

void ofApp::audioOut(ofSoundBuffer & output)
{
    while (phase > twopi)
    {
        phase -= twopi;
    }
    
    if (bNoise)
    {
        for (int i = 0; i < output.getNumFrames(); i++)
        {
            output[i * output.getNumChannels()     ] = ofRandom(0, 1) * volume;
            output[i * output.getNumChannels() + 1 ] = ofRandom(0, 1) * volume;
        }
    }
    else
    {
        for (int i = 0; i < output.getNumFrames(); i++)
        {
            phase += phaseAddr;
            float sample = sin(phase) * volume;
            output[i * output.getNumChannels()    ] = sample;
            output[i * output.getNumChannels() + 1] = sample;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
