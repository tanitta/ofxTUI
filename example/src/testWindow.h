#pragma once
#include <ofxTUI.h>
class testWindow : public ofxTUIBaseWindow{
	int mouseX;
	int mouseY;
	public:
		testWindow(const int& h, const int& w, const int& py = 0, const int& px = 0):ofxTUIBaseWindow(h,w,py,px),mouseX(0),mouseY(0){};
		virtual ~testWindow(){};

		virtual void update(){};
		virtual void draw(){};
		virtual void changedWindowSize(){};
		virtual void keyPressed(const int& key){};
		virtual void keyReleased(const int& key){
			char keys[] = {(char)key};
			// std::cout<<(char)key<<std::endl;
			setPos(mouseY,mouseX);
			addStr((std::string)keys);
		};

		virtual void mouseMoved(const int& px, const int& py){
			mouseX = px;
			mouseY = py;
		};

		virtual void mouseDragged(const int& px, const int& py, const int& button){
		};

		virtual void mousePressed(const int& px, const int& py, const int& button){};
		virtual void mouseReleased(const int& px, const int& py, const int& button){};
};
