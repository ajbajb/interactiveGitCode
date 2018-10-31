#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	img.load("map01.png");
	// ofRectMode(OF_RECTMODE_CENTER);
	
	ofLog() << "image With/height = " << img.getWidth() << " / " << img.getHeight();

}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	// img.draw(0, 0);
	int width = 50;
	int height = 50;
	
	float inc = 4.5;
	degree += inc;
	
	for(int y = 0; y < img.getHeight(); y += width)
	{
		for (int x = 0; x < img.getWidth(); x += height)
		{
			int index = x + (y * img.getWidth());
		
			ofPushMatrix();
			ofTranslate(x + width/2, y + height/2);
			if(index == moveThis)
			{
				ofRotateZDeg(degree);
			}
				img.drawSubsection(0 - width/2, 0 - height/2, 50, 50, x, y);
				ofPopMatrix();
			
			
			if(degree > 90)
			{
				moveThis+=50;
				degree = 0;
			}
			
			 ofLog() << moveThis;
				
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
