#ifndef _BLANKCARD_H_
#define _BLANKCARD_H_
#include "card.h"

class Board;
class BlankCard: public Card{
	
public:
	BlankCard();
	void effect() override;
	card_template_t getTemplate() override;
	Trigger getTrigger() const override;
	
};	

class EmptyCard: public Card{

public:
	EmptyCard();
	void effect() override;
	card_template_t getTemplate() override;
	Trigger getTrigger() const override;
	
};	

class PlayerCard: public Card{
    int player_num;
public:
    	PlayerCard(std::string name, int player_num, int defenses, int magic);
		card_template_t getTemplate() override;
	Trigger getTrigger() const override;
	
};

#endif

