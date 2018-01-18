#ifndef _ENCHANTMENT_H_
#define _ENCHANTMENT_H_

#include <stdio.h>
#include "minion.h"
class Board;
class Enchantment: public Minion {
	//std::string type = "Enchantment";
protected:
	//Card* kernel = nullptr;
public:
    Enchantment(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
                int defenses,Board*board, Card* core);

	/*virtual int getAttacks() override;
	virtual int getDefenses() override;
	virtual int getActiveCost() override;
	std::string getType() override;*/
    ~Enchantment();
};

class Immortal: public Enchantment {
public:
 Immortal();
 card_template_t getTemplate() override;
 void effect(int i, int p, char ch) override;
 Trigger getTrigger() const override;
 ~Immortal();
} ;

class GiantStrength: public Enchantment {
	/*std::string name = "Giant Strength";
	std::string type = "Enchantment";
	std::string description = "";
	Board *b = nullptr;
	int magic = 0;
	int cost = 1;
	int attacks = 2;
	int defenses = 2;	
	std::string string_attack = "+2";
	std::string string_defence = "+2";
	int chargeCost = 0;
	int charge = 0;
	int activeCost = 0;*/
public:
	GiantStrength();
	card_template_t getTemplate() override;
	void effect(int i, int p, char ch) override;
	Trigger getTrigger() const override;
	~GiantStrength();
} ;


class MagicFatigue: public Enchantment {
	/*std::string name = "Magic Fatigue";
	std::string type = "Enchantment";
	std::string description = "Enchanted minion's activated ability costs 2 more";
	Board *b = nullptr;
	int magic = 0;
	int cost = 0;
	int attacks = 0;
	int defenses = 0;	
	int chargeCost = 0;
	int charge = 0;
	int activeCost = 2;*/
public:
    MagicFatigue();
	card_template_t getTemplate() override;
	void effect(int i, int p, char ch) override;
	Trigger getTrigger() const override;
	~MagicFatigue();
} ;


class Silence: public Enchantment {
	/*std::string name = "Silence";
	std::string type = "Enchantment";
	std::string description = "Enchanted minion cannot use abilities";
	Board *b = nullptr;
	int magic = 0;
	int cost = 0;
	int attacks = 0;
	int defenses = 0;	
	int chargeCost = 0;
	int charge = 0;
	int activeCost = 10000;*/
public:
    Silence();
	card_template_t getTemplate() override;
	void effect(int i, int p, char ch) override;
	Trigger getTrigger() const override;
	~Silence();
} ;




#endif

