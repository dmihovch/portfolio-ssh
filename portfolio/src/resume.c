#include "../include/resume.h"


void redrawResume(View resume, int maxy, int maxx, bool resize){

	if(resize){
		wclear(resume.win);
		box(resume.win,0,0);
	}

	const char* name = "Daniel Mihovch";
	mvwprintw(resume.win,0,center_text(maxx/2,strlen(name) ),"%s",name);
	//I think I should stop using center_text
	const char* contact = "732-239-5689 | dmihovch@udel.edu | linkedin.com/in/danielmihovch | github.com/dmihovch";
	mvwprintw(resume.win,1,center_text(maxx/2, strlen(contact)),"%s",contact);
	drawEducation(resume.win,2, 0, maxy,maxx);
	drawExperience(resume.win, 2, 0, maxy, maxx);
	return;
}


void drawEducation(WINDOW* win, int y, int x, int maxy, int maxx){

	const char* edu_title = "Education";
	mvwprintw(win,y,center_text(maxx/2, strlen(edu_title)),"%s",edu_title);
	const char* edu_school = "University of Delaware";
	mvwprintw(win,y+1, 1,"%s",edu_school);
	const char* edu_city = "Newark, DE";
	mvwprintw(win, y+1, maxx - (strlen(edu_city)+1),"%s",edu_city);



	const char* edu_major = "Bachelor of Science in Computer Science";
	mvwprintw(win,y+2,maxx-(strlen(edu_major)+1),"%s",edu_major);

	const char* edu_conc = "Concentration in Systems & Networks";
	mvwprintw(win,y+3,maxx-(strlen(edu_conc)+1),"%s",edu_conc);

	return;

}


void drawExperience(WINDOW* win, int y, int x, int maxy, int maxx){
	mvwprintw(win,maxy/2,maxx/2,"Experience");
	return;
}
