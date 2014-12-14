#pragma once
#include <iostream>
#include <ofMain.h>
class ofxTUIFont : public ofTrueTypeFont{
		ofTrueTypeFont font;
	public:
		ofxTUIFont(){};
		virtual ~ofxTUIFont(){};
		// void loadFont(const std::string& fontName, const int& size){
		// 	font.loadFont(fontName, size);
		// 	font.setEncoding(OF_ENCODING_ISO_8859_15);
		// }
		//
		// void drawString(const std::string& str, const int& x, const int& y){
		// 	font.drawString(str,x, y);
		// };
		//
		// int getSize(){
		// 	return font.getSize();
		// }
		//
		// int getLetterSpacing(){
		// 	return font.getLetterSpacing();
		// }
		//
		// float getSpaceSize(){
		// 	return font.getSpaceSize();
		// };
		//
		// float getLineHeight(){
		// 	return font.getLineHeight();
		// };
		// float getDescenderHeight(){
		// 	return font.getDescenderHeight();
		// }

		int getTextBoxWidth(){
			return int((float)getSize()*2.0/3.0+0.5);
		}

		int getTextBoxHeight(){
			return int(getLineHeight()+0.5);
		}
};
