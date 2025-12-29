#include "../include/animations.h"




void rain(int startx)
{
	int maxy = getmaxy(stdscr);
	char chs[CHARS] = {'&', '$', '@', '|', '%'};

	for(int i = 0; i<maxy; i++){

		char ch = chs[rand()%CHARS];
		if(rand()%2){
			startx = startx + 1;
		} else {
			startx = startx - 1;
		}
		mvaddch(i, startx, ch);
		refresh();
		usleep(10000);
	}
}
