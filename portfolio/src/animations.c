#include "../include/animations.h"




void rain(int startx)
{
	int maxy = getmaxy(stdscr)-1;
	int maxx = getmaxx(stdscr)-1;
	char chs[CHARS] = {'&', '$', '@', '|', '%'};

	for(int i = 1; i<maxy; i++){

		char ch = chs[rand()%CHARS];
		if(rand()%2){
			startx = startx + 1;
		} else {
			startx = startx - 1;
		}
		clampx(&startx, maxx);
		mvaddch(i, startx, ch);
		usleep(10000);
	}
}
