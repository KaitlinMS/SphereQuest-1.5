// SphereQuest 1.5
// SFWR ENG 3GC3
// Game updates made in 2011 by Kaitlin Smith (0645771)
// Original base game written by Jason Costabile, Ben Kybartas (with permission), and Kaitlin Smith in April 2010

// draw.h
// Contains functions relating to drawing commands.

#ifndef DRAW_H
#define DRAW_H

#include <stdlib.h>
#include <gl\glut.h>

class draw {
public:
	draw(); // Constructor
	~draw(){}; // Destructor
	void drawTemples(GLuint roofTexture, GLuint redTexture);
	void drawXWall();
	void drawZWall();
	void drawTree();
	void drawWiseMen();
	void drawGround();
	void drawSkybox();
	void drawFountain(float x, float z);
};

#endif