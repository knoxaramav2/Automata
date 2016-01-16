#include "Color.hpp"

void initColor()
{
	start_color();
	
	//initialize all colors
	for (int fg=0; fg<8; ++fg)
		for (int bg=0; bg<8; ++bg)
		{
			init_pair((fg+1)*(bg+1), fg, bg);
			refresh();
		}
	
}

void setColor(int fg, int bg)
{
	//Offset to min=1
	++fg;
	++bg;
	attron(COLOR_PAIR(fg*bg));
}