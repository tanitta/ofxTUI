#pragma once
#include <ofParameter.h>
class ofxTUIToggle : public ofxTUIWidget{
	bool bOnMouse;
	bool bClicked;
	bool bSwitch;
	public:
	ofxTUIToggle(const int& h, const int& w, const float& py = 0, const float& px = 0):ofxTUIWidget(h,w,py,px),bSwitch(false),bOnMouse(false),bClicked(false){};
	virtual ~ofxTUIToggle(){};

	virtual void mouseMoved(const float& px, const float& py){
		if(px>=0&&px<width&&py>=0&&py<height){
			bOnMouse = true;
		}else{
			bOnMouse = false;
			bClicked= false;
		}
	}

	virtual void mousePressed(const float& px, const float& py, const int& button){
		if(px>=0&&px<width&&py>=0&&py<height){
			bClicked = true;
		}
	};
	virtual void mouseDragged(const float& px, const float& py, const int& button){
		if(px>=0&&px<width&&py>=0&&py<height){
		}else{
			bClicked= false;
			bOnMouse = false;
		}
	};

	virtual void mouseReleased(const float& px, const float& py, const int& button){
		if(bClicked){
			if(px>=0&&px<width&&py>=0&&py<height){
				bSwitch = !bSwitch;
			}
		}
		bClicked = false;
	};

	virtual void draw(){

		if(bSwitch){
			setColor("Toggle:On");
			if(bOnMouse)setColor("Toggle:On:OnMouse");
			if(bClicked)setColor("Toggle:On:Clicked");
		}else{
			setColor("Toggle:Off");
			if(bOnMouse)setColor("Toggle:Off:OnMouse");
			if(bClicked)setColor("Toggle:Off:Clicked");
		}

		fillAllBackground();
		setAllColor();
	};

	bool operator()(){
		return bSwitch;
	};

	bool operator()(const bool& b){
		bSwitch = b;
		return bSwitch;
	};

};
