#ifndef _HAND_H_
#define _HAND_H_
#include "ascii_graphics.h"
#include <vector>
#include "card.h"
//#include "deck.h"

class Hand{
	std::vector<Card*> cards;
public:
	void display(); // print all cards in one's hand
	void update(Card* c); // insert card into hand
	Card* getCard(int i);
	ctArray createTemplateArray();
	void displayTemplateArray(ctArray cta);
    int getLength();
  void putBack(Card* c, int i);
	~Hand();
};




#endif

