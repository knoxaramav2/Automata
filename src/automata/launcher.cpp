#include "Defs.hpp"
#include "Lib.hpp"
#include "Resource.hpp"
#include "Util.hpp"
#include "Menu.hpp"
#include "Color.hpp"
#include "Data.hpp"

#include <ncurses.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <unistd.h>

#define VERSION "1.0.0"

#if PLATFORM==PLATFORM_WINDOWS
	#include <windows.h>
#endif

using namespace std;

bool initialize()
{
	//initialize system data
	initscr();
	noecho();
	keypad(stdscr,true);
	raw();
	curs_set(0);//Won't work for windows users
	initColor();
	
	if (DEBUG)
		printw("%d : %d >> %s", PLATFORM, BITMODE, PLATFORM==PLATFORM_WINDOWS?"Windows":"Linux");	
	
	setColor(stdscr,COLOR_GREEN, COLOR_BLACK);
	
	return true;
}

void shutdown()
{

	endwin();
}

//input options
options CMD(int argc, char**argv)
{
	options opts;
	bool cnt=true;
	for (unsigned x=1; x<argc; ++x)
	{
		if (argv[x][0]!='-')
		continue;
		if (strlen(argv[x])==2)//toggle option
		{
			switch(argv[x][1])
			{
			case 'd': opts.debug=true;break;
			case 'g': opts.godmode=true;break;
			case 'v': printw("%s\n",VERSION); break;
			case 'x': cnt=false; break;
			default:
				printw("Unrecognized option\n");
				break;
			}
		}else//field option
		{
			
		}
	}
	if (!cnt)
		exit(0);
	return opts;
}

void splashScreen()
{
	int width=0, height=0;
	getmaxyx(stdscr,height,width);

	int tpos=0;
	bool ico=true;
	string text="Automata";
	int sx=(width/2)-(text.size()/2)-2;

	for (unsigned cycle=0; cycle<200; ++cycle)
	{
		if (cycle%20==0)
		{
			if (ico=!ico)
				{
					mvprintw(height/2,sx,">>");
				}
			else
				{
					mvprintw(height/2,sx,"  ");
				}
		}
		if (cycle%10==0&&tpos!=text.size())
		{
			mvaddch(height/2, sx+3+tpos, text[tpos]);
			++tpos;
		}
		refresh();
		usleep(30000);
	}
}


int main(int argc, char**argv)
{
	if (!initialize())
		return -1;
		
	registry reg;
	reg.opts=CMD(argc,argv);
	
	if (!reg.opts.debug)
		splashScreen();
	//loads data files
	
	//loads mods

	//select new/load
	clear();
	switch(splashMenu(reg))
	{
		case MENU_NEW:break;
		case MENU_LOAD:break;
		case MENU_BACK: exit(0); break;
	}

	//begin game

	shutdown();
	return 0;
}