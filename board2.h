//
//  board.hpp
//  a5
//
//  Created by 姚钰玮 on 2017-07-20.
//  Copyright © 2017 姚钰玮. All rights reserved.
//

#ifndef board_h
#define board_h

#include <stdio.h>
#include "card.h"
#include <vector>

#include "ascii_graphics.h"
#include "card.h"
#include "spell.h"
#include "ritual.h"
#include "Enchantment.h"
#include "baseMinion.h"
#include "deck.h"
#

class Player;
class Board {
    std::vector <Card* > vec1;
    std::vector <Card* > vec2;
    std::vector <Card* > grave1;
    std::vector <Card* > grave2;
    Card* r1;
    Card* r2;
    Card* pc1;
    Card* pc2;
    Player* p1;
    Player* p2;
    int turn;
    
public:
    Board(std::string name1, std::string name2);
    //void player_update(Player *p1,Player *p2);
    void display();
    Card* return_ri(int p);
    Card* getPlayer(int p);
    Card* return_min(int i, int p);
    // ith element from either t p1 f p2 or or in ritual_grave;
    //type: g=graveyard r=ritual m=min
    void update(Card* c,int p, int i);
    void replace(Card* c, int p, int i);
    //put card from hand to board
    void update();//update turn
    int return_turn();
    void update_deck(Card* c,int p);
    void attackAll();
    void addAll(int p);
    void summon(int n, int p);
    void remove(int i, int p, char ch);//remove ith card from board
    void resurrect(int p);
    void addMagic(int i, int p);
    //ctArray createTemplateArray();
    void displayTemplateArray(ctArray cta);
    void addToGrave(int p, Card* c);
    void endTrigger(int who);
    void startTrigger(int who);
    void enterTrigger(int who);
    void update_grave(Card* c, int p);
    void updatePlayer1(Player* p);
    void updatePlayer2(Player* p);
    void inspect(int i, int p);
    //void addMagic(int i, int p);
    ~Board();
};
Card* convert(std::string name);
#endif /* board_hpp */

