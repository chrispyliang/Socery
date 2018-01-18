#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <string>
#include "deck.h"
#include "hand.h"
#include "board2.h"
#include "card.h"

class Player {
	std::string name;
	Deck* deck;
	Hand* hand;
	Board* board;
	int life = 20; 
	int magic = 2;
	int who;
    bool test;
public:
	Player(std::string name, Deck* deck, Board* board, Hand* hand, int who,bool test);
	bool isDead();
	void draw();
	void discard(int i);
	void attack(int i);
	void attack(int i, int j);
	void play(int i, int p);
	void play(int i, int p, char t);
	void use(int i, int p);
	void use(int i, int p, char t);
	void inspect(int i, int p);
	void displayHand(); 
	void displayBoard();
    void magicUpdate(int p,int i);
	void magicUpdate(int p);
	void remove();
	std::string getName();
	void add_deck_bottom(Card* c); // add card at bottom of deck

};

#endif

