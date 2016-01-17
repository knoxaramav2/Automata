#ifndef TERMINAL_H
#define TERMINAL_H

#include <ncurses.h>
#include <vector>
#include <string>

using namespace std;

/*
Controls window graphics
*/

enum winCtrlCode
{
	_NA,
	_textField,
	_textArea,//multiline
	_loadBar,
	_console,
	_button,
	_frame
};

struct winControl
{
	winCtrlCode wcode;
};

struct textField : public winControl
{
	string data;
	WINDOW*win;
};

struct textArea : public winControl
{
	string data;
	WINDOW*win;
};

struct loadBar : public winControl
{
	string data;
	WINDOW*win;
};

struct console : public winControl
{
	string data;
	WINDOW*win;
};

struct button : public winControl
{
	string data;
	WINDOW*win;
};

struct frame : public winControl
{
	string data;
	WINDOW*win;
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
	void rebuildBorder();
	
	vector <winControl*> controls;
	winControl*focusControl;//control to receive input
	
	unsigned id;
	
	void update();
};

class winEnvironment
{
vector <Window*>windows;

public:

Window * registerWindow();
bool deregisterWindow(Window*);

void bringToFront(Window*);//focus window
void sendToBack(Window*);

void render();
void render(Window*);

void update();

};

#endif