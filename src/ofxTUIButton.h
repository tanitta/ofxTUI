#pragma once
class ofxTUIButton : public ofxTUIWidget{
	bool bSwitch;
	bool bOnMouse;
	int mouseX;
	int mouseY;
	bool val;
	ofEvent<void> triggerEvent;
	public:
	ofxTUIButton(const int& h, const int& w, const float& py = 0, const float& px = 0):ofxTUIWidget(h,w,py,px),bSwitch(false),bOnMouse(false),mouseX(0),mouseY(0),val(false){};
	virtual ~ofxTUIButton(){};

	virtual void mouseMoved(const float& px, const float& py){
		if(px>=0&&px<width&&py>=0&&py<height){
			bOnMouse = true;
		}else{
			bOnMouse = false;
			bSwitch = false;
		}
	}

	virtual void mousePressed(const float& px, const float& py, const int& button){
		if(px>=0&&px<width&&py>=0&&py<height){
			bSwitch = true;
		}
	};
	virtual void mouseDragged(const float& px, const float& py, const int& button){
		if(px>=0&&px<width&&py>=0&&py<height){
		}else{
			bSwitch = false;
			bOnMouse = false;
		}
	};

	virtual void mouseReleased(const float& px, const float& py, const int& button){
		if(bSwitch){
			if(px>=0&&px<width&&py>=0&&py<height){
				val = true;
				ofNotifyEvent(triggerEvent);
			}
		}
		bSwitch = false;
	};

	virtual void update(){
	};

	virtual void draw(){
		if(bOnMouse){
			setColor("Button:OnMouse");
		}else{
			setColor("Button:NoOnMouse");
		}

		if(bSwitch){
			setColor("Button:Clicked");
		}
		fillAllBackground();
		setAllColor();
		val = false;
	};

	bool operator()(){
		return val;
	};
	template<class ListenerClass, typename ListenerMethod>
		void addListener(ListenerClass * listener, ListenerMethod method){
			ofAddListener(triggerEvent,listener,method);
		}
	template<class ListenerClass, typename ListenerMethod>
		void removeListener(ListenerClass * listener, ListenerMethod method){
			ofRemoveListener(triggerEvent,listener,method);
		}
};
