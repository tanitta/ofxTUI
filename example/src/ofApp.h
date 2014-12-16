#pragma once

#include "ofMain.h"
#include <ofxTUI.h>
#include <testWindow.h>
class ofApp : public ofBaseApp{
	private:
		ofxTUIWindow win;
	ofxTUIWindow win1;
	ofxTUIWindow win2;
	testWindow win3;
	public:
		ofApp():win(30,30),win1(8,28),win2(8,28),win3(8,28){};
		virtual ~ofApp(){};
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
