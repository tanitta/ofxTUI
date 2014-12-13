#pragma once
#include <iostream>
#include <ofMain.h>
class ofxTUIFont {
		ofTrueTypeFont font;
	public:
		ofxTUIFont(){};
		virtual ~ofxTUIFont(){};
		void loadFont(const std::string& fontName, const int& size){
			font.loadFont(fontName, size);
			font.setEncoding(OF_ENCODING_ISO_8859_15);
		}

		void drawString(const std::string& str, const int& x, const int& y){
			font.drawString(str,x, y);
		};

		int getSize(){
			return font.getSize();
		}

		int getLetterSpacing(){
			return font.getLetterSpacing();
		}

		float getSpaceSize(){
			return font.getSpaceSize();
		};

		float getLineHeight(){
			return font.getLineHeight();
		};
};
