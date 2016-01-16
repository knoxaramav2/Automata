#ifndef TERMINAL_H
#define TERMINAL_H

#include <ncurses.h>

/*
Controls window graphics
*/

class winEnvironment
{

};

class Window
{
	WINDOW*win;
	int xpos, ypos, width, height;
	public:
	Window(int height, int width, int ypos, int xpos);
	Window();
	~Window();
	WINDOW*getHandle();
	void getDimensions(int&,int&,int&,int&);
};


#endif