#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	win.addFont("fonts/Inconsolata.otf",10);
	win.setColorFont(255,255,255);
	win.setColorBackground(0,0,0);
	win.fillAllBackground();
	win.setPos(0,0);
	// win.addStr("ofxTUI");

	button.addFont("fonts/Inconsolata.otf",10);
	win.addSubWindow(button);
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

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	win.callMouseMoved(x, y);

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	win.callMousePressed(x, y, button);
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
