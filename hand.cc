#include <iostream>
#include <string>
#include "hand.h"
using namespace std;

void Hand::display(){
	displayTemplateArray(createTemplateArray());
}

void Hand::update(Card* c){
	
	cards.push_back(c);
}

Card* Hand::getCard(int i){
	Card* c = cards[i-1];
	cards.erase(cards.begin()+i-1);
	return c;
}

ctArray Hand::createTemplateArray(){
	ctArray cta;
	for(auto c : cards){
		cta.push_back(c->getTemplate());
	}
	return cta;
}

void Hand::displayTemplateArray(ctArray cta){
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
int Hand::getLength(){
    return cards.size();
}

void Hand::putBack(Card* c, int i){
		cards.emplace(cards.begin()+i-1, c);
}


Hand::~Hand(){
	for(auto c : cards){
		delete c;
	}
}
