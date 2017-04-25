#include "ofMain.h"
#include "boid.h"

class liquid {
public:

	void setup(float x_, float y_, float w_, float h_, float c_);
	bool contains(boid m);
	ofPoint drag(boid m);
	void display();

	// Liquid is a rectangle
	float x, y, w, h;
	// Coefficient of drag
	float c;
};
