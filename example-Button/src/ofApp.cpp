#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	win.addFont("fonts/Inconsolata.otf",10);
	win.loadColorScheme("defaultColorScheme.xml");
	win.fillAllBackground();

	win.setPos(0,0);
	win.setAllColor("None");

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

	button1.setPos(0,0);
	button1.addStr("ofxTUI   +");
	button1.setPos(1,0);
	button1.addStr("Button1");
	win.addSubWindow(button1,2,1);

	button2.setPos(0,0);
	button2.addStr("ofxTUI   +");
	button2.setPos(1,0);
	button2.addStr("Button2");
	win.addSubWindow(button2,5,1);
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
