#pragma once
#include "ofMain.h"
#include "Astro.h"

class Asteroide {
public:
	ofVec2f posicao_, momento_;
	double massa_, raio_;
	ofColor cor;

	Asteroide(double massa, float raio, float px, float py, float mx, float my);
	void Update(ofVec2f posicao, double massa, double raio);
	void Draw();
};