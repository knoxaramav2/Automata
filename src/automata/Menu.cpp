#include "Menu.hpp"
#include "Color.hpp"
#include <unistd.h>

int splashMenu()
{
	Window win;
	
	bool active=true;
	
	const int options=2;
	bool selection=false;
	
	int height, width, ypos, xpos;
	win.getDimensions(height,width,ypos,xpos);
	
	
	while (active)
	{
	setColor(COLOR_GREEN, COLOR_BLACK);
	if (selection)
	{
		setColor(COLOR_RED, COLOR_BLACK);
		mvaddch(ypos+(height/2),xpos+(width/2)-6,'>');
		//mvaddch(ypos+(height/2),xpos+(width/2)-2,']');
	}
	mvprintw(ypos+(height/2),xpos+(width/2)-5,"New");
	if (selection)
		setColor(COLOR_GREEN, COLOR_BLACK);
	else
	{
		setColor(COLOR_RED, COLOR_BLACK);
		//mvaddch(ypos+(height/2),xpos+(width/2)+1,'[');
		mvaddch(ypos+(height/2),xpos+(width/2)+6,'<');
	}
	mvprintw(ypos+(height/2),xpos+(width/2)+2,"Load");
	//refresh();
	wrefresh(win.getHandle());
	wclear(win.getHandle());
	int opt=getch();
	switch(opt)
	{
		case KEY_LEFT: selection=true; break;
		case KEY_RIGHT: selection=false; break;
		case KEY_ENTER:
		return selection?MENU_LOAD:MENU_NEW;
		break;
		case 27: return MENU_QUIT;
		default: break;
	}
	}
	
	return 0;
}