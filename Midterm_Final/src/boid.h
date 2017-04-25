#pragma once
#include "ofMain.h"


class boid {

public:
	void setup(float m, int x, int y);

	void update();

	void applyForce(const ofPoint & force);

	
	void flock(vector<boid> boids);


	ofPoint separate(vector<boid> boids);


	// Alignment
	ofPoint align(vector<boid> boids);

	// Cohesion
	ofPoint cohesion(vector<boid> boids);

	// Wraparound
	void borders();


	// seek near by boids
	ofPoint seek(const ofPoint & target);

	void draw();



	const ofPoint& getLocation() const {
		return location;
	}

	const ofPoint& getVelocity() const {
		return velocity;
	}


	ofPoint location;
	ofPoint velocity;
	ofPoint acceleration;
	float r;
	float maxForce;
	float topSpeed;
	float mass;

	
	

};