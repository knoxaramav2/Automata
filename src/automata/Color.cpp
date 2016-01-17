#include "Color.hpp"

void initColor()
{
	start_color();
	//int dex=0;
	//initialize all colors
	for (int fg=0; fg<8; ++fg)
		for (int bg=0; bg<8; ++bg)
		{
			//++dex;
			init_pair(bg+(fg*8)+1, fg, bg);
			//attron(COLOR_PAIR(dex));
			//printw("%d %d %d >> %d\n", dex, fg, bg, bg+(fg*8)+1);
		}
}

void setColor(WINDOW*win,int fg, int bg)
{
	//Offset to min=1
	wattron(win,COLOR_PAIR(bg+(fg*8)+1));
}