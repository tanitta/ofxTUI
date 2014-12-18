#pragma once
class ofxTUIWidget : public ofxTUIBaseWindow{
	public:
		ofxTUIWidget(const int& h, const int& w, const int& py = 0, const int& px = 0):ofxTUIBaseWindow(h,w,py,px){};
		virtual ~ofxTUIWidget(){};
};
