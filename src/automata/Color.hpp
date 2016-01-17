#ifndef COLOR_H
#define COLOR_H

#include <ncurses.h>

void initColor();
void setColor(WINDOW*,int fg, int bg);

#endif