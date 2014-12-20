#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofTUI Init
	win.addFont("fonts/Inconsolata.otf",10);
	win.loadColorScheme("defaultColorScheme.xml");

	win.addSubWindow(toggle1,2,1);
	win.addSubWindow(toggle2,2,5);
	win.addSubWindow(toggle3,4,1);
	win.addSubWindow(toggle4,4,5);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	win.fillAllBackground();

	win.setPos(0,0);
	win.setColor("Frame");
	win.addStrRect("",0,0,1,40);
	win.setPos(0,39);
	win.addStr("+");

	win.setPos(0,0);
	win.setColor("Headline");
	win.addStr("#");
	win.setPos(0,1);
	win.setColor("Normal");
	win.addStr("ofxTUI-example");

	win.setPos(1,1);
	win.setColor("None");
	win.addStr("Toggle");

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
	win.callMouseDragged(x, y, button);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	win.callMousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	win.callMouseReleased(x, y, button);

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
