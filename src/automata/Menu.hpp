#ifndef MENU_H
#define MENU_H

#include "Terminals.hpp"
#include "Data.hpp"

//OPTIONS
#define MENU_NEW	1
#define MENU_LOAD	2
#define MENU_SAVE	3
#define MENU_YES	4
#define MENU_NO		5
#define MENU_BACK	6
#define MENU_QUIT	7
#define MENU_CANCEL	8

int splashMenu(registry&);
int newGameMenu(registry&);
int loadGameMenu(registry&);

#endif