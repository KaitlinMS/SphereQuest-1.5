// SphereQuest 1.5
// SFWR ENG 3GC3
// Game updates made in 2011 by Kaitlin Smith (0645771)
// Original base game written by Jason Costabile, Ben Kybartas (with permission), and Kaitlin Smith in April 2010

// Code from assignment 3

// Code written with the kind assistance of Manivanna Thevathasan,
// and bits and pieces from the following websites:
// http://nehe.gamedev.net/tutorial/particle_engine_using_triangle_strips/21001/
// http://www.gamedev.net/page/resources/_/technical/opengl/lighting-and-normals-r1682

#include <stdlib.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <time.h>
#include <list>

using namespace std;

#define MAX_PARTICLES 500

typedef struct {
	bool isAlive;
	float lifeSpan;
	float r;
	float g;
	float b;
	float xPos;
	float yPos;
	float zPos;
	float xDir;
	float yDir;
	float zDir;
	float xG;
	float yG;
	float zG;
} particleStruct; 

list<particleStruct> particle; // Create an empty list of particles
list<particleStruct>::iterator i; // Create an iterator for this list

bool running = true;
float airFriction = 7;
float floorFriction = 0.5;
bool continueStream = true;

void setRunState(bool state) {
	running = state;
}

bool getRunState() {
	return running;
}

struct {
	struct 	{
		float pos[3];
		float col[3];
	} ver[8];

	struct {
		unsigned int ver[6];
		float norm[3];
	} quad[6];
} cube;

// Particles are cubes
void drawParticle(float x, float y, float z, float r, float g, float b) {
	glBegin(GL_POINTS);
	glColor3f(r, g, b);
		glVertex3f(x, y, z);
	glEnd();
}

// Countinuous Stream
void initParticleSystem(int Max, float x, float z) {
	if (Max <= MAX_PARTICLES && continueStream == true) {
		for(int j = 0; j < Max; j++) {
			int a = 0;
			int randomSign = rand() % 2 + 1;
			if(randomSign == 1)	{
				a = -1;
			} else {
				a = 1;
			}
			particleStruct initParticle = {true, 50, 
										   0.0745, 0.7647, 0.9216, // Colour
										   x, 0, z, // Origin of particle's motion
										   a*(float)rand() / RAND_MAX, 2+6*(float)rand() / RAND_MAX, a*(float)rand() / RAND_MAX, // Particle motion
										   0, -0.25, 0}; // Gravity
			particle.push_back(initParticle); // Insert a new particle into the back of the list
		}
	}
}

void insertParticles(float x, float z) {
	int numberOfInsertedParticles = 0;
	int maxNumberOfInsertableParticles = 8;

	while(numberOfInsertedParticles < maxNumberOfInsertableParticles && continueStream == true) {
		int a = 0;
		int randomSign = rand() % 2 + 1;
		if(randomSign == 1)	{
			a = -1;
		} else {
			a = 1;
		}
		particleStruct newParticle = {true, 50,
			0, 0, 1, // Colour
			x, 0, z, // Origin
			a*(float)rand() / RAND_MAX, 1+6*(float)rand() / RAND_MAX, a*(float)rand() / RAND_MAX, // Particle motion
			0, -0.25, 0}; // Gravity
		particle.push_back(newParticle); // Insert a new particle into the back of the list
		numberOfInsertedParticles++; 
	}
}

void removeParticle() {
	particle.erase(i++);
}

void drawParticleSystem(int value, float x, float z) {
	if(running == true) {
		initParticleSystem(value, x, z);
		i = particle.begin();
		while(i != particle.end()) {
			if(i->isAlive == true) {
				float x = i->xPos;
				float y = i->yPos;
				float z = i->zPos;
				
				drawParticle(x,y,z, i->r, i->g, i->b);
			} else {
				removeParticle(); 
			}
			i++;
		}
	} else {
		for(i = particle.begin(); i != particle.end(); i++) {
			i->isAlive = false;
		}
	}
}

// Burst and bounce
void nextFrameParticleSystem() {
	for(i = particle.begin(); i != particle.end(); i++) {
		i->xPos += i->xDir/airFriction;
		i->yPos += i->yDir/airFriction;
		i->zPos += i->zDir/airFriction;

		i->xDir += i->xG;
		i->yDir += i->yG;
		i->zDir += i->zG;
		
		// Bounce the particle if it hits the ground
		if(i->yPos < 0 && (i->xPos >= -5 || i->xPos <= 5) && (i->zPos >= -5 || i->zPos <= 5) ) {
			float negyDir = i->yDir;
			i->yPos = 0;
			i->yDir = -negyDir - floorFriction;

			i->xPos += i->xDir/airFriction;
		i->yPos += i->yDir/airFriction;
		i->zPos += i->zDir/airFriction;

		i->xDir += i->xG;
		i->yDir += i->yG;
		i->zDir += i->zG;
		}

		i->lifeSpan -= 1;

		if (i->lifeSpan == 0) {
			i->isAlive = false;
		}
	}
}

