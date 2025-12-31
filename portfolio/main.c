#include "include/animations.h"
#include <string.h>
#include <panel.h>
#include "include/page.h"
#include "include/utils.h"
#include "logs/logs.h"

#define NUMBOLTS 5




int main(int argc, char* argv[]){
	initCurses();
	debug_init();
	



	int miny = 0;
	int minx = 0;
	int maxy = getmaxy(stdscr)-2;
	int maxx = getmaxx(stdscr)-2;

	debug_logf("MAX X %d\nMAX Y %d\n",maxx,maxy);
	

	Lightning* bolts = malloc(NUMBOLTS*sizeof(Lightning));
	if(bolts == NULL)return 1;

	for(int i = 0; i<NUMBOLTS; i++){
		bolts[i] = createLightning(10+i*20, miny);
	}

	const char* msg = "Daniel Mihovch";
	int len = strlen(msg);
	CycleLetter* str = createCycleString(msg, len, 10, 10, 10);
	if(str == NULL) return 1;


	Page home;  
	home.win = newwin(0, 0, 0,0);
	home.pan = new_panel(home.win);

	Page resume; 
	resume.win = newwin(0,0,0,0);
	resume.pan = new_panel(resume.win);

	Page animations; 
	animations.win = newwin(0,0,0,0);
	animations.pan = new_panel(animations.win);
	
	box(home.win, 0, 0);
	box(resume.win,0,0);
	box(animations.win,0,0);

	const char* home_msg = "Welcome to the Home Page";
	int home_len = strlen(home_msg);
	mvwprintw(home.win, 0,(maxx/2) - (home_len/2),home_msg);


	const char* resume_msg = "Welcome to the Resume Page";
	int resume_len = strlen(resume_msg);
	mvwprintw(resume.win, 0,(maxx/2) - (resume_len/2), resume_msg);


	Page pages[3] = {home,resume,animations};
		
	top_panel(home.pan);
	int current_page_idx;
	Page* current_page = &pages[0];


	while(1){
		char ch = getch();
		if(ch == 'q') break;
		if(ch == '1'){
			top_panel(home.pan);
			current_page = &pages[0];
		} 
		if(ch == '2'){
			top_panel(resume.pan);
			current_page = &pages[1];
		}
		if(ch == '3'){
			top_panel(animations.pan);
			resetLightning(animations.win, bolts, NUMBOLTS);
			box(animations.win, 0,0);
			current_page = &pages[2];
		}

		//updatePage(current_page, current_page.function); create a field in Page to store a function pointer
	
		updateAllLightning(animations.win, bolts, NUMBOLTS, maxy, maxx);

		update_panels();
		doupdate();
		usleep(50000);
	}

	debug_close();
	closeCurses();
	return 0;
}
