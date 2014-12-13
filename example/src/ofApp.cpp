#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	win.addFont("fonts/Inconsolata.otf",12);
	win.setColorFont(128,0,0);
	win.setPos(0,1);
	win.addStr("_");
	win.setPos(1,1);
	win.addStr("_");
	win.setPos(2,1);
	win.addStr("_");
	win.setPos(3,1);
	win.addStr("_");
	win.setPos(4,1);
	win.addStr("_");
	win.setPos(5,1);
	win.addStr("_");
	win.setColorFont(0,128,0);
	win.setPos(0,0);
	win.addStr("_\n_\n_\n_\n_\n_");

	ofTrueTypeFont test;
	test.loadFont("fonts/Inconsolata.otf",12);
	std::cout<<test.getLineHeight()<<std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	win.refresh();
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
