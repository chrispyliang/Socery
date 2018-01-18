#include <iostream>
#include <string>
#include "player.h"
using namespace std;

Player::Player(string name, Deck* deck, Board* board, Hand* hand, int who,bool test)
:name(name), deck(deck), board(board), hand(hand), who(who),test(test){}

bool Player::isDead(){ 
	Card* c = board->getPlayer(who);
	if (c->getDefenses() <= 0) return true;
	else return false;
}

void Player::draw(){
    Card* c;
    if (hand->getLength() == 5){
        cout << "hand is full, cannot draw card" << endl;
        return;
    }
    
    if(this->test) {
     c = deck->getFirst();
    }else{
        c=deck->shuffle();
    }
       hand->update(c);
    
    cout << "draw a card" << endl;
}

void Player::discard(int i){
    Card *c=hand->getCard(i);
    delete c;
	cout << "discard " << i << endl;
}

void Player::attack(int i){
	
	Card* c1 =  board->return_min(i, who);
	Card* c2 = board->getPlayer(!who);
	c2->attacked(c1);
}

void Player::attack(int i, int j){
	cout << "attack " << i << " " << j << endl;
	Card* c1 = board->return_min(i, who);
	Card* c2 = board->return_min(j, !who);
	c1->attack(c2);
	if(c1->isDead()){
		
		board->remove(i, who, 's');
	}
	if(c2->isDead()){
		//cout << "hey c2 is dead" << endl;
		//cout << "the defenses of c2 is " << c2->getDefenses() << endl;
		board->remove(j, !who, 's');
	}
}

void Player::play(int i, int p){
    cout << "play " << i << endl;
    //cout << board << endl;
    Card* c = hand->getCard(i);
    //out << "kkkkkk" << endl;
    int cost = c->getCardCost();
    Card* player = board->getPlayer(p);
    int magic = player->getMagic();
    if (cost > magic && test == 0){
        cout << "You don't have enough magic" << endl;
        hand->putBack(c, i);
        return;
    }
    if (c->getType() == "Spell"){
        c->updateBoard(board);
        //cout << "hhhhh" << endl;
        c->effect(1, who, 's');
    } else {
        c->updateBoard(board);
        board->update(c, p, 100);
        board->enterTrigger(p);
    }
    if (test == 0) player->addMagic(-1 * cost);
}

void Player::play(int i, int j, char r){
    cout << "play " << i << " " << j << " " << r << endl;
    //cout << board << endl;
    Card* c = hand->getCard(i);
    int cost = c->getCardCost();
    Card* player = board->getPlayer(j);
    int magic = player->getMagic();
    if (cost > magic && test == 0){
        cout << "You don't have enough magic" << endl;
        hand->putBack(c, i);
        return;
    }
    if (r == 'r') {
        c->effect(100, j, r);
    } else if (c->getType() == "Enchantment") {
        int a = r - '0';
        c->updateBoard(board);
        //cout<<"entantment"<<endl;
        Card* min = board->return_min(a, j);
        //cout<<"entantment2"<<endl;
        c->updateCore(min);
        board->update(c, j, a);
        //cout << "haha666" << endl;
    } else {
        //cout << "haha1" << endl;
        int a = r - '0';
        c->updateBoard(board);
        //cout<< "haha2"<<endl;
        c->effect(a, j, 's');
        //cout << "haha2" << endl;
    } if (test == 0) player->addMagic(-1 * cost);
}

void Player::use(int i, int p){
    cout << "use " << i << endl;
    Card* c = board->return_min(i, p);
    int cost = c->getActiveCost();
    //cout<<cost<<endl;
    Card* player = board->getPlayer(p);
    int magic = player->getMagic();
    if (cost > magic && test == 0){
        cout << "You don't have enough magic" << endl;
        //hand->putBack(c, i);
        return;
    }
    c->effect(i, p, 'm');
    if (test == 0) player->addMagic(-1 * cost);
}

void Player::use(int i, int j, char r){
	cout << "use " << i << " " << j << " " << r <<  endl;
    cout << "use " << i << endl;
    int m=0;
    
    if(j==1){ m=2;}
    else{ m=1;}
    
    cout<<m<<endl;
    int a = r - '0';
    
    Card* c = board->return_min(i, m);
    //cout<<"I am here"<<endl;
    int cost = c->getActiveCost();
    //cout<<"player1"<<endl;
    Card* player = board->getPlayer(m);
    int magic = player->getMagic();
    if (cost > magic && test == 0){
        cout << "You don't have enough magic" << endl;
        //hand->putBack(c, i);
        return;
    }
    cout<<a<<endl;
    c->effect(a, j, r);
    if (test == 0) player->addMagic(-1 * cost);
}

void Player::inspect(int i, int p){
	cout << "inspect " << i << p << endl;
    if (p == 1){
        board->inspect(i, 1);
    } else {
        board->inspect(i, 2);
    }
}

void Player::displayHand(){
	//hand->display();
	cout << "display hand" << name << endl;
	hand->display();
}

void Player::displayBoard(){
	//board->display();
	cout << "display board" << endl;
	board->display();
}
void Player::magicUpdate(int p,int i){
    Card* c = board->getPlayer(p);
    int magic=c->getMagic();
    c->addMagic(i-magic);
}
void Player::magicUpdate(int p){
	//++magic;
    //++magic;
    cout << "magic update" << endl;
    Card* c = board->getPlayer(p);
    c->addMagic(1);}

void Player::add_deck_bottom(Card* c){
    deck->addToBack(c);
}

string Player::getName(){
	return name;
}











