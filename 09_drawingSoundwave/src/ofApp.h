#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void audioOut(ofSoundBuffer & output);
    
        const double twopi = glm::two_pi<double>();
        ofSoundStream stream;
        int sampleRate;
    
        std::vector<float> lAudio;
        std::vector<float> rAudio;
    
        // ===for=synth========
        float frequency;
        float volume;
        float phase;
        float phaseAddr;
    
        bool bNoise = false;
};
