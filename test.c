#include <ncurses.h>
#include <stdio.h>

#define ERROR 	"\x1B[31m"
#define SUCCESS "\x1B[32m"
#define RESET 	"\x1B[0m" 

/*
 * använd röd färg för fel,
 * grön färg för avklarade bokstäver,
 * ingen färg för normal text.
 */

int main()
{	
	initscr();

	if (has_colors() == FALSE){
		printf(ERROR "[Caligulaphy]\t\t" RESET);
		printf("Color might not be supported.\n");

	}

	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	mvaddch(0,0,'b');
	attroff(COLOR_PAIR(1));
	addch(getch());
	refresh();		
	getch();	
	endwin();

	return 0;
}
