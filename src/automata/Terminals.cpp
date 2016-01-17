#include "Terminals.hpp"

Window::Window(int height, int width, int ypos, int xpos)
{
	win=newwin(height,width,ypos,xpos);
	box(win, 0, 0);
	wrefresh(win);
	
	id=0;
	
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
	
	id=0;
	
	this->height=height;
	this->width=width;
	this->ypos=ypos;
	this->xpos=xpos;
}

Window::~Window()
{
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	
	//free controls
}

void Window::rebuildBorder()
{
	box(win, 0, 0);
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

void Window::update()
{
	
	
	//input loop: send to focus control (if any)
}


Window * winEnvironment::registerWindow()
{
	bool valid=true;
	unsigned id=0;
	
	do{
	++id;
	for (unsigned x=0; x<windows.size(); ++x)
		if (windows[x]->id==id)
			{
			valid=false;
			break;
			}
	}while(!valid);
	
	Window * ret = new Window();
	ret->id=id;
	
	windows.push_back(ret);
	
	return ret;
}

bool winEnvironment::deregisterWindow(Window*win)
{	
	if (win==NULL)
		return false;
	
	for (unsigned x=0; x<windows.size(); ++x)
	{
		if (windows[x]==win)
		{
			delwin(win->getHandle());
			windows.erase(windows.begin()+x);
			delete win;
			render();
			return true;
		}
	
	}
	
	
	return false;	
}

void winEnvironment::render()
{
	clear();
	refresh();
	for (unsigned x=0; x<windows.size(); ++x)
		if (windows[x]!=NULL)
			wrefresh(windows[x]->getHandle());
	
}

void winEnvironment::render(Window*win)
{
if (win!=NULL)
	wrefresh(win->getHandle());
}

void winEnvironment::update()
{
	
}

