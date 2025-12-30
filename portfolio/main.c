#include "include/animations.h"
#include <string.h>
#include <panel.h>

#define NUMBOLTS 5

int main(int argc, char* argv[]){
	initCurses();
	int miny = 1;
	int minx = 1;
	int maxy = getmaxy(stdscr)-2;
	int maxx = getmaxx(stdscr)-2;
	//
	//
	// Lightning bolts[NUMBOLTS];
	// for(int i = 0; i<NUMBOLTS; i++){
	// 	bolts[i] = createLightning(10+i*20);
	// }
	//
	// const char* msg = "Daniel Mihovch";
	// int len = strlen(msg);
	// CycleLetter* str = createCycleString(msg, len, 10, 10, 10);
	// if(str == NULL) return 1;
	//

	WINDOW* win = newwin(0,0,0,0);
	WINDOW* win2 = newwin(0,0,0,0);
	PANEL* pan = new_panel(win);
	PANEL* pan2 = new_panel(win2);


	
	box(win, 0, 0);
	mvwprintw(win, 10,10, "WIN1 GOOBYE WORLD");
	mvwprintw(win2, 20,20, "WIN2 HELLO WORLD");
		
	while(3){
		char ch = getch();
		if(ch == 'q') break;
		if(ch == '1'){
			top_panel(pan);
		} 
		if(ch == '2'){
			top_panel(pan2);
		}
		update_panels();
		doupdate();
		
		




		









		//
		// for(int i = 0; i<NUMBOLTS; i++){
		// 	if(bolts[i].y < maxy) updateLightning(&bolts[i], maxy,maxx );
		// }
		//
		// updateCycleString(str, len);
		
	
		usleep(50000);

	}

	closeCurses();
	return 0;
}
