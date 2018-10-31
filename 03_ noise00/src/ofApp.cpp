#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	float xInc = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 0.01);
	float xOff = 0;
	
	float yInc = ofMap(ofGetMouseY(), 0, ofGetWidth(), 0, 0.01);
	float yOff = 0;
	
	float time = ofGetElapsedTimef();
	for (int y = 0; y < ofGetHeight(); y+=2)
	{
		for (int x = 0; x < ofGetWidth(); x+=2)
		{
			xOff += sin(time * 0.002 + xInc);
			yOff += sin(time * 0.002 + yInc);
			
			float noise = ofNoise(xOff, yOff);
			float hue = 255 * noise;
			
			ofSetColor(ofColor::fromHsb(hue, 255, 255));
			ofFill();
			ofDrawRectangle(x, y, 2, 2);
		}
	}

}

