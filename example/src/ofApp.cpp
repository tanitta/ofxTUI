#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	win.addFont("fonts/Inconsolata.otf",10);
	win.setColorBackground(32,32,32);
	win.fillAllBackground();

	win.setColorBackground(32,32,32);
	win.setIsFill(true);
	win.setColorFont(128,128,128);
	win.addStrRect("-",1,0,1,30);
	win.addStrRect("-",10,0,1,30);

	win.setColorBackground(128,128,128);
	win.addStrRect("",0,0,1,30);
	win.setColorFont(255,255,255);
	win.setPos(0,1);
	win.addStr("ofxTUI - Test Window");

	win.setColorBackground(255,128,0);
	win.setColorFont(255,255,255);
	win.setPos(0,0);
	win.addStr("@");

	win1.addFont("fonts/Inconsolata.otf",10);
	win1.setColorBackground(16,16,16);
	win1.fillAllBackground();

	win.addSubWindow(win1,2,1);

	win2.addFont("fonts/Inconsolata.otf",10);
	win2.setColorBackground(16,16,16);
	win2.fillAllBackground();

	// win.addSubWindow(win2,11,1);

	win3.addFont("fonts/Inconsolata.otf",10);
	win3.setColorBackground(16,16,16);
	win3.setColorFont(255,255,255);
	win3.fillAllBackground();

	win.addSubWindow(win3,11,1);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	win.callDraw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	win.callKeyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	win.callKeyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	win.callMouseMoved(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	win.callMouseDragged(x,y,button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	win.callMousePressed(x,y,button);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	win.callMouseReleased(x,y,button);
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
