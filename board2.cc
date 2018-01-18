//
//  board.cpp
//  a5
//
//  Created by 姚钰玮 on 2017-07-20.
//  Copyright © 2017 姚钰玮. All rights reserved.
//


#include <vector>
#include "board2.h"
#include "blankCard.h"
#include "minion.h"
#include "ritual.h"
using namespace std;


Board::Board(string name1, string name2){
  this->r1 = new BlankCard();
  this->r2 = new BlankCard();
  this->pc1 = new PlayerCard(name1, 1, 20, 0);
  this->pc2 = new PlayerCard(name2, 2, 20, 0);
  grave1.push_back(new BlankCard());
  grave2.push_back(new BlankCard());
}

void Board::display(){
  ctArray ct1, ct2, ct3, ct4;
  Card* blank = new BlankCard();
  Card* empty = new EmptyCard();
  ct1.push_back(r1->getTemplate());
  ct1.push_back(empty->getTemplate());
  ct1.push_back(pc1->getTemplate());
  ct1.push_back(empty->getTemplate());
  ct1.push_back(grave1[grave1.size()-1]->getTemplate());
  for(auto c : vec1){
    ct2.push_back(c->getTemplate());
  }
  for(int i=0;i<5-vec1.size();++i){
    ct2.push_back(blank->getTemplate());
  }
  for(auto c : vec2){
    ct3.push_back(c->getTemplate());
  }
  for(int i=0;i<5-vec2.size();++i){
    ct3.push_back(blank->getTemplate());
  }
  ct4.push_back(r2->getTemplate());
  ct4.push_back(empty->getTemplate());
  ct4.push_back(pc2->getTemplate());
  ct4.push_back(empty->getTemplate());
  ct4.push_back(grave2[grave2.size()-1]->getTemplate());
  displayTemplateArray(ct1);
  displayTemplateArray(ct2);
  for(auto s : CENTRE_GRAPHIC){
    cout << s << endl;
  }
  displayTemplateArray(ct3);
  displayTemplateArray(ct4);
  delete blank;
  delete empty;
}

void Board::update(Card* c, int p, int i){
  if (c->getType() == "BaseMinion"){
      if (p == 1){
          vec1.push_back(c);
      } else {
          vec2.push_back(c);
      }
  } else if (c->getType() == "Ritual"){
      if (p == 1){
          delete r1;
          r1 = c;
      } else {
          delete r2;
          r2 = c;
      }
  } else if (c->getType() == "Spell"){
      c->effect(i, p, 'n');
  } else {
    if (p == 1){
          vec1.erase(vec1.begin()+i-1);  
          vec1.emplace(vec1.begin()+i-1, c);
      } else {
          vec2.erase(vec2.begin()+i-1);
          vec2.emplace(vec2.begin()+i-1, c);
      }
  }
}

void Board::replace(Card* c, int p, int i){
  if (p == 1){
          vec1.erase(vec1.begin()+i-1);  
          vec1.emplace(vec1.begin()+i-1, c);
      } else {
          vec2.erase(vec2.begin()+i-1);
          vec2.emplace(vec2.begin()+i-1, c);
      }
}

void Board::update(){
  if(this->turn==1) this->turn=2;
  else{this->turn=1;}
}

Card* Board::return_min(int i,int p){
  if(p==1) return this->vec1[i-1];
  else return this->vec2[i-1];
}

Card* Board::return_ri(int p){
  if(p==1) return this->r1;
  else return this->r2;
}

Card* Board::getPlayer(int p){
    if (p == 1){
        return pc1;
    } else {
        return pc2;
    }
}

void Board::remove(int i, int p ,char ch){
    if(ch=='r'){
        if(p == 1){
      
      Card * ri=this->r1;
      delete ri;
      r1 = new BlankCard();
    }
    else {
        
      Card * ri=this->r2;
      delete ri;
      r2 = new BlankCard();
    }
        return;
    } else {
        if(p == 1){
            
          
            Card* c = vec1[i-1];
           if(ch != 'u'){
                grave1.push_back(c);
            }
             vec1.erase(vec1.begin()+i-1);
           
        }
        else{
            Card* c = vec2[i-1];
            if (ch != 'u'){
                grave2.push_back(c);
            }
            vec2.erase(vec2.begin()+i-1);
        }
    }
}

