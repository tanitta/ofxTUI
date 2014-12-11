#pragma once
class ofxTUIType {
	public:
		ofColor bg;
		ofColor fg;
		std::string str;
		std::string fontName;
		ofxTUIType():fontName("fonts/Inconsolata.otf"){};
		virtual ~ofxTUIType(){};
};
