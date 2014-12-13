#pragma once
class ofxTUIType {
	public:
		ofColor colorBackground;
		ofColor colorFont;
		std::string str;
		std::string fontName;
		ofxTUIType():fontName("fonts/Inconsolata.otf"){};
		virtual ~ofxTUIType(){};
};
