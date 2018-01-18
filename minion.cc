#include "minion.h"
#include "board2.h"
using namespace std;


Minion::Minion(string name ,string type, string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks, int defenses,Board* board, Card* core): Card{name ,type,description,  magic, activeCost, cardCost, charge, chargeCost, attacks,
    defenses,board,core}{}

//Minion::~Minion(){};
/*
int Minion::getAttacks(){
	return attacks;
}*/
/*
bool Minion::isDead(){
	if (defenses <= 0){
		return true;
	}
	return false;
}*/
