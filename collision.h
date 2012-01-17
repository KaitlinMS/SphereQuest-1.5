// SphereQuest 1.5
// SFWR ENG 3GC3
// Game updates made in 2011 by Kaitlin Smith (0645771)
// Original base game written by Jason Costabile, Ben Kybartas (with permission), and Kaitlin Smith in April 2010

// collision.h
// contains functions related to collision detection

#ifndef COLLISION_H
#define COLLISION_H

#include <iostream>		//for debugging. Remove when done.
#include <stdlib.h>
#include <gl/glut.h>
#include <cmath>

#include "maze.h"

using namespace std;	//debugging

class collision {
private:
	bool checkPointCollision(float movX, float movZ);
	float getUpperBound(float obstacleWidth, float tolerance);
	float getLowerBound(float obstacleWidth, float tolerance);

public:
	collision(maze *mazeObj); // Constructor
	~collision(){}; // Destructor
	int getGridPositionX(float locX);
	int getGridPositionZ(float locZ);
	bool checkCollision(float movX, float movY, float movZ, float objectRadius);
};

#endif