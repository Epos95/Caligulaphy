#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ERROR 	"\x1B[31m"
#define SUCCESS "\x1B[32m"
#define RESET 	"\x1B[0m" 

#define SUCCESS_PAIR 1
#define ERROR_PAIR 2


/*
 * använd röd färg för fel,
 * grön färg för avklarade bokstäver,
 * ingen färg för normal text.
 */


int main()
{	
	char str[32] = "ah hello there";

	initscr();
	noecho();

	if (has_colors() == FALSE){
		printf(ERROR "[Caligulaphy]\t\t" RESET);
		printf("Color might not be supported.\n");
		exit(1);

	}

	start_color();
	init_pair(SUCCESS_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(ERROR_PAIR, COLOR_RED, COLOR_BLACK);

	mvprintw(10,10,str);

	char input;
	char current;
	int start_of_word = 0;
	int length_of_word = 0;
	for (int i=0; i < strlen(str); i++){
		move(10,10+i);

		current = str[i];
		input = getch();
		if (current == ' ') {
			// ordet är slut










			start_of_word = i+1;
			// sätt nytt start för ett nytt ord
			length_of_word = 0;
			// resetta längden av ordet

		}


		if(input == current){
			attron(COLOR_PAIR(SUCCESS_PAIR));
			mvaddch(10,10+i, current);
			attroff(COLOR_PAIR(SUCCESS_PAIR));
		} else {
			attron(COLOR_PAIR(ERROR_PAIR));
			mvaddch(10,10+i, current);
			attroff(COLOR_PAIR(ERROR_PAIR));
		}
		refresh();		
	}

	mvprintw(12,13, "You did well!\tpress any key to exit.");
	getch();	
	endwin();

	return 0;
}
