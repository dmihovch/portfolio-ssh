#include "../include/resume.h"
#include <ncurses.h>

void redrawResume(Page* resume){
	WINDOW* resume_win = resume->win;
	int y,x;
	getmaxyx(resume_win, y, x);
	mvwprintw(resume_win,y/2,x/2,"Daniel Mihovch, Computer Science Major @ UD");
}

