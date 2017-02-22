/*
 * flashcardset.h
 *
 *  Created on: Feb 22, 2017
 *      Author: Sihao
 */

#ifndef CLASS_FLASHCARDSET_H_
#define CLASS_FLASHCARDSET_H_

#include "flashcard.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>

using namespace std;

class Flashcardset {
public:
	Flashcardset(string inputFilePath);
	virtual ~Flashcardset();
	Flashcard* getNextCard();
	void updateCardPosition(Flashcard* c);
	size_t getMasteredCardCount();
	void saveToFile();
	Flashcard* currentCard;

private:
	// Return Number of cards generated
	size_t generateSetFromFile();
	void sanityCheck();
	size_t totalCardCount;
	vector<Flashcard*> unknownCards, learningCards, masteredCards;
	string savePath;

};

#endif /* CLASS_FLASHCARDSET_H_ */
