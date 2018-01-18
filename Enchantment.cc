#include "Enchantment.h"
#include "ascii_graphics.h"
#include "board2.h"
#include <iostream>
using namespace std;

//*******************Enchantment************************//
/*
Enchantment::Enchantment(Minion* min){
	this->kernel = min;
}
*/


Enchantment::Enchantment(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,int defenses,Board*board, Card* core): Minion{ name , type, description,  magic, activeCost,  cardCost, charge, chargeCost, attacks,defenses,board,core}{}

/*string Enchantment::getType(){
	return "Enchantment";
}

int Enchantment::getAttacks(){
	if (core != nullptr) return attacks + core->getAttacks();
	return attacks;
}

int Enchantment::getDefenses(){
	if (core != nullptr) return defenses + core->getDefenses();
	return defenses;
}

int Enchantment::getActiveCost(){
	if (core != nullptr) return activeCost + core->getActiveCost();
	return activeCost;
}
*/
Enchantment::~Enchantment(){}

//***********************Immortal************************//
Immortal::Immortal(): Enchantment{ "Immortal" , "Enchantment", "",  0, 0,  5,0, 0, 0,1000,nullptr,nullptr}{}

card_template_t Immortal::getTemplate(){
	if (core == nullptr){
		return display_enchantment_attack_defence(name, cardCost, description, "+0", "+10000");
	} else {
		string name = getName();
		//string type = getType();
		string description = getDescription();
		//cout << "hhhhhhhh888" << endl;
		int attacks = getAttacks();
		int defenses = getDefenses();
		int cardcost = getCardCost();
		int activecost=getActiveCost();
		//cout << "hhhhhhh777" << endl;
		if(activecost==0) return display_minion_no_ability(name, cardcost, attacks, defenses);
		return display_minion_activated_ability(name, cardcost, attacks, defenses,activecost, description);
	}
}

void Immortal::effect(int i, int p, char ch){
 core->effect(i, p, ch);
}

Trigger Immortal::getTrigger() const{
 return Trigger::No;
}

Immortal::~Immortal(){}

//***********************Giant Strength************************//
GiantStrength::GiantStrength(): Enchantment{ "Giant Strength" , "Enchantment", "",  0, 0,  1,0, 0, 2,2,nullptr,nullptr}{}

/*
int GiantStrength::getAttacks(){
	if (kernel != nullptr) return attacks + kernel->getAttacks();
	return attacks;
}

int Enchantment::getDefenses(){
	if (kernel != nullptr) return defenses + kernel->getDefenses();
	return defenses;
}

int Enchantment::getActiveCost(){
	if (kernel != nullptr) return activeCost + kernel->getActiveCost();
	return activeCost;
}
*/
card_template_t GiantStrength::getTemplate(){
	if (core == nullptr){
		return display_enchantment_attack_defence(name, cardCost, description, "+2", "+2");
	} else {
		string name = getName();
		//string type = getType();
		string description = getDescription();
		//cout << "hhhhhhhh888" << endl;
		int attacks = getAttacks();
		int defenses = getDefenses();
		int cardcost = getCardCost();
		int activecost=getActiveCost();
		//cout << "hhhhhhh777" << endl;
		if(activecost==0) return display_minion_no_ability(name, cardcost, attacks, defenses);
		return display_minion_activated_ability(name, cardcost, attacks, defenses,activecost, description);
	}
}

void GiantStrength::effect(int i, int p, char ch){
	core->effect(i, p, ch);
}

Trigger GiantStrength::getTrigger() const{
	return Trigger::No;
}

GiantStrength::~GiantStrength(){}


//***********************Magic Fatigue************************//
MagicFatigue::MagicFatigue():Enchantment{ "Magic Fatigue" , "Enchantment", "Enchanted minion's activated ability costs 2 more",  0, 2,  0,0, 0, 0,0,nullptr,nullptr}{}
card_template_t MagicFatigue::getTemplate(){
	if (core == nullptr) {
		return display_enchantment(name, cardCost, description);
	} else {
		string name = getName();
		//string type = getType();
		string description = getDescription();
		//cout << "hhhhhhhh888" << endl;
		int attacks = getAttacks();
		int defenses = getDefenses();
		int cardcost = getCardCost();
		int activecost = getActiveCost();
		//cout << "hhhhhhh777" << endl;
		if(activecost==0) return display_minion_no_ability(name, cardcost, attacks, defenses);
		return display_minion_activated_ability(name, cardcost, attacks, defenses,activecost, description);
	}
}

void MagicFatigue::effect(int i, int p, char ch){
	core->effect(i, p, ch);
}

Trigger MagicFatigue::getTrigger() const{
	return Trigger::No;
}

MagicFatigue::~MagicFatigue(){}


//***********************Silence************************//
Silence::Silence():Enchantment{ "Silence" , "Enchantment", "Enchanted minion cannot use abilities",  0, 1000,  1,0, 0, 0,0,nullptr,nullptr}{}
card_template_t Silence::getTemplate(){
	if(this->core==nullptr) {
		return display_enchantment(name, cardCost, description);
	} else {
		string name = getName();
		//string type = getType();
		string description = getDescription();
		//cout << "hhhhhhhh888" << endl;
		int attacks = getAttacks();
		int defenses = getDefenses();
		int cardcost = getCardCost();
		int activecost = getActiveCost();
		//cout << "hhhhhhh777" << endl;
		if(activecost==0) return display_minion_no_ability(name, cardcost, attacks, defenses);
		return display_minion_activated_ability(name, cardcost, attacks, defenses,activecost, description);
	}
}

void Silence::effect(int i, int p, char ch){
	core->effect(i, p, ch);
}

Trigger Silence::getTrigger() const{
	return Trigger::No;
}

Silence::~Silence(){}

