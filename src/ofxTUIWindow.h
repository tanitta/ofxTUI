#pragma once
#include <ofMain.h>
#include <ofxTUIType.h>
#include <ofxTUIFont.h>
class ofxTUIWindow{
	private:
		std::vector<ofxTUIWindow> subWindows;
		std::map<std::string, ofxTUIFont> fonts;
		std::vector<std::vector<ofxTUIType>> types;
		int posX;
		int posY;
		int posWindowX;
		int posWindowY;
		int height;
		int width;
		ofColor colorFont;
		int alphaFont;
		ofColor colorBackground;
		int alphaBackground;

	public:
		ofxTUIWindow(const int& h, const int& w, const int& y = 0, const int& x = 0):
			subWindows(),
			fonts(),
			types(h, std::vector<ofxTUIType>(w)),
			posX(0),
			posY(0),
			posWindowX(x),
			posWindowY(y),
			height(h),
			width(w),
			colorFont(),
			alphaFont(255),
			colorBackground(),
			alphaBackground(255)
		{};

		virtual ~ofxTUIWindow(){};
		void addFont(const std::string& fontName, const int& size){
			fonts[fontName] = ofxTUIFont();
			fonts[fontName].loadFont(fontName,size);
		};

		void setPos(const int& x, const int& y){
			if(0<=x && x<width){posX = x;}
			if(0<=y && y<height){posY = y;}
		};
		void addStr(const std::string& str){
			types[posX][posY].str = str;
			types[posX][posY].colorFont = colorFont;
			types[posX][posY].colorBackground = colorBackground;
		};

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

		void refresh(){
			int y = 0;
			for (auto&& i : types) {
				int x = 0;
				for (auto&& j : i) {
					if(j.str != ""){
						ofSetColor(j.colorFont);
						int size = fonts[j.fontName].getSize();
						int xoffset = x*int((float)size*2.0/3.0+0.5);
						int yoffset = (y+1)*int(fonts[j.fontName].getLineHeight()+0.5);
						// fonts[j.fontName].drawString(j.str, xoffset+posWindowX, (y+1)*18+posWindowY);
						fonts[j.fontName].drawString(j.str, xoffset+posWindowX, yoffset+posWindowY);
						// fonts[j.fontName].drawString(j.str, xoffset+posWindowX, yoffset+posWindowY);
						// std::cout<<fonts[j.fontName].getSpaceSize()<<std::endl;
					}
					x++;
				}
				y++;
			}
		};
};
