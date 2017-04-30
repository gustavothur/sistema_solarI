#pragma once
#include "ofMain.h"

class Astro {

public:
	ofVec2f posicao_, posInicial_;
	float raio_;
	double massa_, periodo_;
	ofColor cor;

	Astro(ofVec2f posicao, float raio, double massa, double periodo, int r, int g, int b);
	void Update(Astro* astro);
	void Draw();
	
};
