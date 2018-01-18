#ifndef _MINION_H_
#define _MINION_H_
#include "card.h"

class Board;
class Minion: public Card{

public:
	Minion(std::string name ,std::string type, std::string description, int magic,int activeCost, int cardCost,int charge,int chargeCost,int attacks,int defenses,Board*board, Card* core);
	//std::string getType() = 0;
 //   ~Minion();
};


#endif

