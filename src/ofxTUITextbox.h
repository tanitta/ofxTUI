#pragma once
class ofxTUITextbox : public ofxTUIWidget{
	bool bSelected;
	public:
	ofxTUITextbox(const int& h, const int& w, const float& py = 0, const float& px = 0):ofxTUIWidget(h,w,py,px),bSelected(false){};
	virtual ~ofxTUITextbox(){};

	virtual void keyPressed(const int& key){
		if(bSelected){
			// std::cout<<key<<std::endl;
			if(key==8){
				//backspace
				//8
				if(!(xCaret == width-1 && yCaret == height-1)){
					if(xCaret == 0){
						if(yCaret >  0){
							setPos(yCaret-1,width-1);
						}
					}else{
						setPos(yCaret,xCaret -1);
					}
					addStr("");
				}else{
					if(types[yCaret][xCaret].str == ""){
						if(xCaret == 0){
							if(yCaret >  0){
								setPos(yCaret-1,width-1);
							}
						}else{
							setPos(yCaret,xCaret -1);
						}
						addStr("");

					}else{
						addStr("");
					}

				}

				// }else if(key == 32){
				//space
				//32
		}else if(key == 13){

			//enter
			//13
		}else if(key == 4352){
			//tab
			//4352
		}else{

			//add
			char keys[] = {(char)key};
			setColorFont(255,255,255);
			setColorBackground(0,0,0);

			std::string strKeys=(std::string)keys;
			strKeys.resize(1);
			addStr(strKeys);
			// addStr("a");
			if(!(xCaret == width-1 && yCaret == height-1)){
				if(xCaret >= width-1){
					setPos(yCaret+1,0);
				}else{
					setPos(yCaret,xCaret+1);
				}
			}
		}
		// std::cout<<"x:"<<xCaret<<std::endl;
		// std::cout<<"y:"<<yCaret<<std::endl;
		}
	}

	virtual void mousePressed(const float& px, const float& py, const int& button){
		if(px>=0&&px<width&&py>=0&&py<height){
			bSelected = true;
		}else{
			bSelected = false;
		}
	};

	std::string operator()(){
		std::string str;
		for (auto&& i : types) {
			for (auto&& j : i) {
				str+=j.str;
			}
		}
		return str;
	};

	std::string operator()(const std::string& s){
		for (auto&& i : types) {
			for (auto&& j : i) {
				j.str = "";
			}
		}
		setPos(0,0);
		addStr(s);
		return s;
	};


};
