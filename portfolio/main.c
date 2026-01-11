#include <ncurses.h>
#include <panel.h>
#include <unistd.h>
#include "include/home.h"
#include "include/resume.h"
#include "include/utils.h"
#include "logs/logs.h"

#define HOME 0
#define RESUME 1


int main(int argc, char* argv[]){
	initCurses();
	debug_init();
	int exit_code = 0;	

	printl("NEW RUN OF PROGRAM\n");
	printl("MAX X %d\nMAX Y %d\n",LINES,COLS);
	
	int npages = 2;
	View pages[npages];  
	pages[HOME] = newView(LINES,COLS,0,0);
	pages[RESUME] = newView(LINES,COLS,0,0);

	int curch = '1';
	int ch;
	redrawHome(pages[HOME], LINES, COLS, true);
	redrawResume(pages[RESUME], LINES, COLS, true);
	top_panel(pages[HOME].pan);
	update_panels();
	doupdate();
	while(1){
		ch = wgetch(stdscr);
		if(ch != ERR) printl("%d\n",ch);
		if(ch == 'q') break;
		if(ch == KEY_RESIZE){
			printl("%d %d\n",LINES,COLS);
			redrawHome(pages[HOME],LINES,COLS,true);
			redrawResume(pages[RESUME],LINES,COLS,true);
			goto update;
		}
		if((ch == '1' && ch != curch)){
			curch = ch;
			top_panel(pages[HOME].pan);
			redrawHome(pages[HOME], LINES, COLS,false);
		} 
		if((ch == '2' && ch != curch)){
			curch = ch;
			top_panel(pages[RESUME].pan);
			redrawResume(pages[RESUME], LINES,COLS,false);
		}

update:
		update_panels();
		doupdate();
		usleep(50000);
	}
cleanup:

	debug_close();
	closeCurses();
	return exit_code;
}
