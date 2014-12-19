#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	win.addFont("fonts/Inconsolata.otf",10);
	win.loadColorScheme("defaultColorScheme.xml");

	// hSlider1.EnableFillOver();
	hSlider1.EnableFillUnder();
	win.addSubWindow(hSlider1,2,1);

	hSlider2.EnableFillUnder();
	win.addSubWindow(hSlider2,4,1);

	hSlider3.EnableFillUnder();
	win.addSubWindow(hSlider3,6,1);
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

	win.setColor("None");
	win.setPos(1,1);
	win.addStr("HSlider1 :");
	win.setPos(3,1);
	win.addStr("HSlider2 :");
	win.setPos(5,1);
	win.addStr("HSlider3 :");
	win.setPos(1,12);
	win.addStr(std::to_string(hSlider1()*100));
	win.setPos(3,12);
	win.addStr(std::to_string(hSlider2()*100));
	win.setPos(5,12);
	win.addStr(std::to_string(hSlider3()*100));

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
