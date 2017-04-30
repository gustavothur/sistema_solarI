#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	ofSetBackgroundColor(0, 0, 0);
	astro.push_back(new Astro(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), 100, 1000, 0, 255, 150, 0));
	astro.push_back(new Astro(ofVec2f(250, 250), 10, 100, 180, 102, 187, 174));
	astro.push_back(new Astro(ofVec2f(25, 25), 5, 10, 90, 185, 173, 173));

}

//--------------------------------------------------------------
void ofApp::update(){
	astro.at(1)->Update(astro.at(0));
	astro.at(2)->Update(astro.at(1));

	for (int i = 0; i < asteroide.size(); i++) {
		for (int j = 0; j < astro.size(); j++) {
			asteroide.at(i)->Update(astro.at(j)->posicao_, astro.at(j)->massa_, astro.at(j)->raio_);
		}
		for (int j = 0; j < asteroide.size(); j++) {
			if (i != j) {
				asteroide.at(i)->Update(asteroide.at(j)->posicao_, asteroide.at(j)->massa_, asteroide.at(j)->raio_);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < astro.size(); i++)
		astro.at(i)->Draw();
	for (int i = 0; i < asteroide.size(); i++)
		asteroide.at(i)->Draw();
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
	float massa = 1 + ofRandom(10);
	asteroide.push_back(new Asteroide(10 * massa, massa, x, y, 0, 0));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
