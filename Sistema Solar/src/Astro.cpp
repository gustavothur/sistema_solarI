#include "Astro.h"

Astro::Astro(ofVec2f posicao, float raio, double massa, double periodo, int r, int g, int b) {
	posicao_ = posicao;
	posInicial_ = posicao;
	raio_ = raio;
	massa_ = massa;
	periodo_ = 360 / periodo;
	cor.set(r, g, b);
}

void Astro::Update(Astro * astro)
{
	posInicial_.rotate(periodo_);
	posicao_ = posInicial_;
	posicao_ += astro -> posicao_;
}

void Astro::Draw() {
	ofPushMatrix();
	ofTranslate(posicao_);
	ofSetColor(cor);
	ofFill();
	ofDrawCircle(0, 0, raio_);
	ofPopMatrix();
}
