#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	win.addFont("fonts/Inconsolata.otf",10);

	win.setColorBackground(32,32,32);
	win.fillAllBackground();

	win.setColorBackground(64,64,64);
	for (int i = 0; i < 40; i++) {
		win.setPos(0,i);
		win.addStr("");
	}
	win.setColorFont(255,128,0);
	win.setPos(0,0);
	win.addStr("@ofxTUI - imaginary editor");
	for (int i = 1; i < 40; i++) {
	win.setColorBackground(64,64,64);
		win.setColorFont(255,255,255);
		win.setPos(i,1);
		win.addStr("");
		win.setPos(i,2);
		win.addStr("");
		win.setPos(i,0);
		win.addStr(std::to_string(i-1));

		win.setPos(i,3);
		win.setColorBackground(32,32,32);
		win.setColorFont(64,64,64);
		win.addStr("_");

	}
	win.setColorBackground(32,32,32);
	win.setColorFont(255,255,255);
	win.setPos(1,3);
	win.addStr("#include <ofMain.h>");
	win.setIsFill(true);
	win.addStrRect("*",2,3,3,3);


	ofxTUIWindow win2(9,30);
	win2.addFont("fonts/Inconsolata.otf",10);

	win2.setColorBackground(32,32,32);
	win2.fillAllBackground();

	win2.setColorBackground(64,64,64);
	for (int i = 0; i < 30; i++) {
		win2.setPos(0,i);
		win2.addStr("");
	}
	win2.setColorBackground(255,128,0);
	win2.setColorFont(255,255,255);
	win2.setPos(0,0);
	win2.addStr("@");

	win2.setColorBackground(64,64,64);
	win2.setPos(0,1);
	win2.setColorFont(255,255,255);
	win2.addStr("ofxTUI - imaginary editor");
	for (int i = 1; i < 9; i++) {
	win2.setColorBackground(64,64,64);
		win2.setColorFont(255,255,255);
		win2.setPos(i,1);
		win2.addStr("");
		win2.setPos(i,2);
		win2.addStr("");
		win2.setPos(i,0);
		win2.addStr(std::to_string(i-1));

		win2.setPos(i,3);
		win2.setColorBackground(32,32,32);
		win2.setColorFont(64,64,64);
		win2.addStr("_");

	}
	win2.setColorBackground(32,32,32);
	win2.setColorFont(255,255,255);
	win2.setPos(1,3);
	win2.addStr("ABCDEFGHIJKLMNOP");
	win2.setPos(2,3);
	win2.addStr("QRSTUVWXYZ");
	win2.setPos(3,3);
	win2.addStr("abcdefghijklmnop");
	win2.setPos(4,3);
	win2.addStr("qrstuvwxyz");

	win2.setPos(8,29);
	win2.setColorBackground(64,64,64);
	win2.addStr("+");
	// win.setPos(1,0);
	// win.addStr("|");
	// win.setPos(2,0);
	// win.addStr("|");
	// win.setPos(3,0);
	// win.addStr("|");

	win.addSubWindow(win2,3,20);
	//
	//
	// ofTrueTypeFont test;
	// test.loadFont("fonts/Inconsolata.otf",12);
	// test.drawString("a",0,0);
	// std::cout<<test.getLineHeight()<<std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	win.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
