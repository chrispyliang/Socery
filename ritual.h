//
//  ritual.hpp
//  a5
//
//  Created by 姚钰玮 on 2017-07-16.
//  Copyright © 2017 姚钰玮. All rights reserved.
//

#ifndef ritual_h
#define ritual_h

#include <stdio.h>
#include "card.h"
#include <string>
#include "ascii_graphics.h"
#include "trigger.h"

class Board;
class Ritual: public Card {
    //std::string type = "Ritual";
protected:
  //  int active_cost;
   // int charge;
    
public:
    //virtual void effect(int i,int p,char ch)=0;
    Ritual(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
           int defenses,Board*board, Card* core);
    card_template_t getTemplate() override;
    //void add_ritual(int i);
    //std::string getType() override;
    virtual ~Ritual();

};
class BrightRitual: public Ritual {
public:
    BrightRitual();
    void effect(int i,int p,char ch) override;
    Trigger getTrigger() const override;
    card_template_t getTemplate() override;
    ~BrightRitual();


};

class DarkRitual: public Ritual {
    /*std::string name="Dark Ritual";
    std::string type="Ritual";
    std::string description="At the start of your turn, gain 1 magic";
    int magic=0;
    int activeCost=1;
    int cardCost=1;
    int charge=5;
    int chargeCost=0;
    int attacks=0;
    int defenses=0;
    Board* board=nullptr;*/
    

public:
    DarkRitual();
    void effect(int i,int p,char ch) override;
    Trigger getTrigger()  const override;
    card_template_t getTemplate() override;
    ~DarkRitual();

};

class AuraofPower: public Ritual{
   /* std::string name="Aura of Power";
    std::string type="Ritual";
    std::string description="Whenever a minion enters play under your control, it gains +1/+1";
    int magic=0;
    int activeCost=1;
    int cardCost=1;
    int charge=4;
    int chargeCost=0;
    int attacks=0;
    int defenses=0;
    Board* board=nullptr;
    */

public:
    AuraofPower();
    void effect(int i,int p,char ch) override;
    Trigger getTrigger()  const override ;
    card_template_t getTemplate() override;
    ~AuraofPower();
};

class Standstill: public Ritual {
    /*std::string name="Standstill";
    std::string type="Ritual";
    std::string description="Whenever a minion enters play, destroy it";

    int magic=0;
    int activeCost=2;
    int cardCost=3;
    int charge=4;
    int chargeCost=0;
    int attacks=0;
    int defenses=0;
    Board* board=nullptr;
    */

public:
    Standstill();
    void effect(int i,int p,char ch) override;
    Trigger getTrigger() const override;
    card_template_t getTemplate() override;
    ~Standstill();

};

#endif /* ritual_hpp */

