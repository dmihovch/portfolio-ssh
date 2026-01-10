#include "../include/home.h"


Home* initHome(int maxy,int maxx){
	Home* home = malloc(sizeof(Home));
	if(home == NULL) return NULL;
	home->win = newwin(0,0,0,0);
	if(home->win == NULL) goto fail;
	home->pan = new_panel(home->win);
	if(home->pan == NULL) goto fail;

	box(home->win,0,0);
	windowOptions(home->win);
	redrawHome(home, maxy, maxx);
	top_panel(home->pan);
	return home;
	fail:
		freeHome(home);
		return NULL;

}

void freeHome(Home* home){
	if(home){
		if(home->pan) del_panel(home->pan);
		if(home->win) delwin(home->win);
	}
	free(home);
}



void redrawHome(Home* home, int maxy, int maxx){
	int err = top_panel(home->pan);
	printl("redrawing home, err = %d \n",err);

	const char* home_msg = "Welcome to the Home Page";
	int home_len = strlen(home_msg);
	mvwprintw(home->win, 0,(maxx/2) - (home_len/2),"%s",home_msg);
}
