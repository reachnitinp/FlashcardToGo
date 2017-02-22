/*
 * flashcardset.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: Sihao
 */

#include "flashcardset.h"


Flashcardset::Flashcardset(string inputFilePath) {
	savePath = "res/save/" + inputFilePath;
	totalCardCount = generateSetFromFile();
}

Flashcardset::~Flashcardset() {
	saveToFile();
	// free memory for each card in three sets
}


Flashcard* Flashcardset::getNextCard()
{
	sanityCheck();
	size_t percent = rand() % 100;
	Flashcard* curCard;
	vector<Flashcard*>* curCardSet;
	if (percent > 65 || unknownCards.size() == totalCardCount)
		curCardSet = &unknownCards;
	else if (percent < 5 || unknownCards.size() == totalCardCount)
		curCardSet = &masteredCards;
	else
		curCardSet = &learningCards;

	curCard = curCardSet->back();
	curCardSet->pop_back();

	return curCard;
}

void Flashcardset::updateCardPosition(Flashcard* c)
{
	if (!c) throw runtime_error("updateCardPosition(): argument is null pointer");

	size_t curExp = c->getExp();
	if (curExp == 5)
		masteredCards.push_back(c);
	else if (curExp == 0)
		unknownCards.push_back(c);
	else
		learningCards.push_back(c);
}

size_t Flashcardset::getMasteredCardCount() {return masteredCards.size();}

void Flashcardset::saveToFile()
{
	/*
	sanityCheck();
	ofstream fout;
	try
	{
		fout.open(savePath.c_str(), ios::trunc);
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
	*/
}

/**
 * gnerateSetfromFile()
 *
 * Input:	None
 * Return: 	Number of cards generated
 */
size_t Flashcardset::generateSetFromFile()
{
	ifstream fin;
	string curTerm, curDef, curExpStr;
	size_t curExp;
	size_t count = 0;
	try
	{
		fin.open(savePath.c_str());
		while (!fin.eof())
		{
			getline(fin, curTerm);
			getline(fin, curDef);
			getline(fin, curExpStr);
			if (!curExpStr.empty())
				curExp = (size_t) curExpStr.at(0);

			Flashcard* curCard = new Flashcard(this, curTerm, curDef, curExp);
			if (curExp == 0)
				unknownCards.push_back(curCard);
			else if (curExp == 5)
				masteredCards.push_back(curCard);
			else
				learningCards.push_back(curCard);
			count++;
		}
		fin.close();
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}

	return count;
}

void Flashcardset::sanityCheck()
{
	if (totalCardCount == 0) throw runtime_error("No card in the current set!!");
	if (savePath.empty()) throw runtime_error("Save File Path Not Initialized!!");
}

