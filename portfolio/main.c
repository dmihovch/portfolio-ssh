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

	int x_termsize;
	int y_termsize;
	int x_new_termsize;
	int y_new_termsize;

	int miny = 0;
	int minx = 0;
	int maxy = getmaxy(stdscr);
	int maxx = getmaxx(stdscr);

	printl("NEW RUN OF PROGRAM\n");
	printl("MAX X %d\nMAX Y %d\n",maxx,maxy);
	
	int npages = 2;
	View pages[npages];  
	pages[HOME] = newView(LINES, COLS, 0, 0);
	pages[RESUME] = newView(LINES,COLS,0,0);

	char curch = '1';
	char ch;
	while(1){
		//need to transition to just windows
		ch = wgetch(stdscr);
		if(ch != ERR) printl("%c\n",ch);
		if(ch == 'q') break;

		if(ch == (char)KEY_RESIZE){
			printl("old %d old %d\n",LINES,COLS);
			resizeterm(0, 0);
			printl("%d %d\n",LINES,COLS);
			handleResize(pages, npages);
			redrawHome(pages[HOME],LINES,COLS);
			redrawResume(pages[RESUME],LINES,COLS);
			continue;
		}
		if((ch == '1' && ch != curch)){
			curch = ch;
			top_panel(pages[HOME].pan);
			redrawHome(pages[HOME], maxy, maxx);
		} 
		if((ch == '2' && ch != curch)){
			curch = ch;
			top_panel(pages[RESUME].pan);
			redrawResume(pages[RESUME], maxy,maxx);
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
