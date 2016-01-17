#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
Contains game data structures

*/

struct options
{
	bool debug : 1;
	bool godmode : 1;
	
	options();
};

struct item
{
	long long unsigned id;
};

struct player
{
	long long unsigned id;
	unsigned money;
	float reputation;

	string name;

	player(string);
};

class registry
{
	
public:
	options opts;
	
	vector <player> players;//loaded players
	vector <item*> items;//base game objects
};



bool createNewGame(string, registry&);
bool saveGame(string, registry&);


#endif