int Board::return_turn(){ return this->turn;}

void Board::update_deck(Card *c,int p){
    /*if(p==1) this->p1->add_deck_bottom(c);
    else this->p1->add_deck_bottom(c);*/
}

void Board::attackAll(){
    int m=this->vec1.size();
    int n=this->vec2.size();
    for(int j=0;j<m;j++){
        Card* c = this->vec1[j];
        c->attacked(2);
    }
    for(int j=m-1;j>=0;--j){
        Card* c = this->vec1[j];
        if(c->isDead()){
            
            remove(j+1, 1, 'm');
           
        }
    }
    
    for(int j=0;j<n;j++){
        Card* c = this->vec2[j];
        c->attacked(2);
    }
    for(int j=n-1;j>=0;--j){
        Card* c = this->vec2[j];
        if(c->isDead()){
            
            remove(j+1, 2, 'm');
           
        } 
    }
}

void Board::addAll(int p){
  if (p == 1){
    for(auto c : vec1){
      c->adddefenses(1);
    }
  } else {
    for(auto c : vec2){
      c->adddefenses(1);
    }
  }
}

void Board::summon(int n, int p){
  int num;
  if (p == 1){
    int max = 5-vec1.size();
    num = (max > n)? n : max;
    for (int i=0;i<num;++i){
      Card* c = new AirElemental();
      vec1.push_back(c);
       this->enterTrigger(p);
    }
    // if (n == 3){
    //   pc1->addMagic(-2);
    // } else {
    //   pc1->addMagic(-1);
    // }
  } else {
    int max = 5-vec2.size();
    num = (max > n)? n : max;
    for (int i=0;i<num;++i){
      Card* c = new AirElemental();
      vec2.push_back(c);
        this->enterTrigger(p);
    }
    // if (n == 3){
    //   pc2->addMagic(-2);
    // } else {
    //   pc2->addMagic(-1);
    // }
  }
}

void Board::resurrect(int p){
  if(p==1){
    Card* c=this->grave1.back();
    string name = c->getName();
    c = convert(name);
    this->vec1.push_back(c);
      this->enterTrigger(p);
    grave1.erase(grave1.begin()+grave1.size()-1);
  }
  else {
    Card* c=this->grave2.back();
    string name = c->getName();
    c = convert(name);
    this->vec2.push_back(c);
       this->enterTrigger(p);
    grave2.erase(grave2.begin()+grave2.size()-1);
  }
}

void addMagic(){
    
}
/*
ctArray Board::createTemplateArray(){
    ctArray cta;
    for(auto c : cards){
        cta.push_back(c->getTemplate());
    }
    return cta;
}*/
void Board::inspect(int i, int p){
  Card* c = return_min(i, p);
  card_template_t tmp;
  ctArray cta;
  string my_name;
  while (c != nullptr) {
    my_name = c->getMyName();
    if (my_name == "Giant Strength"){
      tmp = display_enchantment_attack_defence(my_name, 1, "", "+2", "+2");
    } else if (my_name == "Magic Fatigue") {
      tmp = display_enchantment(my_name, 0, "Enchanted minion's activated ability costs 2 more");
    } else if (my_name == "Silence") {
      tmp = display_enchantment(my_name, 1, "Enchanted minion cannot use abilities");
    } else {
      tmp = c->getTemplate();
    }
    cta.push_back(tmp);
    c = c->getCore();
  }
  const int L = cta.size();
  ctArray templist;
  int ctr = 0;
  bool end = false;
  tmp = cta.back();
  cta.pop_back();
  templist.push_back(tmp);
  displayTemplateArray(templist);
  templist.clear();
  ++ctr;
  while (!end){
    for (int i=0;i<5;++i){
      if (ctr == L) {
        end = true;
        break;
      }
      tmp = cta.back();
      cta.pop_back();
      templist.push_back(tmp);
      ++ctr;
    }
    displayTemplateArray(templist);
    templist.clear();
  }
}


void Board::displayTemplateArray(ctArray cta){
    card_template_t sample = cta[0];
    int cardLength = sample.size();
        int arrayLength = cta.size();
    
    for(int i=0;i<cardLength;++i){
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for(int j=0;j<arrayLength;++j){
            cout << cta[j][i];
        }
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        cout << endl;
    }
}

