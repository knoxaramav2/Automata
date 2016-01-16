#include "Terminals.hpp"

Window::Window(int height, int width, int ypos, int xpos)
{
	win=newwin(height,width,ypos,xpos);
	box(win, 0, 0);
	wrefresh(win);
	
	this->height=height;
	this->width=width;
	this->ypos=ypos;
	this->xpos=xpos;
}

Window::Window()
{
	int x=0,y=0;
	getmaxyx(stdscr,y,x);
	int width=x/2;
	int height=y/2;
	int xpos=x/4;
	int ypos=y/4;
	win=newwin(height,width,ypos,xpos);
	box(win, 0, 0);
	wrefresh(win);
	
	this->height=height;
	this->width=width;
	this->ypos=ypos;
	this->xpos=xpos;
}

Window::~Window()
{
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
}

WINDOW*Window::getHandle()
{
	return win;
}

void Window::getDimensions(int&height, int&width, int&ypos, int&xpos)
{
	height=this->height;
	width=this->width;
	ypos=this->ypos;
	xpos=this->xpos;
}