#include "Util.hpp"
#include <unistd.h>

void typewrite(string line, int y, int x)
{
move(y,x);
for (char c: line)
	{
	addch(c);
	refresh();
	usleep(1000);
	}
}