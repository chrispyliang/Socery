//
//  minion.hpp
//  a5
//
//  Created by 姚钰玮 on 2017-07-16.
//  Copyright © 2017 姚钰玮. All rights reserved.
//

#ifndef _BASE_MINION_H_
#define _BASE_MINION_H_

#include <stdio.h>
#include "minion.h"
#include "trigger.h"

class Board;
class BaseMinion: public Minion{
	std::string type = "BaseMinion";
public:
  BaseMinion(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
    int defenses,Board* board, Card* core);
     ~BaseMinion();
  
};



//*******************Player Card********************//
/*class PlayerCard: public BaseMinion{

};

*/

class BaronGeddon: public BaseMinion {
public:
    BaronGeddon();
  card_template_t getTemplate() override;
  void effect(int i, int p, char ch) override;
  Trigger getTrigger() const override;
  ~BaronGeddon();
};


//*******************Earth Elemental****************//


class EarthElemental: public BaseMinion {
 public:
    EarthElemental();
	void effect(int i,int p,char ch) override;
  	card_template_t getTemplate() override;
 	
 	Trigger getTrigger() const override;
 	~EarthElemental();
  
};

//******************Air Elemental***********************//

class AirElemental: public BaseMinion {
 	public:
    AirElemental();
  
 	card_template_t getTemplate() override;
 	void effect(int i, int p, char ch) override;
 	Trigger getTrigger() const override;
 	~AirElemental();
};

//******************Fire Elemental***********************//

class FireElemental: public BaseMinion {
 	public:
    FireElemental();
	
 	card_template_t getTemplate() override;
 	void effect(int i, int p, char ch) override;
 	Trigger getTrigger() const override;
 	~FireElemental();
};

//******************Potion Seller***********************//


class PotionSeller: public BaseMinion {
public:
    PotionSeller();
	
 	card_template_t getTemplate() override;
 	void effect(int i, int p, char ch) override;
 	Trigger getTrigger() const override;
 	~PotionSeller();
};

//******************Novice Pyromancer***********************//

class NovicePyromancer: public BaseMinion {
 	public:
    NovicePyromancer();
 	card_template_t getTemplate() override;
 	void effect(int i, int p, char ch) override;
 	Trigger getTrigger() const override;
 	~NovicePyromancer();
};

//******************Apprentice Summoner***********************//

class ApprenticeSummoner : public BaseMinion {
public:
    ApprenticeSummoner();
 	card_template_t getTemplate() override;
 	void effect(int i, int p, char ch) override;
 	Trigger getTrigger() const override;
 	~ApprenticeSummoner();
};

//******************Master Summoner***********************//

class MasterSummoner: public BaseMinion {
 	

public:
    MasterSummoner();
	
 	card_template_t getTemplate() override;
 	void effect(int i, int p, char ch) override;
 	Trigger getTrigger() const override;
 	~MasterSummoner();
};













#endif /* minion_hpp */

