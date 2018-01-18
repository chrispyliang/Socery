#ifndef _DECK_H_
#define _DECK_H_
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "spell.h"
#include "ritual.h"
#include "Enchantment.h"
#include "ascii_graphics.h"
using namespace std;

class Deck{
	vector <Card*> cards;
public:
	void update(Board *b);
    void load(string filename);
    void display();
    Card* shuffle();
    Card* convert(string name); // convert a string to a card
    Card* getFirst();
    ctArray createTemplateArray();
    void displayTemplateArray(ctArray cta);
    void addToBack(Card* c);

};


#endif

