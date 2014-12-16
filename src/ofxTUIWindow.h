#pragma once
#include <ofMain.h>
#include <ofxTUIType.h>
#include <ofxTUIFont.h>
#include <ofxTUIBaseWindow.h>
class ofxTUIWindow : public ofxTUIBaseWindow{
	public:
		ofxTUIWindow(const int& h, const int& w, const int& py = 0, const int& px = 0):ofxTUIBaseWindow(h,w,py,px){};
		virtual ~ofxTUIWindow(){};
		virtual void update(){};
		virtual void changedWindowSize(){};
		virtual void mouseMoved(const int& px, const int& py){};
		virtual void mouseDragged(const int& px, const int& py, const int& button){};
		virtual void mousePressed(const int& px, const int& py, const int& button){};
		virtual void mouseReleased(const int& px, const int& py, const int& button){};
};
