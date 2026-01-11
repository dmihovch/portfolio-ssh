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
	while(1){
		ch = wgetch(stdscr);
		if(ch != ERR) printl("%d\n",ch);
		if(ch == 'q') break;
		if(ch == KEY_RESIZE){
			printl("%d %d\n",LINES,COLS);
			for(int i = 0; i<npages; i++){
				pages[i].resize = true;
			}
			continue;
		}
		if((ch == '1' && ch != curch)){
			curch = ch;
			top_panel(pages[HOME].pan);
			redrawHome(pages[HOME], LINES, COLS);
			pages[HOME].resize = false;
		} 
		if((ch == '2' && ch != curch)){
			curch = ch;
			top_panel(pages[RESUME].pan);
			redrawResume(pages[RESUME], LINES,COLS);
			pages[RESUME].resize = false;
		}
		update_panels();
		doupdate();
		usleep(50000);
	}
cleanup:

	debug_close();
	closeCurses();
	return exit_code;
}
