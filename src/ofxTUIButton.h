#pragma once
class ofxTUIButton : public ofxTUIWidget{
	bool bSwitch;
	bool bOnMouse;
	int mouseX;
	int mouseY;
	public:
		ofxTUIButton(const int& h, const int& w, const int& py = 0, const int& px = 0):ofxTUIWidget(h,w,py,px),bSwitch(false),bOnMouse(false),mouseX(0),mouseY(0){};
		virtual ~ofxTUIButton(){};

		virtual void mouseMoved(const int& px, const int& py){
			if(px>=0&&px<=width&&py==0){
				bOnMouse = true;
			}else{
				bOnMouse = false;
			}
		}

		virtual void mouseReleased(const int& px, const int& py, const int& button){
			if(px>=0&&px<=width&&py==0){
				bSwitch = true;
			}else{
				bSwitch = false;
			}
		};

		virtual void update(){
			std::cout<<bOnMouse<<std::endl;
		};

		virtual void draw(){
			if(bOnMouse){
				setColorFont(64,64,64);
				setColorBackground(128,128,128);
			}else{
				setColorFont(255,255,255);
				setColorBackground(64,64,64);
			}
			addStr("ofxTUIButton");
		};
};
