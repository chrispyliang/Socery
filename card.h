#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include <vector>
#include "trigger.h"

typedef std::vector<std::string> card_template_t;

class Board;

class Card{
protected:
	std::string name;
	std::string type;
	std::string description;
	int magic;
	int activeCost;
	int cardCost;
	int charge;
	int chargeCost;
	int attacks;
	int defenses ;
	Board* board;
	Card* core;
	//Trigger trigger;
public:
	Card(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,
		int defenses,Board* board, Card* core);
    virtual void effect();
	virtual void effect(int i, int p, char ch);
	 std::string getName();
	 std::string getMyName();
	 std::string getType();
	 std::string getDescription();
	 //std::string getMyDescription();
	virtual card_template_t getTemplate() = 0;
	 int getMagic();
	 int getActiveCost();
	 //int getMyActiveCost();
	 int getCardCost();
	 int getCharge();
	 int getChargeCost();
   int getAttacks();
   //int getMyAttacks();
	 int getDefenses();
	 //itn getMyDefenses();
	 Card* getCore();

	 void addMagic(int i);
	void attack(Card* c);
  void attacked(Card* c);
	void attacked(int i);
	void addattacks(int i);
	void adddefenses(int i);
	void updateBoard(Board *b);
  void addcharge(int i);
	bool isDead();
	Card* returnMin();
	virtual ~Card() = default;
	virtual Trigger getTrigger() const = 0;
	void updateCore(Card* c);

};

//*******************Blank Card*********************//
/*class BlankCard: public BaseMinion{

};
*/
#endif

