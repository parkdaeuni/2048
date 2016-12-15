#include <curses.h>

void help(){
	char ch;

	clear();

	mvprintw( 8, 20, " Left     is    'LEFT KEY, a, h' ");
	mvprintw( 9, 20, " Right    is    'RIGHT KEY, d, l' ");
	mvprintw(10, 20, " Down     is    'DOWN KEY, s, j' ");
	mvprintw(11, 20, " Up       is    'UP KEY, w, k'");
	mvprintw(13, 20, " Quit     is    'q' ");
	mvprintw(14, 20, " Restart  is    'r' ");
	mvprintw(16, 20, " Press a key to Continue..");
	move(LINES-1, COLS-1);
	refresh();

	ch = getchar();
}
