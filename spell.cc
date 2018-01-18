//
//  spell.cpp
//  a5
//
//  Created by 姚钰玮 on 2017-07-16.
//  Copyright © 2017 姚钰玮. All rights reserved.
//

#include "spell.h"
#include "ritual.h"
#include "board2.h"

using namespace std;
//********************Spell**************************//
Spell::Spell(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
             int defenses,Board*board, Card* core):Card{ name , type, description,  magic, activeCost,cardCost, charge, chargeCost, attacks, defenses,board,core}{}
/*string Spell::getType(){
    return type;
}*/

Spell::~Spell(){}
//*******************Banish**************************//
Banish::Banish():Spell{ "Banish" , "Spell", "Destroy target minion or ritual",  0, 0,  2,0, 0, 10000,0,nullptr,nullptr}{}

void Banish::effect(int i,int p,char ch){
    if(ch=='r'){
    //Card * c =this->board->return_ri(p);
        this->board->remove(i,p,ch );
    //this->board->update_grave(c,p);
    }
    else {
       
       
       
        this->board->remove(i, p,ch );
       
    }
}

card_template_t Banish::getTemplate(){
    return display_spell(this->name,this->cardCost,this->description);
}
Trigger Banish::getTrigger() const {
    return Trigger::No;
}

Banish::~Banish(){}

//**************************Firework***********************//
Firework::Firework():Spell{ "Firework" , "Spell", "Deal 6 damage to oppsite player",  0, 0,  2,0, 0, 0,0,nullptr,nullptr}{}

//   void updateBoard(Board* b) override;
void Firework::effect(int i,int p,char ch) {
    Card* c;
    if(p==1){
        c=board->getPlayer(2);
    }
    else{
        c=board->getPlayer(1);
    }
    
    c->attacked(6);
}
card_template_t Firework::getTemplate(){
    return display_spell(this->name,this->cardCost,this->description);
}
Trigger Firework::getTrigger()  const {
    return Trigger::No;
}
Firework::~Firework(){}



//**************************Unsummon***********************//
Unsummon::Unsummon():Spell{ "Unsummon" , "Spell", "Put target minion on the bottom of its owner's deck",  0, 0,  1,0, 0, 0,0,nullptr,nullptr}{}
void Unsummon::effect(int i,int p,char ch){
    Card * c=this->board->return_min(i, p);
    this->board->update_deck(c,p);
    this->board->remove(i,p,'m');
    
}


card_template_t Unsummon::getTemplate(){
   return display_spell(this->name,this->cardCost,this->description);
}

Trigger Unsummon::getTrigger()  const {
    return Trigger::No;
}

Unsummon::~Unsummon(){}

//************************Recharge*************************//
Recharge::Recharge():Spell{ "Recharge" , "Spell", "Your ritual gains 3 charges",  0, 0,  1,0, 0, 0,0,nullptr,nullptr}{}

void Recharge::effect(int i,int p,char ch){
    Card * c=this->board->return_ri(p);
    
    if(c!=nullptr) c->addcharge(3);
}
card_template_t Recharge::getTemplate(){
    return display_spell(this->name,this->cardCost,this->description);
}

Trigger Recharge::getTrigger() const {
    return Trigger::No;
}


Recharge::~Recharge(){}

//*************************Disenchant*****************************//
Disenchant::Disenchant():Spell{ "Disenchant" , "Spell", "Destroy the top enchantment on target minion",  0, 0,  1,0, 0, 0,0,nullptr,nullptr}{}
void Disenchant::effect(int i,int p,char ch) {
    Card * c=this->board->return_min(i, p);
    if(c->getType()=="Enchantment"){
        Card * min=c->getCore();
        board->replace(min, p, i);
        c->updateCore(nullptr);
        delete c;
    }
}

card_template_t Disenchant::getTemplate(){
 return display_spell(this->name,this->cardCost,this->description);
}

Trigger Disenchant::getTrigger() const {
    return Trigger::No;
}

Disenchant::~Disenchant(){}

//**************************Raise Dead****************************//
RaiseDead::RaiseDead():Spell{ "Raise Dead" , "Spell", "Resurrect the top minion in your graveyard",  0, 0,  1,0, 0, 0,0,nullptr,nullptr}{}
void RaiseDead::effect(int i,int p,char ch) {
    this->board->resurrect(p);
}

card_template_t RaiseDead::getTemplate(){
 return display_spell(this->name,this->cardCost,this->description);
}

Trigger RaiseDead::getTrigger() const {
    return Trigger::No;
}
RaiseDead::~RaiseDead(){}

//**************************Blizzard*******************************//
Blizzard::Blizzard():Spell{ "Blizzard" , "Spell", "Deal 2 damage to all minions",  0, 0,  3,0, 0, 0,0,nullptr,nullptr}{}
void Blizzard::effect(int i,int p,char ch){
    this->board->attackAll();
}

// void Blizzard::updateBoard(Board *b) {
  //   this->board = b;}

card_template_t Blizzard::getTemplate() {
    return display_spell(this->name,this->cardCost,this->description);
}

Trigger Blizzard::getTrigger() const {
    return Trigger::No;
}

Blizzard::~Blizzard(){}
