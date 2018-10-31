#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	// get the time as a float
	float time = ofGetElapsedTimef();
	
	// we inc by this amount (which changes with sine)
	float sine = sin(time);

	float xInc = 0.001 * sine;
	float xOff = 0;
	
	// same for y
	float cosine = cos(time);
	
	float yInc = 0.002 * cosine;
	float yOff = 0;
	
	float sine1 = sin(time * 0.02);

	float zInc = 0.001 * sine1;
	float zOff = 0;
	
	cam.begin();
	
	for (int z = 0; z < 100; z += 2)
	{
		for (int y = 0; y < 100; y+=2)
		{
			for (int x =0; x < 100; x+=2)
			{
			
				xOff = xInc;
				yOff = yInc;
				zOff = zInc;
				// use where we are in our loop to set our noise value
				float noise = ofNoise(x*xOff, y*yOff, z*zOff);
				float hue = noise * 255;
			
				ofSetColor(ofColor::fromHsb(hue, 190, 200));
				ofFill();
				ofDrawRectangle(x, y, z, 2, 2);
			

			}
		}
	}
	cam.end();

}
