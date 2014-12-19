#pragma once
class ofxTUIWidget : public ofxTUIBaseWindow{
	public:
		ofxTUIWidget(const int& h, const int& w, const int& py = 0, const int& px = 0):ofxTUIBaseWindow(h,w,py,px){};
		virtual ~ofxTUIWidget(){};

		virtual void update(){};
		virtual void draw(){};

		virtual void keyPressed(const int& key){};
		virtual void keyReleased(const int& key){};
		virtual void mouseMoved(const float& px, const float& py){};
		virtual void mouseDragged(const float& px, const float& py, const int& button){};
		virtual void mousePressed(const float& px, const float& py, const int& button){};
		virtual void mouseReleased(const float& px, const float& py, const int& button){};
};
