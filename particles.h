// SphereQuest 1.5
// SFWR ENG 3GC3
// Game updates made in 2011 by Kaitlin Smith (0645771)
// Original base game written by Jason Costabile, Ben Kybartas (with permission), and Kaitlin Smith in April 2010

// Code used from assignment 3

// Code written with the kind assistance of Manivanna Thevathasan,
// and bits and pieces from the following websites:
// http://nehe.gamedev.net/tutorial/particle_engine_using_triangle_strips/21001/
// http://www.gamedev.net/page/resources/_/technical/opengl/lighting-and-normals-r1682

#ifndef PARTICLES
#define PARTICLES

extern float airFriction;
extern float floorFriction;
extern bool continueStream;

void initParticleSystem(int Max);
void drawParticleSystem(int value, float x, float y);
void setRunState(bool state);
bool getRunState();
void nextFrameParticleSystem();
void removeParticle();
void collisionDetection();
void drawParticle(float x, float y, float z, float r, float g, float b);
void insertParticles(float x, float y);

#endif