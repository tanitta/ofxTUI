#pragma once
class ofxTUIVSlider : public ofxTUIWidget{
		float sliderPos;
		ofxTUIWindow knob;
		bool bPressed;
		bool bFillOver;
		bool bFillUnder;
	public:
		ofxTUIVSlider(const int& h, const int& w, const float& py = 0, const float& px = 0):ofxTUIWidget(h,w,py,px),sliderPos(0),knob(1,w),bPressed(false),bFillOver(false),bFillUnder(false){
			addSubWindow(knob);
			knob.y = ((float)height-1.0);
		};
		virtual ~ofxTUIVSlider(){};

		float operator()(){
			return 1.0-knob.y/((float)height-1.0);
		}

		float operator()(const float& v){
			if(0<=v&&v<=1){
				knob.y = (1-v)*((float)height-1.0);
			}else if(v<0){
				knob.y = 1;
			}else{
				knob.y = 0;
			}
			return knob.y/((float)height-1.0);
		}

		virtual void mouseDragged(const float& px, const float& py, const int& button){
			if(py>=0 && py<height-1 && bPressed){
				knob.y = py;
			}else if(py>=height-1 && bPressed){
				knob.y = height-1;
			}
		};

		virtual void mousePressed(const float& px, const float& py, const int& button){
			if(px>=0&&px<width&&py>=0&&py<height){
					bPressed = true;
			}
		};

		virtual void mouseReleased(const float& px, const float& py, const int& button){
			bPressed = false;
		};

		virtual void draw(){
			knob.setColor("Slider:Knob");
			knob.addStrRect("",0,0,1,width);
			setColor("Slider:Scale");
			addStrRect("",0,0,height,width);

			setColor("Slider:Fill");
			if(bFillUnder){
				addStrRect("", (int)knob.y+1, 0, height-(int)knob.y, width);
			}
			if(bFillOver){
				addStrRect("",0,0,knob.y+1,width);
			}
		};

		void EnableFillOver(){
			bFillOver = true;
		};

		void DisableFillOver(){
			bFillOver = false;
		};

		void EnableFillUnder(){
			bFillUnder= true;
		};

		void DisableFillUnder(){
			bFillUnder= false;
		};
};
