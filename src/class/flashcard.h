/*
 * flashcard.h
 *
 *  Created on: Feb 21, 2017
 *      Author: fchen
 */

#ifndef FLASHCARD_H_
#define FLASHCARD_H_

#include <string>

using namespace std;

class Flashcardset;				// Forward declaration to prevent double inclusion

class Flashcard {
public:
	Flashcard(Flashcardset* o, string t, string d);
	Flashcard(Flashcardset* o, string t, string d, size_t e);
	virtual ~Flashcard();
	string getTerm();
	string getDefinition();
	size_t getExp();
	void promoteExp();
	void demoteExp();

private:
	Flashcardset* owner;	/* Keep a reference to the set the card belongs to */
	string term;
	string definition;
	size_t exp;				/* experience with the current flash card (on scale 0 - 5)
							   0		: 	Completely Unknown
							   1 - 4 	:	Learning
							   5		: 	Mastered 				*/
};


#endif /* FLASHCARD_H_ */
