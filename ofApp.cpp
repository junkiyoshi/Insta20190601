#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto radius = 250;
	auto len = 30;
	int deg_start = ofGetFrameNum() * 3;
	vector<glm::vec3> vertices_1, vertices_2;
	for (int y = -200;  y <= 200; y += 50) {

		deg_start += 30;

		ofFill();
		ofSetColor(139);

		for (int deg = deg_start; deg <= deg_start + 120; deg++) {

			vertices_1.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), y + len * 0.5, radius * sin(deg * DEG_TO_RAD)));
			vertices_2.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), y + len * -0.5, radius * sin(deg * DEG_TO_RAD)));

			if (deg > deg_start) {

				ofBeginShape();
				ofVertex(glm::vec3(radius * cos(deg * DEG_TO_RAD), y + len * 0.5, radius * sin(deg * DEG_TO_RAD)));
				ofVertex(glm::vec3(radius * cos((deg - 1) * DEG_TO_RAD), y + len * 0.5, radius * sin((deg - 1) * DEG_TO_RAD)));
				ofVertex(glm::vec3(radius * cos((deg - 1) * DEG_TO_RAD), y + len * -0.5, radius * sin((deg - 1) * DEG_TO_RAD)));
				ofVertex(glm::vec3(radius * cos(deg * DEG_TO_RAD), y + len * -0.5, radius * sin(deg * DEG_TO_RAD)));
				ofEndShape(true);
			}
		}

		reverse(vertices_2.begin(), vertices_2.end());

		ofNoFill();
		ofSetColor(39);
		ofBeginShape();
		ofVertices(vertices_1);
		ofVertices(vertices_2);
		ofEndShape(true);

		vertices_1.clear();
		vertices_2.clear();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}