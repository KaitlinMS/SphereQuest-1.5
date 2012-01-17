// SphereQuest 1.5
// SFWR ENG 3GC3
// Game updates made in 2011 by Kaitlin Smith (0645771)
// Original base game written by Jason Costabile, Ben Kybartas (with permission), and Kaitlin Smith in April 2010

// Normal calculations from: http://support.microsoft.com/kb/131130

#include "draw.h"
#include "player.h"
#include <math.h>

draw::draw(){}

float PI = 3.1415926535897932384626433832795;
float x = 0;
float transx;

void calcNormal(float vert1[], float vert2[], float vert3[], float *normX = 0, float *normY = 0, float *normZ = 0) {
	float Qx, Qy, Qz, Px, Py, Pz;

	Qx = vert2[0]-vert1[0];
	Qy = vert2[1]-vert1[1];
	Qz = vert2[2]-vert1[2];
	Px = vert3[0]-vert1[0];
	Py = vert3[1]-vert1[1];
	Pz = vert3[2]-vert1[2];

	*normX = Py*Qz - Pz*Qy;
	*normY = Pz*Qx - Px*Qz;
	*normZ = Px*Qy - Py*Qx;
}

// This is the GLUT solid cube code. Since cubes don't have texture coordinates, "re-write" the code so that textures will work properly.
// This idea is from http://stackoverflow.com/questions/327043/how-to-apply-texture-to-glutsolidcube/327135#327135
static void setUpBox(GLfloat size, GLenum type) {
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

  for (i = 5; i >= 0; i--) {
    glBegin(type);
		glNormal3fv(&n[i][0]);
		glTexCoord2f(0, 0);
		glVertex3fv(&v[faces[i][0]][0]);
		glTexCoord2f(1, 0);
		glVertex3fv(&v[faces[i][1]][0]);
		glTexCoord2f(1, 1);
		glVertex3fv(&v[faces[i][2]][0]);
		glTexCoord2f(0, 1);
		glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

void makeCube(GLdouble size) {
  setUpBox(size, GL_QUADS);
}

// End of solid cube code.

void draw::drawTemples(GLuint roofTexture, GLuint redTexture) {

	glEnable(GL_TEXTURE_2D);
	
	glColor3f(0.7, 0.3, 0.3);
	glPushMatrix();

	GLfloat dull[3] = {0, 0, 0};
	glMaterialfv (GL_FRONT, GL_SPECULAR , dull);

	
	//Draw Roof
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	glBindTexture(GL_TEXTURE_2D, roofTexture);
	glDisable(GL_CULL_FACE);		//don't cull the roof (both sides are visible)
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(20,-20,32);	//orig: 0, 0, 32 (shifted to draw the temple within the grid cell)
	glutSolidCone(40, 30, 20, 20);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);

	glBindTexture( GL_TEXTURE_2D, redTexture);
	glTranslatef(20, 20, 20);	//orig: 0,20,0
	makeCube(40);

	//Draw Roof
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	glBindTexture( GL_TEXTURE_2D, roofTexture);
	glDisable(GL_CULL_FACE);		//don't cull the roof (both sides are visible)
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0,0,45);
	glutSolidCone(30, 20, 20, 20);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);

	glBindTexture( GL_TEXTURE_2D, redTexture);
	glTranslatef(0, 35, 0);
	makeCube(30);

	//Draw Roof
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	glBindTexture( GL_TEXTURE_2D, roofTexture);
	glDisable(GL_CULL_FACE);		//don't cull the roof (both sides are visible)
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0,0,35);
	glutSolidCone(20, 10, 20, 20);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	
	glBindTexture( GL_TEXTURE_2D, redTexture);
	glTranslatef(0, 25, 0);
	makeCube(20);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

}

