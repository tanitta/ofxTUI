#pragma once

#include "ofMain.h"
#include <ofxTUI.h>
class ofApp : public ofBaseApp{
		ofxTUIWindow win;
		ofxTUIHSlider hSlider1;
		ofxTUIHSlider hSlider2;
		ofxTUIHSlider hSlider3;

		ofxTUIVSlider vSlider1;
	public:
		ofApp():win(20,40),
		hSlider1(1,16),
		hSlider2(1,16),
		hSlider3(1,16),
		vSlider1(8,2)
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
