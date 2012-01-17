// SphereQuest 1.5
// SFWR ENG 3GC3
// Game updates made in 2011 by Kaitlin Smith (0645771)
// Original base game written by Jason Costabile, Ben Kybartas (with permission), and Kaitlin Smith in April 2010

// hud.h
// contains function primitives related to drawing the hud

#ifndef HUD_H
#define HUD_H

#include <stdlib.h>
#include <gl/glut.h>
#include <string.h>

#include <iostream>

#include "player.h"

class HUD {
public:
	HUD(); // Constructor
	~HUD(){}; // Destructor
	void printText(float x, float y, char *string, float r, float g, float b);
	void drawIntroText();
	void drawQuestion(char * q, char * a, char * b, char * c);
	void printPlayAgainMsg(bool isWin);
	void printQuestionFeedback(bool isCorrect);
	void printLevelName(int level);
	void printSaveLoadFeedback(bool isSave, bool isSuccessful);
	void drawIntroScreen();
	void drawHUD();
private:
	void beginHudDrawing();
	void endHudDrawing();
};

#endif