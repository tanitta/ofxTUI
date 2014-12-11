#pragma once
#include <iostream>
#include <ofMain.h>
class ofxTUIFont {
		ofTrueTypeFont font;
	public:
		ofxTUIFont(){};
		virtual ~ofxTUIFont(){};
		void loadFont(const std::string fontName, int size){
			font.loadFont(fontName, size);
		}

		void drawString(const std::string str, int x, int y){
			font.drawString(str,x, y);
		};

		int getSize(){
			return font.getSize();
		}
};
