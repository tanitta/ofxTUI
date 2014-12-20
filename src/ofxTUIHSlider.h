#pragma once
class ofxTUIHSlider : public ofxTUIWidget{
	private:
		float sliderPos;
		ofxTUIWindow knob;
		bool bPressed;
		bool bFillOver;
		bool bFillUnder;
	public:
		ofxTUIHSlider(const int& h, const int& w, const float& py = 0, const float& px = 0):ofxTUIWidget(h,w,py,px),sliderPos(0),knob(h,1),bPressed(false),bFillOver(false),bFillUnder(false){
			addSubWindow(knob);
		};
		virtual ~ofxTUIHSlider(){};

		float operator()(){
			return knob.x/((float)width-1.0);
		}

		float operator()(const float& v){
			if(0<=v&&v<=1){
				knob.x = v*((float)width-1.0);
			}else if(v<0){
				knob.x = 0;
			}else{
				knob.x = 1;
			}
			return knob.x/((float)width-1.0);
		}

		virtual void update(){};

		virtual void keyPressed(const int& key){};
		virtual void keyReleased(const int& key){};
		virtual void mouseMoved(const float& px, const float& py){};
		virtual void mouseDragged(const float& px, const float& py, const int& button){
			if(px>=0 && px<width-1 && bPressed){
				knob.x = px;
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
			knob.addStrRect("",0,0,height,1);
			setColor("Slider:Scale");
			addStrRect("",0,0,height,width);

			setColor("Slider:Fill");
			if(bFillUnder){
				addStrRect("",0,0,height,knob.x+1);
			}
			if(bFillOver){
				addStrRect("",0,(int)knob.x+1,height,width-(int)knob.x);
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
