#pragma once
#include <ofMain.h>
#include <ofxTUIType.h>
#include <ofxTUIFont.h>
class ofxTUIBaseWindow{
	protected:
		std::vector<ofxTUIBaseWindow> subWindows;
		std::map<std::string, ofxTUIFont> fonts;
		ofxTUIFont baseFont;
		std::vector<std::vector<ofxTUIType>> types;

		int x;
		int y;
		int height;
		int width;
		ofColor colorFont;
		int alphaFont;
		ofColor colorBackground;
		int alphaBackground;

	public:
		ofxTUIBaseWindow(const int& h, const int& w, const int& py = 0, const int& px = 0):
			subWindows(),
			fonts(),
			baseFont(),
			types(h, std::vector<ofxTUIType>(w)),
			x(px),
			y(py),
			height(h),
			width(w),
			colorFont(255,255,255),
			alphaFont(255),
			colorBackground(0,0,0),
			alphaBackground(255)
		{};

		virtual ~ofxTUIBaseWindow(){};

		void setWindowSize(const int& w, const int& h){
			if(width != w || height != h){
			width = w;
			height = h;
			// changedWindowSize();
			}
		}

		virtual void changedWindowSize(){};

		void addSubWindow(ofxTUIBaseWindow& window){
			subWindows.push_back(window);
		};
		void addSubWindow(ofxTUIBaseWindow& window,const int& y,const int& x){
			window.x = x;
			window.y = y;
			subWindows.push_back(window);
		};

		void addFont(const std::string& fontName, const int& size){
			fonts[fontName] = ofxTUIFont();
			fonts[fontName].loadFont(fontName,size);
			if (!baseFont.isLoaded()) {
				setBaseFont(fontName, size);
			}
		};

		void setBaseFont(const std::string& fontName, const int& size){
			baseFont.loadFont(fontName, size);
		}

		void setPos(const int& y_, const int& x_){
			if(0<=x_ && x_<width){x = x_;}
			if(0<=y_ && y_<height){y = y_;}
		};
		void addStr(const std::string& str){
			types[y][x].colorFont = colorFont;
			types[y][x].colorBackground = colorBackground;
			if(str.length() <= 1){
			types[y][x].str = str;
			}else{
				for(int i = 0; i<(int)str.length(); i++){
					types[y][x+i].str = str[i];
				}
			}
		};

		void addAllBackground(){
			for (auto&& i : types) {
				for (auto&& j : i) {
					j.colorBackground = colorBackground;
				}
			}
		};
		void addAllBackground(const ofColor& color){
			for (auto&& i : types) {
				for (auto&& j : i) {
					j.colorBackground = color;
				}
			}
		};
		// void drawLine

		void setColorFont(const ofColor& color){
			colorFont = color;
		};

		void setColorFont(const int& r, const int& g, const int& b){
			colorFont = ofColor(r, g, b);
		};

		void setColorBackground(const ofColor& color){
			colorBackground = color;
		};

		void setColorBackground(const int& r, const int& g, const int& b){
			colorBackground = ofColor(r, g, b);
		};

		void clear(){};

		virtual void update(){};

		void draw(){
			update();
			int iy = 0;
			for (auto&& i : types) {
				int ix = 0;
				for (auto&& j : i) {
					int size = fonts[j.fontName].getSize();
					int w = fonts[j.fontName].getTextBoxWidth();
					int h = fonts[j.fontName].getTextBoxHeight();
					int xoffset = ix*int((float)size*2.0/3.0+0.5);
					int yoffset = (iy)*int(fonts[j.fontName].getLineHeight()+0.5);

					ofSetColor(j.colorBackground);
					ofRect(xoffset,yoffset,w,h);

					ofSetColor(j.colorFont);
					fonts[j.fontName].drawString(j.str, xoffset, 1*(float)h+h*(iy)+fonts[j.fontName].getDescenderHeight());
					ix++;
				}
				iy++;
			}
			// subWindowsの描画
			for (auto&& i : subWindows) {
				ofPushMatrix();
				ofTranslate(i.x * i.baseFont.getTextBoxWidth(),i.y * i.baseFont.getTextBoxHeight());
				i.draw();
				ofPopMatrix();
			}
		};
};
