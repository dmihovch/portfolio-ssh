#include "../include/animations.h"




void rain(int startx)
{
	int maxy = getmaxy(stdscr);
	int maxx = getmaxx(stdscr);
	char chs[CHARS] = {'&', '$', '@', '|', '%'};

	for(int i = 0; i<maxy; i++){

		char ch = chs[rand()%CHARS];
		if(rand()%2){
			startx = startx + 1;
		} else {
			startx = startx - 1;
		}
		clampx(&startx, maxx);
		mvaddch(i, startx, ch);
		boxRefresh(stdscr);
		usleep(10000);
	}
}
