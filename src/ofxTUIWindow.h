#pragma once
#include <ofMain.h>
#include <ofxTUIType.h>
#include <ofxTUIFont.h>
#include <ofxTUIBaseWindow.h>
class ofxTUIWindow : public ofxTUIBaseWindow{
	public:
		ofxTUIWindow(const int& h, const int& w, const float& py = 0, const float& px = 0):ofxTUIBaseWindow(h,w,py,px){};
		virtual ~ofxTUIWindow(){};

		virtual void update(){};
		virtual void draw(){};
		virtual void changedWindowSize(){};
		virtual void keyPressed(const int& key){};
		virtual void keyReleased(const int& key){};
		virtual void mouseMoved(const float& px, const float& py){};
		virtual void mouseDragged(const float& px, const float& py, const int& button){};
		virtual void mousePressed(const float& px, const float& py, const int& button){};
		virtual void mouseReleased(const float& px, const float& py, const int& button){};
};
