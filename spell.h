//
//  spell.hpp
//  a5
//
//  Created by 姚钰玮 on 2017-07-16.
//  Copyright © 2017 姚钰玮. All rights reserved.
//

#ifndef spell_h
#define spell_h

#include <stdio.h>
#include "card.h"
#include "ascii_graphics.h"
#include "trigger.h"

class Board;

class Spell: public Card {
    //std::string type = "Spell";
    
public:
    //virtual void effect(int i,int p,char ch)=0;
    //virtual card_template_t getTemplate()=0;
    Spell(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
          int defenses,Board*board, Card* core);
    //std::string getType() override;
     virtual ~Spell();

};

class Banish: public Spell {
/*std::string name = "Banish";
std::string type = "Spell";
std::string description = "Destroy target minion or ritual";
    
    int magic=0;
    int activeCost=0;
    int cardCost=2;
    int charge=0;
    int chargeCost=0;
    int attacks=10000;
    int defenses=0;
    Board* board=nullptr;*/
public:
    Banish();
    void effect(int i,int p,char ch) override;
    card_template_t getTemplate() override;
    Trigger getTrigger() const override;
    ~Banish();
};

class Unsummon: public Spell {
 /*   std::string name = "Unsummon";
    std::string type = "Spell";
    std::string description = "Put target minion on the bottom of its owner's deck";
    int magic=0;
    int activeCost=0;
    int cardCost=1;
    int charge=0;
    int chargeCost=0;
    int attacks=0;
    int defenses=0;
    Board* board=nullptr;*/
    
public:
    Unsummon();
    void effect(int i,int p,char ch) override;
    card_template_t getTemplate() override;
    Trigger getTrigger()  const override ;
    ~Unsummon();
};

class Firework: public Spell{
public:
    Firework();
    //   void updateBoard(Board* b) override;
    void effect(int i,int p,char ch) override;
    card_template_t getTemplate() override;
    Trigger getTrigger()  const override ;
    ~Firework();

};


class Recharge: public Spell {
   /* std::string name = "Recharge";
    std::string type = "Spell";
    std::string description = "Your ritual gains 3 charges";
    int magic=0;
    int activeCost=0;
    int cardCost=1;
    int charge=0;
    int chargeCost=0;
    int attacks=0;
    int defenses=0;
    Board* board=nullptr;*/

public:
    Recharge();
    void effect(int i,int p,char ch) override;
    card_template_t getTemplate() override;
    Trigger getTrigger()  const override ;
    ~Recharge();

    
};

class Disenchant: public Spell {
 /*   std::string name = "Disenchant";
    std::string type = "Spell";
    std::string description = "Destroy the top enchantment on target minion";
    int magic=0;
    int activeCost=0;
    int cardCost=1;
    int charge=0;
    int chargeCost=0;
    int attacks=0;
    int defenses=0;
    Board* board=nullptr;*/

public:
    Disenchant();
    void effect(int i,int p,char ch) override;
    card_template_t getTemplate() override;
    Trigger getTrigger()  const override ;
    ~Disenchant();

};


class RaiseDead: public Spell {
   /* std::string name = "Raise Dead";
    std::string type = "Spell";
    std::string description = "Resurrect the top minion in your graveyard";
    int magic=0;
    int activeCost=0;
    int cardCost=1;
    int charge=0;
    int chargeCost=0;
    int attacks=0;
    int defenses=0;
    Board* board=nullptr;*/

public:
    RaiseDead();
    void effect(int i,int p,char ch) override;
    card_template_t getTemplate() override;
    Trigger getTrigger()  const override ;
    ~RaiseDead();
};

class Blizzard: public Spell {
   /* std::string name = "Blizzard";
    std::string type = "Spell";
    std::string description = "Deal 2 damage to all minions";
    int magic=0;
    int activeCost=0;
    int cardCost=3;
    int charge=0;
    int chargeCost=0;
    int attacks=2;
    int defenses=0;
    Board* board=nullptr;*/

public:
    Blizzard();
 //   void updateBoard(Board* b) override;
    void effect(int i,int p,char ch) override;
    card_template_t getTemplate() override;
    Trigger getTrigger()  const override ;
    ~Blizzard();
    
};
#endif /* spell_hpp */

