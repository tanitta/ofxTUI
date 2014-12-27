#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofTUI Init
	win.addFont("fonts/Inconsolata.otf",10);
	win.loadColorScheme("defaultColorScheme.xml");

	win.addSubWindow(textbox,1,0);
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

	textbox("hoge");

	win.callDraw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	win.callKeyPressed(key);

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
