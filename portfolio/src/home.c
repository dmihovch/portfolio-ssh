#include "../include/home.h"

void redrawHome(View home, int maxy, int maxx){

	if(home.resize){
		wclear(home.win);
		box(home.win, 0,0);
	}
	const char* home_msg = "Welcome to the Home Page";
	int home_len = strlen(home_msg);
	mvwprintw(home.win, 0,(maxx/2) - (home_len/2),"%s",home_msg);
}

