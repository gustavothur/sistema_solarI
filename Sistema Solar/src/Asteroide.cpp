#include "Asteroide.h"

Asteroide::Asteroide(double massa, float raio, float px, float py, float mx, float my)
{
	massa_ = massa;
	raio_ = raio;
	posicao_.set(px, py);
	momento_.set(mx, my);
	cor.set(100 + ofRandom(156), 100 + ofRandom(156), 100 + ofRandom(156));
}

void Asteroide::Update(ofVec2f posicao, double massa, double raio) {
	double distance = sqrt(pow(posicao.x - posicao_.x, 2) + pow(posicao.y - posicao_.y, 2));
	double atraction = 0;

	if (distance > (raio + raio_))
		atraction = (massa * massa_) / pow(distance, 2);

	ofVec2f direcao = posicao - posicao_;
	ofVec2f forca = direcao.normalized() * atraction;
	ofVec2f aceleracao = forca / massa_;

	posicao_ += (momento_ + aceleracao / 2.0f);
	momento_ += aceleracao;
}

void Asteroide::Draw() {
	ofSetColor(cor);
	ofFill();
	if (raio_ > 10) {
		ofBeginShape();
		for (int i = 0; i < raio_; i++) {
			float x = raio_ * cos(i * (TWO_PI / raio_));
			float y = raio_ * sin(i * (TWO_PI / raio_));
			ofVertex(posicao_.x + x, posicao_.y + y);
		}
		ofEndShape();
	}
	else
		ofDrawCircle(posicao_, raio_);
}