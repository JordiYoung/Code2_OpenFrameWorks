#include "flocking.h"

void flocking::setup() {
	boids.resize(100);
	for (auto & b : boids) {
		b.setup(ofRandom(2,15), ofGetWidth() / 2, ofGetHeight() / 2);
		l.setup(0, ofGetHeight() / 2, ofGetWidth(), ofGetHeight(), 0.1);
	}
}

void flocking::update() {
	
	for (auto & b : boids) {

		if (l.contains(b)) {
			ofPoint dragForce = l.drag(b);
			b.applyForce(dragForce);
		}
		//ofPoint gravity(0, 0.01*b.mass);
		//b.applyForce(gravity);
		b.flock(boids);
		b.update();
		b.borders();
	}
}

void flocking::draw() {
	l.display();
	for (auto & b : boids) {
		b.draw();
	}
}

void flocking::addBoid(int x, int y) {
	boid v;
	v.setup(ofRandom(2,15),x, y);
	boids.push_back(v);
}