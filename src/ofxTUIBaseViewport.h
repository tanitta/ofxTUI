#pragma once
#include <ofxTUIBaseWindow.h>

class ofxTUIBaseViewport : public ofxTUIBaseWindow{
	public:
		ofxTUIBaseViewport(const int& h, const int& w, const int& py = 0, const int& px = 0):ofxTUIBaseWindow(h,w,py,px){};
		virtual ~ofxTUIBaseViewport(){};

		virtual void update(){};
		virtual void draw(){};
		virtual void changedWindowSize(){};
		virtual void keyPressed(const int& key){};
		virtual void keyReleased(const int& key){};
		virtual void mouseMoved(const int& px, const int& py){};
		virtual void mouseDragged(const int& px, const int& py, const int& button){};
		virtual void mousePressed(const int& px, const int& py, const int& button){};
		virtual void mouseReleased(const int& px, const int& py, const int& button){};

		void callDraw(){
			//update
			update();
			for (auto&& i : subWindow_ptrs) {
				i->update();
			}

			//draw
			ofPushView();
			ofViewport(0,0,width*baseFont.getTextBoxWidth(), height*baseFont.getTextBoxHeight());
			ofSetupScreen();

			draw();

			ofPopView();

			// subWindowsの描画
			for (auto&& i : subWindow_ptrs) {
				ofPushMatrix();
				ofTranslate(i->x * baseFont.getTextBoxWidth(),i->y * baseFont.getTextBoxHeight());
				i->callDraw();
				ofPopMatrix();
			}
		};
};