void Board::addToGrave(int p, Card* c){
    if (p == 1){
        grave1.push_back(c);
    } else {
        grave2.push_back(c);
    }
}

void Board::enterTrigger(int who) {
    int len1;
    int len2;
    bool dead;
    if (who==1) {

        len1 = this->vec1.size();
        if (len1 <= 0) {
          return;
        }
        //cout << "eg1" << endl;
        if (r1->getTrigger() == Trigger::Enter) {
            r1->effect(len1, 1, 'i');
        }
        //cout << "eg2" << endl;
        if (vec1[len1-1]->isDead()) {
          Board::remove(len1, 1, 'm');
          return;
        }
        //cout << "eg" << endl;
        len2 = this->vec2.size();
        if (len2 > 0) {
          
        //cout << "eg3 " << len2 << endl;
        for (int i=0; i<len2; i++) {
            if (vec2[i]->getTrigger() == Trigger::Enter) {
              //cout << "eg5 " << len1 << endl;
                vec2[i]->effect(len1, 1, 'n');
                //cout << "eg7 " << len1 << endl;
                cout << vec2[i]->getName() << endl;
                //cout << "eg6 " << len1 << endl;

            }
        }
      }
        if (vec1[len1-1]->isDead()) {
          Board::remove(len1, 1, 'm');
          return;
        }
        //cout << "eg4 " << len1 << endl;

        if ((r2->getTrigger() == Trigger::Enter)&&(r2->getName() == "Standstill")) {
              //cout << "destroy" << endl;
               r2->effect(len1, 1, 'i');
        }
        // if (vec1[len1-1]->isDead()) {
        //   Board::remove(len1, 1, 'i');
        //   return;
        // }
    } else {
        len2 = this->vec2.size();
        if (len2 <= 0) {
          return;
        }
        if (r2->getTrigger() == Trigger::Enter) {
            r2->effect(len2, 2, 'i');
        }
        if (vec2[len2-1]->isDead()) {
          Board::remove(len2, 2, 'm');
          return;
        }
        len1 = this->vec1.size();
        if (len1 > 0) {
          
        for (int i=0; i<len1; i++) {
            if (vec1[i]->getTrigger() == Trigger::Enter) {
                vec1[i]->effect(len2, 2, 'n');
            }
        }
      }
        if (vec2[len2-1]->isDead()) {
          Board::remove(len2, 2, 'm');
          return;
        }
        if ((r1->getTrigger() == Trigger::Enter)&&(r1->getName() == "Standstill")) {
            r1->effect(len2, 2, 'i');
        }
        if (vec2[len2-1]->isDead()) {
          Board::remove(len2, 2, 'i');
          return;
        }
    } 
}

void Board::endTrigger(int who) {
    int len;
    if (who==1) {
        len = this->vec1.size();
        for (int i=0; i<len; i++) {
            if (vec1[i]->getTrigger() == Trigger::End) {
                vec1[i]->effect(len, 1, 'n');
            }
        }
       
    } else {
        len = this->vec2.size();
        for (int i=0; i<len; i++) {
            if (vec2[i]->getTrigger() == Trigger::End) {
                vec2[i]->effect(len, 2, 'n');
            }
        }
        
    }     
}

void Board::startTrigger(int who) {
    int len;
    if (who==1) {
         if(r1==nullptr) return;
       
        if (r1->getTrigger() == Trigger::Start) {
         
            r1->effect(0, 1, 'r');
        }
          } else {
      if(r2==nullptr) return;
      
        if (r2->getTrigger() == Trigger::Start) {
            r2->effect(0, 2, 'r');
        }
        
    }     
}

void Board::update_grave(Card* c, int p){

}

void Board::addMagic(int i, int p){
  if(p==1) this->pc1->addMagic(i);
  else this->pc2->addMagic(i);
}

void Board::updatePlayer1(Player* p){
    p1 = p;
}

void Board::updatePlayer2(Player* p){
    p2 = p;
}



Board::~Board(){
    for(auto c : vec1){
        delete c;
    }
    for(auto c : vec2){
        delete c;
    }
    for(auto c : grave1){
        delete c;
    }
    for(auto c : grave2){
        delete c;
    }
    delete r1;
    delete r2;
    delete pc1;
    delete pc2;
}



Card* convert(string s){
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
      //  cout << s << endl;
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






