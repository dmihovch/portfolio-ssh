#include <ncurses.h>
#include <panel.h>
#include <unistd.h>
#include "include/home.h"
#include "include/resume.h"
#include "include/utils.h"
#include "logs/logs.h"


#define NUMBOLTS 5

int main(int argc, char* argv[]){
	initCurses();
	debug_init();
	

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


	Resume* resume = initResume(maxy,maxx);
	if(resume == NULL){
		printl("resume == NULL");
		goto cleanup;
	} 

	Home* home = initHome(maxy, maxx);
	if(home == NULL) {
		printl("home == NULL");
		goto cleanup;
	}

	char curch = '1';
	char ch;
	while(1){

		if(curch == '1') ch = wgetch(home->win);
		if(curch == '2') ch = wgetch(resume->win);
		if(ch != ERR){
			printl("%c\n",ch);
		}
		if(ch == 'q') break;
		if(ch == (char)KEY_RESIZE) {
			//handleResize will handle everything that needs to be done before next loop iteration
			continue;
		}
		if(ch == '1' && ch != curch){
			curch = ch;
			redrawHome(home, maxy, maxx);
		} 
		if(ch == '2' && ch != curch){
			curch = ch;
			redrawResume(resume, maxy,maxx);
		}
		update_panels();
		doupdate();
		usleep(50000);
	}
	

cleanup:

	freeResume(resume);
	freeHome(home);

	debug_close();
	closeCurses();
	return 0;
}
