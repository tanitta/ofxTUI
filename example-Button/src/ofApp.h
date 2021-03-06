#pragma once

#include "ofMain.h"
#include <ofxTUI.h>
class ofApp : public ofBaseApp{
		ofxTUIWindow win;
		ofxTUIButton button1;
		ofxTUIButton button2;
	public:
		ofApp():win(20,40), button1(2,10), button2(2,10){}
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
