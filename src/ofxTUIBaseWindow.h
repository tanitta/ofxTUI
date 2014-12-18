#pragma once
#include <ofMain.h>
#include <ofxTUIType.h>
#include <ofxTUIFont.h>
class ofxTUIBaseWindow{
	protected:
		std::vector<ofxTUIBaseWindow*> subWindow_ptrs;
		std::map<std::string, ofxTUIFont> fonts;
		ofxTUIFont baseFont;
		std::vector<std::vector<ofxTUIType>> types;


		int xCaret;
		int yCaret;

		ofColor colorFont;
		int alphaFont;
		ofColor colorBackground;
		int alphaBackground;

		bool bFill;

	public:
		int x;
		int y;
		int height;
		int width;

		ofxTUIBaseWindow(const int& h, const int& w, const int& py = 0, const int& px = 0):
			subWindow_ptrs(),
			fonts(),
			baseFont(),
			types(h, std::vector<ofxTUIType>(w)),
			x(px),
			y(py),
			xCaret(0),
			yCaret(0),
			height(h),
			width(w),
			colorFont(255,255,255),
			alphaFont(255),
			colorBackground(0,0,0),
			alphaBackground(255),
			bFill(false)
		{};

		virtual ~ofxTUIBaseWindow(){};

		void setWindowSize(const int& w, const int& h){
			if(width != w || height != h){
			width = w;
			height = h;
			// changedWindowSize();
			}
		}

		virtual void changedWindowSize(){};

		void addSubWindow(ofxTUIBaseWindow& window){
			subWindow_ptrs.push_back(&window);
		};
		void addSubWindow(ofxTUIBaseWindow& window,const int& y,const int& x){
			window.x = x;
			window.y = y;
			subWindow_ptrs.push_back(&window);
		};

		void addFont(const std::string& fontName, const int& size){
			fonts[fontName] = ofxTUIFont();
			fonts[fontName].loadFont(fontName,size);
			if (!baseFont.isLoaded()) {
				setBaseFont(fontName, size);
			}
		};

		void setBaseFont(const std::string& fontName, const int& size){
			baseFont.loadFont(fontName, size);
		}

		void setIsFill(const bool& b){
			bFill = b;
		}
		bool IsFill()const{
			return bFill;
		}

		void setPos(const int& y_, const int& x_){
			if(0<=x_ && x_<width){xCaret = x_;}
			if(0<=y_ && y_<height){yCaret = y_;}
		};

		void addStr(const std::string& str){
			if((0<=xCaret && xCaret<width)&&(0<=yCaret && yCaret<height)){
				types[yCaret][xCaret].colorFont = colorFont;
				types[yCaret][xCaret].colorBackground = colorBackground;
				if(str.length() <= 1){
					types[yCaret][xCaret].str = str;
				}else{
					for(int i = 0; i<(int)str.length()&&x+i<width; i++){
						types[yCaret][xCaret+i].colorFont = colorFont;
						types[yCaret][xCaret+i].colorBackground = colorBackground;
						types[yCaret][xCaret+i].str = str[i];
					}
				}
			}
		};

		void addStrRect(const std::string& str, const int& py, const int& px, const int& h, const int& w){
			if(bFill){
				for(int i = 0; i<h; i++){
					for(int j = 0; j<w; j++){
						setPos(i+py,j+px);
						addStr(str);
					}
				}
			}else{
				if(h == 1){
					for(int i = 0; i<w; i++){
						setPos(py, i+px);
						addStr(str);
					}
				}else if(w == 1){
					for(int i = 0; i<h; i++){
						setPos(i+py, px);
						addStr(str);
					}

				}else{
					for(int i = 0; i<h; i++){
						if(i == 0||i==h-1){
							for(int j = 0; j<w; j++){
								setPos(i+py,j+px);
								addStr(str);
							}
						}else{
							setPos(i+py,px);
							addStr(str);
							setPos(i+py,px+w-1);
							addStr(str);
						}
					}
				}

			}
		};

		void fillAllBackground(){
			for (auto&& i : types) {
				for (auto&& j : i) {
					j.colorBackground = colorBackground;
				}
			}
		};
		void addAllBackground(const ofColor& color){
			for (auto&& i : types) {
				for (auto&& j : i) {
					j.colorBackground = color;
				}
			}
		};
		// void drawLine

		void setColorFont(const ofColor& color){
			colorFont = color;
		};

		void setColorFont(const int& r, const int& g, const int& b){
			colorFont = ofColor(r, g, b);
		};

