#pragma once

#include "ofMain.h"
#include <ofxTUI.h>
class ofApp : public ofBaseApp{
		ofxTUIWindow win;
		ofxTUIToggle toggle1;
		ofxTUIToggle toggle2;
		ofxTUIToggle toggle3;
		ofxTUIToggle toggle4;
	public:
		ofApp():win(20,40),
		toggle1(1,2),
		toggle2(1,2),
		toggle3(1,2),
		toggle4(1,2)
	{}
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
