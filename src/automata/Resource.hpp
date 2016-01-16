#ifndef RESOURCE_H
#define RESOURCE_H
/*
Stores game resources such as graphics and audio
*/
#include <stdio.h>
#include <string>

using namespace std;

class rscRepository
{
	bool loadSprite(string);
	bool loadTile(string);
	bool loadSpriteSheet(string);
};

#endif