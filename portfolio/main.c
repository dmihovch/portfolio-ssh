#include "include/animations.h"
#include "include/utils.h"


int main(int argc, char* argv[]){
	initCurses();


	mvprintw(10,10,"Hello world");
	refresh();
	rain(10);
	rain(30);
	rain(50);
	getch();
	closeCurses();
	return 0;
}
