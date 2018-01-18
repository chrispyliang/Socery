#include "card.h"
#include <iostream>
#include "board2.h"
using namespace std;


Card::Card(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
		int defenses,Board*board, Card* core): name{name}, type{type},description{description},magic{magic},activeCost{activeCost},
        cardCost{cardCost},charge{charge},chargeCost{chargeCost},attacks{attacks}, defenses{defenses},board{board},core{core}{}


void Card::effect(){

}

void Card::effect(int i, int p, char ch){}

string Card::getName(){
	if (core == nullptr){
		return name;
	} else {
		return core->getName();
	}
}

string Card::getMyName(){
	return name;
}

string Card::getType(){
	return type;
}

string Card::getDescription(){
	if (core == nullptr){
		return description;
	} else {
		return core->getDescription();
	}
}
/*
string Card::getMyDescription(){
	return description;
}*/

int Card::getMagic(){
	return magic;
}

int Card::getActiveCost(){
    if (core == nullptr){
        return activeCost;
        
    } else {int cost=core->getActiveCost();
        if(cost==0) {return 0;}
        
        else{ return cost+activeCost; }
    }}

int Card::getCardCost(){
	return cardCost;
}

int Card::getCharge(){
	return charge;
}

int Card::getChargeCost(){
	if (core == nullptr){
		return chargeCost;
	} else {
		return core->getCardCost();
	}
}

int Card::getAttacks(){
	if (core == nullptr){
		return attacks;
	} else {
		return attacks + core->getAttacks();
	}
}


int Card::getDefenses(){
	if (core == nullptr){
		return defenses;
	} else {
		return defenses + core->getDefenses();
	}
}
/*
int Card::getMyDefenses(){
	return defenses;
}*/

Card* Card::getCore(){
	return core;
}

void Card::addMagic(int i){
	magic += i;
}

void Card::attack(Card* c){
	this->attacked(c);
	c->attacked(this);
}

void Card::attacked(Card* c){
	
	this->defenses -= c->getAttacks();
	
}

void Card::attacked(int i){
	this->defenses -= i;
}

void Card::addattacks(int i){
	attacks += i;
}

void Card::adddefenses(int i){
	defenses += i;
}

void Card::addcharge(int i){
	charge += i;
}

Card* Card::returnMin(){
	return core;
}

bool Card::isDead(){
	if (getDefenses() <= 0){
		
		return true;
	}
	return false;
}

void Card::updateBoard(Board* b) {
	this->board = b;
}

void Card::updateCore(Card* c){
	core = c;
}