void draw::drawXWall() {

	glEnable(GL_TEXTURE_2D);

	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(10, 10, 20);

	GLfloat dull[3] = {0, 0, 0};
	glMaterialfv (GL_FRONT, GL_SPECULAR , dull);

	makeCube(20);
	glTranslatef(20, 0, 0);
	makeCube(20);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

void draw::drawZWall() {

	glColor3f(0.5, 0.5, 0.5);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glTranslatef(20, 10, 10);

	GLfloat dull[3] = {0, 0, 0};
	glMaterialfv (GL_FRONT, GL_SPECULAR , dull);

	makeCube(20);
	glTranslatef(0, 0, 20);
	makeCube(20);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

void draw::drawWiseMen() {

	float max = 2 * PI;
	// Draw Body		
	if (x <= max){
		x += 0.03;
		transx = sin(x);
	}
	else{
		x = 0;
		transx = sin(x);
	}
	
	glDisable(GL_CULL_FACE);
	glTranslatef(0, 1*transx + 2.5, 0);
	glPushMatrix();
	GLfloat dull[3] = {1, 1, 1};
	glMaterialfv (GL_FRONT, GL_SPECULAR , dull);

	glColor3f(1.0f, 1.0f, 0.5f);
	//glTranslatef(0.0f ,0.0f, 0.0f);
	glTranslatef(20.0f ,0.0f, 20.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glutSolidCone(0.6f,2.0f,20,20);
	glPopMatrix();

	glEnable(GL_CULL_FACE);

	//Draw Belt
	glPushMatrix();
	glColor3f(0.5f, 0.25f, 0.0f);
	//glTranslatef(0.0f ,0.7f, 0.0f);
	glTranslatef(20.0f ,0.7f, 20.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glutSolidTorus(0.19f, 0.3f,10,10);
	glPopMatrix();

	// Draw Head
	glColor3f(1.0f, 0.75f, 0.6f);
	//glTranslatef(0.0f, 1.8f, 0.0f);
	glTranslatef(20.0f, 1.8f, 20.0f);
	glutSolidSphere(0.35f,20,20);
	
	//Draw Beard
	glPushMatrix();
	glColor3f(0.5f,0.5f,0.5f);
	glTranslatef(0.0f, -0.25f, 0.05f);
	glRotatef(50.0f + (5 * transx), 1.0f, 0.0f, 0.0f);
	glutSolidCone(0.2f,0.8f,20,20);
	glPopMatrix();

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.13f, 0.0f, 0.30f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.26f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

	//Draw Eyebrows
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	glTranslatef(-0.26f, 0.1f, 0.35f);
	glRotatef(90.0, 0.0f, 1.0f, -0.2f);
	glutSolidCone(0.04,0.2,5,5);
	glTranslatef(0.0f, 0.1f, 0.52f);
	glRotatef(-180.0, 0.0f, 1.0f, -0.2f);
	glutSolidCone(0.04,0.2,5,5);
	glPopMatrix();

	// Draw Hat
	glDisable(GL_CULL_FACE);		//don't cull the hat (both sides are visible)
	glPushMatrix();
	glTranslatef(0.0f, 0.2f + (0.1*transx), 0.0f);
	glColor3f(1.0f, 0.8f , 0.2f);
	glRotatef(-90.0f ,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.9f,0.35f,10,2);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
}

void draw::drawTree() {

	glDisable(GL_CULL_FACE);		//don't cull the tree (inside of cones are visible)

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();

	GLfloat dull[3] = {0, 0, 0};
	glMaterialfv (GL_FRONT, GL_SPECULAR , dull);

	glRotatef(-90, 1, 0, 0);
	glTranslatef(20, -20, 0);
	
	glPushMatrix();
	glRotatef(-2 * transx, 1, 0, 0);
	glutSolidCone(3, 5, 10, 10);
	glPopMatrix();
	
	glTranslatef(0, 0, 2.5);
	
	glPushMatrix();
	glRotatef(-3 * transx, 1, 0, 0);
	glutSolidCone(3, 5, 10, 10);
	glPopMatrix();

	glTranslatef(0, 0, 2.5);
	
	glPushMatrix();
	glRotatef(-4 * transx, 1, 0, 0);
	glutSolidCone(3, 5, 10, 10);
	glPopMatrix();
	
	glPopMatrix();

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
}

void draw::drawGround() {
	float vert1[] = {-400.0, 0.0, -400.0};
	float vert2[] = {-400.0, 0.0,  400.0};
	float vert3[] = {400.0, 0.0,  400.0};
	float vert4[] = {400.0, 0.0, -400.0};
	float normX, normY, normZ;

	glBegin(GL_QUADS);
		calcNormal(vert1, vert2, vert3, &normX, &normY, &normZ);
		glNormal3f(normX, normY, normZ);
		
		glTexCoord2f(0, 0);
		glVertex3fv(vert1);

		glTexCoord2f(75, 0);
		glVertex3fv(vert2);

		glTexCoord2f(75, 75);
		glVertex3fv(vert3);

		glTexCoord2f(0, 75);
		glVertex3fv(vert4);
	glEnd();
}

void draw::drawFountain(float x, float z) {
	glDisable(GL_CULL_FACE);

	glEnable(GL_TEXTURE_2D);
	glColor3f(0.99, 0.94, 0.22);

	glPushMatrix();
	glTranslatef(x, 0, z);
	GLfloat dull[3] = {0.99, 0.74, 0.23};
	glMaterialfv (GL_FRONT, GL_SPECULAR , dull);
	makeCube(5);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	glEnable(GL_CULL_FACE);
}


//Sky is pretty
void draw::drawSkybox(){
	glCullFace(GL_FRONT);		//invert culling (because we see the inside of the skybox)

	glColor3f(0.8, 0.9, 1.0);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glutSolidSphere(500, 10, 10);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	glCullFace(GL_BACK);		//restore normal culling
}