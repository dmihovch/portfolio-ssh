#include "include/animations.h"
#include "include/utils.h"
#include <string.h>


#define NUMBOLTS 5

int main(int argc, char* argv[]){
	initCurses();
	int miny = 1;
	int minx = 1;
	int maxy = getmaxy(stdscr)-2;
	int maxx = getmaxx(stdscr)-2;
	Lightning bolts[NUMBOLTS];
	for(int i = 0; i<NUMBOLTS; i++){
		bolts[i] = createLightning(10+i*20);
	}
	



		const char* msg = "Daniel Mihovch";
		int len = strlen(msg);
		CycleLetter* str = createCycleString(msg, len, 10, 10, 100);
		if(str == NULL) return 1;

	while(1 ){
		char ch = getch();
		if(ch == 'q') break;


		for(int i = 0; i<NUMBOLTS; i++){
		 	if(bolts[i].y < maxy) updateLightning(&bolts[i], maxy,maxx );
		}
		
		updateCycleString(str, len);


		refresh();
		usleep(50000);
	}

	free(str);

	closeCurses();
	return 0;
}
