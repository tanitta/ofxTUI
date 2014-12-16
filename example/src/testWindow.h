#pragma once
#include <ofxTUI.h>
class testWindow : public ofxTUIBaseWindow{
	public:
		testWindow(const int& h, const int& w, const int& py = 0, const int& px = 0):ofxTUIBaseWindow(h,w,py,px){};
		virtual ~testWindow(){};
		virtual void update(){};
		virtual void changedWindowSize(){};
		virtual void mouseMoved(const int& px, const int& py){
			setPos(py,px);
			addStr("a");
		};
};
