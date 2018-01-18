#include "blankCard.h"
#include "ascii_graphics.h"
#include <iostream>
#include "board2.h"
using namespace std;

BlankCard::BlankCard(): Card{"blank" ,"BlankCard", "", 0,0, 0,0,0,0,0,nullptr, nullptr}{}

void BlankCard::effect(){

}

card_template_t BlankCard::getTemplate(){
	return CARD_TEMPLATE_BORDER;
}


Trigger BlankCard::getTrigger() const {
	return Trigger::No;
}

//*******************Empty Card***********************//
EmptyCard::EmptyCard(): Card{"empty" ,"EmptyCard", "", 0,0, 0,0,0,0,0,nullptr, nullptr}{}
void EmptyCard::effect(){

}

card_template_t EmptyCard::getTemplate(){
	return CARD_TEMPLATE_EMPTY;
}

Trigger EmptyCard::getTrigger() const {
	return Trigger::No;
}

//********************Player Card********************//
PlayerCard::PlayerCard(string name, int player_num, int defenses, int magic): Card{name,"BlankCard", "", magic,0, 0,0,0,0,defenses,nullptr, nullptr},player_num{player_num}{}


Trigger PlayerCard::getTrigger() const {
	return Trigger::No;
}

card_template_t PlayerCard::getTemplate(){
	return display_player_card(player_num, name, defenses, magic);
}










