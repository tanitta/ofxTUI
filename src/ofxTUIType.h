#pragma once
class ofxTUIType {
	public:
		ofColor colorBackground;
		ofColor colorFont;
		std::string str;
		std::string fontName;
		ofxTUIType():fontName("fonts/Inconsolata.otf"),colorFont(255,255,255),colorBackground(0,0,0){};
		virtual ~ofxTUIType(){};
};
