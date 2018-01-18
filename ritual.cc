//
//  ritual.cpp
//  a5
//
//  Created by 姚钰玮 on 2017-07-16.
//  Copyright © 2017 姚钰玮. All rights reserved.
//

#include "ritual.h"
//#include "trigger.h"
#include "board2.h"
using namespace std;

//**********************Ritual**************************//
Ritual::Ritual(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
   int defenses,Board*board, Card* core): Card{ name , type, description,  magic, activeCost,cardCost, charge, chargeCost, attacks, defenses,board,core}{}

/*string Ritual::getType(){
  return type;
}

void Ritual::add_ritual(int i ){
    this->charge +=i;
}*/
Ritual::~Ritual(){}

card_template_t Ritual::getTemplate(){
  return display_ritual(name, cardCost, chargeCost, description, charge);
}


//*********************Bright Ritual***********************//
BrightRitual::BrightRitual():Ritual{"Bright Rituall" , "Ritual", "At the start of your turn, all your minions gain +0/+1 ",  0, 0,  3,3, 1, 0,0,nullptr,nullptr}{}
void BrightRitual::effect(int i,int p,char ch){
    if(this->charge > 0){
        
        board->addAll(p);
        this->charge--;
    }

    board->addAll(p);
}
Trigger BrightRitual::getTrigger() const{
   return Trigger::Start;

}
card_template_t BrightRitual::getTemplate() {
    return display_ritual(name, cardCost, chargeCost, description, charge);
}
BrightRitual::~BrightRitual(){}


//*********************Dark Ritual***********************//

DarkRitual::DarkRitual(): Ritual{"Dark Ritual" , "Ritual", "At the start of your turn, gain 1 magic",  0, 0,  0,5, 1, 0,0,nullptr,nullptr}{}

void DarkRitual::effect(int i,int p,char ch){
   
    if(this->charge > 0){
        
        this->board->addMagic(1,p);
        
        this->charge--;
    }
    
}

Trigger DarkRitual::getTrigger() const {
    return Trigger::Start;
}

card_template_t DarkRitual::getTemplate(){
    return display_ritual(name, cardCost, chargeCost, description, charge);
}

DarkRitual::~DarkRitual(){}

//*********************Aura Of Power**********************//
AuraofPower::AuraofPower():Ritual{"Aura of Power" , "Ritual", "Whenever a minion enters play under your control, it gains +1/+1",  0, 0,  1,4, 1, 0,0,nullptr,nullptr}{}

void AuraofPower::effect(int i,int p,char ch) {
    if(this->charge>this->activeCost){
      Card * newc=this->board->return_min(i,p);
        newc->adddefenses(1);
        newc->addattacks(1);
      this->charge -=this->activeCost;
    
    }
}
Trigger AuraofPower::getTrigger() const {
    return Trigger::Enter;
}


card_template_t AuraofPower::getTemplate(){
  return display_ritual(name, cardCost, chargeCost, description, charge);
}

AuraofPower::~AuraofPower(){}

//****************Stand Still*********************//
Standstill::Standstill():Ritual{"Standstill" , "Ritual", "Whenever a minion enters play, destroy it",  0, 0,  3,4, 2, 0,0,nullptr,nullptr}{}

void Standstill::effect(int i,int p,char ch){
    if(this->charge>this->activeCost){
        Card * c=this->board->return_min(i, p);
        this->board->remove(i, p, ch);
        this->board->update_grave(c, p);
      this->charge -=this->activeCost;
    }
}

Trigger Standstill::getTrigger() const {
    return Trigger::Enter;
}

card_template_t Standstill::getTemplate(){
    return display_ritual(name, cardCost, chargeCost, description, charge);
}

Standstill::~Standstill(){}





