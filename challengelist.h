// SphereQuest 1.5
// SFWR ENG 3GC3
// Game updates made in 2011 by Kaitlin Smith (0645771)
// Original base game written by Jason Costabile, Ben Kybartas (with permission), and Kaitlin Smith in April 2010

// A Class which defines a list of wisemen Challenges

#ifndef CHALLENGELIST_H
#define CHALLENGELIST_H

class challengelist{

public:
	challengelist();
	~challengelist(){};

	/*
	The Below Options should generally not be used since they directly
	affect the challenge list although the challenge list is designed to
	work on its own
	*/
	void setChallengeNum(int newNum);
	void incrementChallengeNum(); //manually go to the next challenge
	void decrementChallengeNum(); //manually go to the previous challenge

	/*
	These operators should be used since they are abstract and require no
	manual changes to be made to the challenge list
	*/
	int getChallengeNum();		//returns the challenge number
	char * getCurrentChallenge(); // Get a string of the current challenge
	char * getFirstChoice(); // Get the first choice (a)
	char * getSecondChoice(); // Get the second choice (b)
	char * getThirdChoice(); // Get the third choice (c)
	bool answerChallenge(int choice); //Input an answer (0 = a, 1 = b, 2 = c) and the function returns true if correct
									  //and false if incorrect. Afterwards, the challenge list moves to the next challenge
};

#endif