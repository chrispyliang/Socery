//
//  minion.cpp
//  a5
//
//  Created by 姚钰玮 on 2017-07-16.
//  Copyright © 2017 姚钰玮. All rights reserved.
//

#include "baseMinion.h"
#include "ascii_graphics.h"
#include "board2.h"
#include <iostream>
using namespace std;

//*****************Base Minion*************************//

 BaseMinion::BaseMinion(string name ,string type,string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
        int defenses,Board* board, Card* core): Minion{ name , type, description,  magic, activeCost,  cardCost, charge, chargeCost, attacks, defenses,board,core}{}


BaseMinion::~BaseMinion(){}




/******************Baron Geddon***********************/
BaronGeddon::BaronGeddon():BaseMinion{ "Baron Geddon" , "BaseMinion", "At the end of turn, deal 2 damages to all minions",  0, 0,  5,0, 0, 0,10,nullptr,nullptr}{}

card_template_t BaronGeddon::getTemplate(){
    return display_minion_triggered_ability(name, cardCost, attacks, defenses, description);
}

void BaronGeddon::effect(int i, int p, char ch){
    board->attackAll();
}

Trigger BaronGeddon::getTrigger() const {
    return Trigger::End;
}

BaronGeddon::~BaronGeddon(){}

//******************Earth Elemental***********************//
EarthElemental::EarthElemental(): BaseMinion{ "Earth Elemental" , "BaseMinion", "",  0, 0,  3,0, 0, 4,4,nullptr,nullptr}{}



void EarthElemental::effect(int i,int p,char ch){}

card_template_t EarthElemental::getTemplate(){
    return display_minion_no_ability(name, cardCost, attacks, defenses);
}


Trigger EarthElemental::getTrigger() const {
	return Trigger::No;
}

EarthElemental::~EarthElemental(){}



//******************Air Elemental***********************//
AirElemental::AirElemental(): BaseMinion{ "Air Elemental" , "BaseMinion", "",  0, 0,  0,0, 0, 1,1,nullptr,nullptr}{}

card_template_t AirElemental::getTemplate(){
    return display_minion_no_ability(name, cardCost, attacks, defenses);
}

void AirElemental::effect(int i, int p, char ch){
	return;
}

Trigger AirElemental::getTrigger() const {
	return Trigger::No;
}


AirElemental::~AirElemental(){}



//******************Fire Elemental***********************//
FireElemental::FireElemental(): BaseMinion{ "Fire Elemental" , "BaseMinion", "Whenever an opponent's minion enters play, deal 1 damage to it",  0, 0,  2,0, 0, 2,2,nullptr,nullptr}{}


card_template_t FireElemental::getTemplate(){
    return display_minion_triggered_ability(name, cardCost, attacks, defenses, description);
}

void FireElemental::effect(int i, int p, char ch){
    
	Card * c = board->return_min(i,p);
   
	c->attacked(1);
    }

Trigger FireElemental::getTrigger() const {
	return Trigger::Enter;
}

FireElemental::~FireElemental(){}


//******************Potion Seller***********************//
PotionSeller::PotionSeller():BaseMinion{ "Potion Seller" , "BaseMinion", "At the end of your turn, all your minions gain +0/+1",  0, 0,  2,0, 0, 1,3,nullptr,nullptr}{}
card_template_t PotionSeller::getTemplate(){
    return display_minion_triggered_ability(name, cardCost, attacks, defenses, description);
}

void PotionSeller::effect(int i, int p, char ch){
	board->addAll(p);
}

Trigger PotionSeller::getTrigger() const {
	return Trigger::End;
}

PotionSeller::~PotionSeller(){}


//******************Novice Pyromancer***********************//
NovicePyromancer::NovicePyromancer():BaseMinion{ "Novice Pyromancer" , "BaseMinion", "Deal 1 damage to target minion",  0, 1,  1,0, 0, 0,1,nullptr,nullptr}{}

card_template_t NovicePyromancer::getTemplate(){
    return display_minion_activated_ability(name, cardCost, attacks, defenses, activeCost, description);
}

void NovicePyromancer::effect(int i, int p, char ch){

    Card * c = board->return_min(i, p);
    
	c->attacked(1);
    if (c->isDead()){
        board->remove(i, p, 'k');
    }
}

Trigger NovicePyromancer::getTrigger() const {
	return Trigger::No;
}

NovicePyromancer::~NovicePyromancer(){}

//******************Apprentice Summoner***********************//
ApprenticeSummoner::ApprenticeSummoner():BaseMinion{ "Apprentice Summoner" , "BaseMinion", "Summon a 1/1 air elemental",  0, 1,  1,0, 0, 1,1,nullptr,nullptr}{}

card_template_t ApprenticeSummoner::getTemplate(){
    return display_minion_activated_ability(name, cardCost, attacks, defenses, activeCost, description);
}

void ApprenticeSummoner::effect(int i, int p, char ch){
	board->summon(1, p);
}

Trigger ApprenticeSummoner::getTrigger() const {
	return Trigger::No;
}

ApprenticeSummoner::~ApprenticeSummoner(){}

//******************Master Summoner***********************//
MasterSummoner::MasterSummoner():BaseMinion{ "Master Summoner" , "BaseMinion", "Summon up to 3 1/1 air elementals",  0, 2,  3,0, 0, 2,3,nullptr,nullptr}{}


card_template_t MasterSummoner::getTemplate(){
    return display_minion_activated_ability(name, cardCost, attacks, defenses, activeCost, description);
}

void MasterSummoner::effect(int i, int p, char ch){
	board->summon(3, p);
}

Trigger MasterSummoner::getTrigger() const {
	return Trigger::No;
}

MasterSummoner::~MasterSummoner(){}





