#include "include/animations.h"
#include "include/utils.h"

#include <pthread.h>
#define REFRESH_RATE 16667


typedef struct {
	int running;
}State;

void* refreshThread(void* payload){
	State* state = payload;
	while(state->running){
		wrefresh(stdscr);
		usleep(REFRESH_RATE);
	}
	return NULL;	
}



int main(int argc, char* argv[]){




	initCurses();

	pthread_t refresher;

	State* state = (State*)malloc(sizeof(State));
	state->running = 1;
	pthread_create(&refresher, NULL, refreshThread,state);

	mvprintw(10,10,"Hello world");
	refresh();
	rain(10);
	rain(30);
	rain(50);
	getch();


	
	 pthread_join(refresher,NULL);
	
	 free(state);

	closeCurses();
	return 0;
}
