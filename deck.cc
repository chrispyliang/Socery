#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "deck.h"
#include "baseMinion.h"
#include <cstdlib>
using namespace std;

void Deck::update(Board* b) {
	for (int i=0; i<cards.size(); i++) {
		cards[i]->updateBoard(b);
	}
}

void Deck::addToBack(Card* c){
    cards.push_back(c);
}
Card* Deck::shuffle(){
    int len=this->cards.size();
    int i= rand()%len +0;
    
    Card* c = cards[i];
    //cout << "the card is " << c->getName() << endl;
    cards.erase(cards.begin()+i);
    return c;


}
void Deck::load(string filename){
	if(filename == ""){
		filename = "default.deck";
	}
	ifstream ifs(filename);
	string s;
	while(!ifs.eof()){
		getline(ifs,s);
		Card* c;
		c = convert(s);
		
		
		cards.push_back(c);
		
	}
	
}

void Deck::display(){
	displayTemplateArray(createTemplateArray());
}

Card* Deck::getFirst(){
	Card* c = cards[0];
	cout << "the card is " << c->getName() << endl;
	cards.erase(cards.begin());
	return c;
}

ctArray Deck::createTemplateArray(){
	ctArray cta;
	for(auto c : cards){
		cta.push_back(c->getTemplate());
	}
	return cta;
}

void Deck::displayTemplateArray(ctArray cta){
	card_template_t sample = cta[0];
	int cardLength = sample.size();
		int arrayLength = cta.size();
	
	for(int i=0;i<cardLength;++i){
		for(int j=0;j<arrayLength;++j){
			cout << cta[j][i];
		}
		cout << endl;
	}
}


Card* Deck::convert(string s){
	Card* c;
	if(s == "Earth Elemental"){
		c = new EarthElemental();
		
		//cout << s << endl;
	}
	else if(s == "Air Elemental"){
		c = new AirElemental();
		//cout << s << endl;
	} 
	else if(s == "Fire Elemental"){
		c = new FireElemental();
		//cout << s << endl;
	}
	else if(s == "Potion Seller"){
		c = new PotionSeller();
		//cout << s << endl;
	}
	else if(s == "Novice Pyromancer"){
		c = new NovicePyromancer();
		//cout << s << endl;
	}
	else if(s == "Apprentice Summoner"){
		c = new ApprenticeSummoner();
		//cout << s << endl;
	}
	else if(s == "Master Summoner"){
		c = new MasterSummoner();
			//	cout << s << endl;
	}
	else if(s == "Banish"){
		c = new Banish();
		//cout << s << endl;
	}
	else if(s == "Unsummon"){
		c = new Unsummon();
		//cout << s << endl;
	}
	else if(s == "Recharge"){
		c = new Recharge();
		//cout << s << endl;
	}
	else if(s == "Disenchant"){
		c = new Disenchant();
		//cout << s << endl;
	}
	else if(s == "Raise Dead"){
		c = new RaiseDead();
		//cout << s << endl;
	}
	else if(s == "Blizzard"){
		c = new Blizzard();
		//cout << s << endl;
	}
	else if(s == "Giant Strength"){
		c = new GiantStrength();
		//cout << s << endl;
	} 
	else if (s == "Magic Fatigue"){
		
		c = new MagicFatigue();
		
		//cout << s << endl;
	} 
	else if (s == "Silence"){
		c = new Silence();
		//cout << s << endl;
	} 
	else if (s == "Dark Ritual"){
		c = new DarkRitual();
		//cout << s << endl;
	} 
	else if (s == "Aura of Power"){
		c = new AuraofPower();
		//cout << s << endl;
	} 
	else if (s == "BaronGeddon") {
  	  	c = new BaronGeddon();
    	//cout << s << endl;
  	} else if (s == "Standstill"){
		c = new Standstill();
		//cout << s << endl;
	} else if (s == "Immortal") {
    	c = new Immortal();
    	//cout << s << endl;
  	}  else if (s == "Firework")  {
    	c = new Firework();
    	//cout << s << endl;
  	} else if (s == "BrightRitual") {
  		c = new BrightRitual();
  		//cout << s << endl;
  	} else {
		c = new FireElemental();
		//cout << s << endl;
	}
	
	return c;
}