		void setColorBackground(const ofColor& color){
			colorBackground = color;
		};

		void setColorBackground(const int& r, const int& g, const int& b){
			colorBackground = ofColor(r, g, b);
		};


		void clear(){};

		virtual void update(){};
		virtual void draw(){};

		virtual void keyPressed(const int& key){};
		virtual void keyReleased(const int& key){};
		virtual void mouseMoved(const int& px, const int& py){};
		virtual void mouseDragged(const int& px, const int& py, const int& button){};
		virtual void mousePressed(const int& px, const int& py, const int& button){};
		virtual void mouseReleased(const int& px, const int& py, const int& button){};

		void callKeyPressed(const int& key){
			keyPressed(key);
			for (auto&& i : subWindow_ptrs) {
				i->callKeyPressed(key);
			}
		};

		void callKeyReleased(const int& key){
			keyReleased(key);
			for (auto&& i : subWindow_ptrs) {
				i->callKeyReleased(key);
			}
		};

		void callMouseMoved(const int& px, const int& py){
			int xType = px/baseFont.getTextBoxWidth();
			int yType = py/baseFont.getTextBoxHeight();
			// if(0<=xType&&xType<width&&0<=yType&&yType<height){
				mouseMoved(xType,yType);
			// }
			// subWindows
			for (auto&& i : subWindow_ptrs) {

				int xSub = (px - i->x * baseFont.getTextBoxWidth());
				int ySub = (py - i->y * baseFont.getTextBoxHeight());
				i->callMouseMoved(xSub, ySub);
			}

		}

		void callMouseDragged(const int& px, const int& py, const int& button){
			int xType = px/baseFont.getTextBoxWidth();
			int yType = py/baseFont.getTextBoxHeight();
			// if(0<=xType&&xType<width&&0<=yType&&yType<height){
				mouseDragged(xType, yType, button);
			// }
			// subWindows
			for (auto&& i : subWindow_ptrs) {

				int xSub = (px - i->x * baseFont.getTextBoxWidth());
				int ySub = (py - i->y * baseFont.getTextBoxHeight());
				i->callMouseDragged(xSub, ySub, button);
			}

		}

		void callMousePressed(const int& px, const int& py, const int& button){
			int xType = px/baseFont.getTextBoxWidth();
			int yType = py/baseFont.getTextBoxHeight();
			// if(0<=xType&&xType<width&&0<=yType&&yType<height){
				mousePressed(xType, yType, button);
			// }
			// subWindows
			for (auto&& i : subWindow_ptrs) {

				int xSub = (px - i->x * baseFont.getTextBoxWidth());
				int ySub = (py - i->y * baseFont.getTextBoxHeight());
				i->callMousePressed(xSub, ySub, button);
			}

		}

		void callMouseReleased(const int& px, const int& py, const int& button){
			int xType = px/baseFont.getTextBoxWidth();
			int yType = py/baseFont.getTextBoxHeight();
			// if(0<=xType&&xType<width&&0<=yType&&yType<height){
				mouseReleased(xType, yType, button);
			// }
			// subWindows
			for (auto&& i : subWindow_ptrs) {

				int xSub = (px - i->x * baseFont.getTextBoxWidth());
				int ySub = (py - i->y * baseFont.getTextBoxHeight());
				i->callMouseReleased(xSub, ySub, button);
			}

		}

		void callDraw(){
			//update
			update();
			for (auto&& i : subWindow_ptrs) {
				i->update();
			}

			//draw
			draw();
			int iy = 0;
			for (auto&& i : types) {
				int ix = 0;
				for (auto&& j : i) {
					int size = fonts[j.fontName].getSize();
					int w = fonts[j.fontName].getTextBoxWidth();
					int h = fonts[j.fontName].getTextBoxHeight();
					int xoffset = ix*int((float)size*2.0/3.0+0.5);
					int yoffset = (iy)*int(fonts[j.fontName].getLineHeight()+0.5);

					ofSetColor(j.colorBackground);
					ofRect(xoffset,yoffset,w,h);

					ofSetColor(j.colorFont);
					fonts[j.fontName].drawString(j.str, xoffset, 1*(float)h+h*(iy)+fonts[j.fontName].getDescenderHeight());
					ix++;
				}
				iy++;
			}
			// subWindowsの描画
			for (auto&& i : subWindow_ptrs) {
				ofPushMatrix();
				ofTranslate(i->x * baseFont.getTextBoxWidth(),i->y * baseFont.getTextBoxHeight());
				i->callDraw();
				ofPopMatrix();
			}
		};
};
