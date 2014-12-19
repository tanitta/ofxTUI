#pragma once
#include <ofxXmlSettings.h>
class ofxTUIColorScheme {
	private:
		ofxXmlSettings settings;
	public:
		ofxTUIColorScheme(){};
		virtual ~ofxTUIColorScheme(){};
		void loadFile(const std::string& str){
			std::string message;
			if(settings.loadFile(str)){
				message = str+" loaded!";
			}else{
				message = "unable to load "+str+" check data/ folder";
			};
			std::cout<<message<<std::endl;
		};
		ofColor getColor(const std::string& str){
			// std::cout<<settings.getValue(str,"")<<std::endl;
			ofColor color;
			int hex = std::stoi(settings.getValue(str,""), nullptr, 16);
			color.setHex(hex);
			return color;
		};
		void setColor(const std::string& str,ofColor color){};
};
