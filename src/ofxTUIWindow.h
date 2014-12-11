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
	public:
		ofxTUIWindow(const int h, const int w, const int y = 0, const int x = 0):
			subWindows(),
			fonts(),
			types(h, std::vector<ofxTUIType>(w)),
			posX(0),
			posY(0),
			posWindowX(x),
			posWindowY(y),
			height(h),
			width(w)
		{};
		virtual ~ofxTUIWindow(){};
		void addFont(const std::string fontName, int size){
			fonts[fontName] = ofxTUIFont();
			fonts[fontName].loadFont(fontName,size);
		};

		void setPos(const int x, const int y){
			if(0<x && x<width){posX = x;}
			if(0<y && y<height){posY = y;}
		};
		void addStr(const std::string str){
			types[posX][posY].str = str;
		};
		void clear(){};

		void refresh(){
			int y = 0;
			for (auto&& i : types) {
				int x = 0;
				for (auto&& j : i) {
					if(j.str != ""){
						int size = 12;//fonts[j.fontName].getSize();
						fonts[j.fontName].drawString(j.str, x*size*0.5+posWindowX, (y+1)*size+posWindowY);
					// std::cout<<j.str<<std::endl;
					}
					x++;
				}
				y++;
			}
		};
};
