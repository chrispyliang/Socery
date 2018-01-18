//#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "player.h"
//#include "deck.h"
//#include "board.h"
#include "baseMinion.h"

using namespace std;

int main(int argc, char* argv[]){
	bool turn = false;
    int round=0;
	int n;
	int i;
	bool quit = false; // if player quit the game
	bool test = false; // if it's in testing mode or not
	string s, st; 
	string file; // filename
	string line; // store each line from file or input
	
	string deck1name="";
	string deck2name="";
	string name1="Player 1";
	string name2="Player 2";
    
    //cout<<"arg"<<endl;
	for (int i=1; i<argc; i++) {
        istringstream sstr{argv[i]};
        
        string tests;
        sstr>>tests;
        
		if (tests=="-deck1") {
			i++;
			deck1name = argv[i];
			cout << tests << endl;
		} else if (tests=="-deck2") {
			i++;
			deck2name = argv[i];

		} else if (tests=="-init") {
			i++;
			file = argv[i];
		} else if (tests=="-testing") {
			test = true;
		}
	}

	ifstream f;
	f.open(file);
	f >> name1 >> name2;

	cout << "filename is " << file << endl;
	cout << "name 1 is " << name1 << endl;
	cout << "name 2 is " << name2 << endl; 
	cout << deck1name << " " << deck2name << " " << file << endl;

	Board b(name1, name2);
	
	Deck d1; // player1's deck
	Deck d2; // player2's deck
	

	cout << "loading Player1's deck" << endl;
	d1.load(deck1name);
	d2.update(&b);
	cout << "loading Player2's deck" << endl;
	d2.load(deck2name);
	d2.update(&b);

	Hand h1;
	Hand h2;

	istringstream ss;
	
	Player p1 = Player(name1, &d1, &b, &h1, 1, test);
	Player p2 = Player(name2, &d2, &b, &h2, 0, test);
    
    b.updatePlayer1(&p1);
    b.updatePlayer2(&p2);
    
    p1.draw();
    p1.draw();
    p1.draw();
    p2.draw();
    p2.draw();
    p2.draw();
    p2.draw();
    p1.magicUpdate(1);
    p1.magicUpdate(1);
    p2.magicUpdate(2);
    p2.magicUpdate(2);
    p2.magicUpdate(2);

/*
	
	d1.display();
	d2.display();*/


	while (true) {
        round++;
        int roundtotal=round/2;
		//cout << "hahaha3" << endl;
		turn = !turn; // alter the player's turn
		if (turn) {
			//cout << "hahaha422" << endl;
			cout << "Now it's " << p1.getName() <<  "'s turn" << endl;
			p1.draw();
			//cout << "hello2" << endl;
			p1.magicUpdate(1,roundtotal+3);
			//cout << "hello3" << endl;
		} else {
			cout << "Now it's " << p2.getName() << "'s turn" << endl;
			p2.draw();
			//cout << "hello2" << endl;
			p2.magicUpdate(2,roundtotal+3);
		}
		while (true) {
			//cout << "hello5" << endl;
			/*if (getline(f, line)) {
				istringstream ss{line};
			} else if (getline(cin, line)){
				istringstream ss{line};
				// istringstream ss(s);
			} else {
				break;
			}*/
			//cout << "hello6" << endl;
			if (f >> s);
			else cin >> s;
			if (s == "help") {
				cout << "Commands: help -- Display this message." << endl;
				cout << "end -- End the current player's turn." << endl;
				cout << "quit -- End the game." << endl;
				cout << "attack minion other-minion -- Orders minion to attck other-minion." << endl;
				cout << "attck minion -- Orders minion to attack the opponent." << endl;
				cout << "play card [target-player target-card]";
				cout << " -- Play card, optionally targeting target-card owned by target-player." << endl;
				cout << "use minion [target-player target-card] -- ";
				cout << "Use minion's ability, optionally targeting target-card owned by target-player." << endl;
				cout << "inspect minion -- View a minion's card and all enchatments on that minion." << endl;
				cout << "hand -- Describe all cards in your hand" << endl;
				cout << "board -- Describe all cards on the board." << endl;
			} else if (s == "end") {
				break;
			} else if (s == "quit") {
				quit = true;
				break;
			} else if (s == "attack") {
				if (getline(f, st)); 
				else getline(cin, st);
				istringstream ss{st};
				int j;
				ss >> n;
				if (ss >> j) {
					if (turn) {
						p1.attack(n, j);
						b.display();
					}	else {
						p2.attack(n, j);
						b.display();
					}
				} else {
					if (turn) {
						p1.attack(n);
						if (p2.isDead()){
							cout << "Player 1 Wins!!!!!" << endl;
							quit = true;
						}
					} else {
						p2.attack(n);
						if (p1.isDead()){
							cout << "Player 2 Wins!!!!!" << endl;
							quit = true;
						}
					}
				}
			} else if (s == "discard") {
				//cout << "hey I am discard" << endl;
				if (test) {
					if (f >> n);
					else cin >> n;
					if (turn) {
						p1.discard(n);	
					} else {
						p2.discard(n);
					}
				} else {
					cout << "discard not allowed in play mode";
					cout << endl;
				}
			} else if (s == "draw"){
				if (test) {
					if (turn) {
						p1.draw();
						h1.display();
					} else {
						p2.draw();
						h2.display();
					}
				} else {
					cout << "draw not allowed in play mode";
					cout << endl;
				}
			} else if (s == "play") {
				if (getline(f, st));
				else getline(cin, st);
				istringstream ss{st};
				int p;
				char t;
				ss >> n;
				if (ss >> p) {
					ss >> t;
					if (turn) {
						p1.play(n, p, t);
					} else {
						p2.play(n, p, t);
					}
				} else {
					if (turn) {
						p1.play(n, 1);
						b.display();
					} else {
						p2.play(n, 2);
						b.display();
					}
				}
			} else if (s == "use") {
				if(getline(f, st));
				else getline(cin, st);
				istringstream ss{st};
				int p;
				char t;
				ss >> n;
				if (ss >> p) {
					ss >> t;
					if (turn) {
						p1.use(n, p, t);
					} else {
						p2.use(n, p, t);
					}
				} else {
					if (turn) {
						p1.use(n, 1);
					} else {
						p2.use(n, 2);
					}
				}
			} else if (s == "inspect") {
				int p;
				if (f >> n >> p);
				else cin >> n >> p;
				if (turn) {
					p2.inspect(n, p);
				} else {
					p1.inspect(n, p);
				}
			} else if (s == "hand") {
				//cout << "hello11" << endl;
				if (turn) {
					p1.displayHand();
				} else {
					p2.displayHand();
				}
			} else if (s == "board") {
				b.display();
			} 
		}
		if (quit) {
			break;
		}
		if (turn) {
			b.endTrigger(1);
			b.startTrigger(2);
		} else {
  		    b.endTrigger(2);
			b.startTrigger(1);
		}
	}
}
