/*
 * flashcard.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: fchen
 */

#include "flashcard.h"

Flashcard::Flashcard(Flashcardset* o, string t, string d) {
	owner = o;
	term = t;
	definition = d;
	exp = 0;
}

Flashcard::Flashcard(Flashcardset* o, string t, string d, size_t e) {
	owner = o;
	term = t;
	definition = d;
	exp = e;
}

Flashcard::~Flashcard() {
}

string Flashcard::getTerm() {return term;}
string Flashcard::getDefinition() {return definition;}
size_t Flashcard::getExp() {return exp;}

void Flashcard::promoteExp()
{
	if (exp < 5) exp++;
	else exp = 5;
	if (owner) owner->updateCardPosition(this);
}

void Flashcard::demoteExp()
{
	exp = 0;
	if (owner) owner->updateCardPosition(this);
}
