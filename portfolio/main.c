#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#define CHARS 5


void rain(int startx){

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
		usleep(100000);
	}
}


void initCurses(){
	initscr();
	curs_set(0);
	noecho();
}

void closeCurses(){
	endwin();
}

int main(int argc, char* argv[]){
	initCurses();
	mvprintw(10,10,"Hello world");
	refresh();
	rain(10);
	rain(20);
	rain(30);
	getch();
	closeCurses();
	return 0;
}
