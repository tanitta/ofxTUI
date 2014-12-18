#pragma once

#include "ofMain.h"
#include <ofxTUI.h>
class ofApp : public ofBaseApp{
		ofxTUIWindow win;
		ofxTUIButton button;
	public:
		ofApp():win(20,20), button(1,10){}
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

};