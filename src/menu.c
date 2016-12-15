#include <stdio.h>
#include <curses.h>

#define MENUSTR0 "*************"
#define MENUSTR1 "  GAME START "
#define MENUSTR2 "    OPTION   "
#define MENUSTR3 "    RECORD   "
#define MENUSTR4 "     HELP    "
#define MENUSTR5 "     EXIT    "

int display_menu();
void print_menu(int);
void print_standout_menu(int);

int display_menu(){
	int choice=1;
	int cur_l, cur_c;
	cur_l = 15;
	cur_c = 31; 
	
	clear();

	mvprintw(3,5, "      2222222222   0000000000   44           8888888888 ");
	mvprintw(4,5, "              22   00      00   44           88      88 ");
	mvprintw(5,5, "              22   00      00   44           88      88 ");
	mvprintw(6,5, "              22   00      00   44    44     88      88 ");
	mvprintw(7,5, "              22   00      00   44    44     88      88 ");
	mvprintw(8,5, "      2222222222   00      00   4444444444   8888888888 ");
	mvprintw(9,5, "      22           00      00         44     88      88 ");
	mvprintw(10,5,"      22           00      00         44     88      88 ");
	mvprintw(11,5,"      22           00      00         44     88      88 ");
	mvprintw(12,5,"      22           00      00         44     88      88 ");
  	mvprintw(13,5,"      2222222222   0000000000         44     8888888888 ");
	
	move(cur_l, cur_c);
	addstr(MENUSTR0);
	move(cur_l + 1, cur_c);
	standout();
	addstr(MENUSTR1);
	standend();
	move(cur_l + 2, cur_c); 
	addstr(MENUSTR2);
	move(cur_l + 3, cur_c);
	addstr(MENUSTR3);
	move(cur_l + 4, cur_c);
	addstr(MENUSTR4);
	move(cur_l + 5, cur_c);
	addstr(MENUSTR5);
	move(cur_l + 6, cur_c);
	addstr(MENUSTR0);
	move(LINES-1, COLS-1);
	refresh();
	
	while(1){
		int ch;
		ch = getchar();

		if(ch == 32 || ch == 13){ // enter or space bar
			return choice;

		}
		else if(ch == 0x1B){
			ch = getchar();
			if(ch != 0x5B)
				continue;
			ch = getchar();
			
			switch(ch){
				case 0x41: // Up
					move(cur_l + choice , cur_c);
					print_menu(choice--);
					if(choice <= 0)
						choice += 5;
					move(cur_l + choice, cur_c);
					print_standout_menu(choice);
					break;
				case 0x42: //down
					move(cur_l + choice , cur_c);					
					print_menu(choice++);
					if(choice > 5)
						choice -= 5;
					move(cur_l + choice , cur_c);
					print_standout_menu(choice);
					break;
			}
			move(LINES-1, COLS-1);
			refresh();
		}
	}
}

void print_standout_menu(int choice){
	standout();
	switch(choice){
		case 1:
			addstr(MENUSTR1);
			break;
		case 2:
			addstr(MENUSTR2);
			break;
		case 3:
			addstr(MENUSTR3);
			break;
		case 4:
			addstr(MENUSTR4);
			break;
		case 5:
			addstr(MENUSTR5);
			break;
	}
	standend();
}

void print_menu(int choice){
	switch(choice){
		case 1:
			addstr(MENUSTR1);
			break;
		case 2:
			addstr(MENUSTR2);
			break;
		case 3:
			addstr(MENUSTR3);
			break;
		case 4:
			addstr(MENUSTR4);
			break;
		case 5:
			addstr(MENUSTR5);
			break;
	}
	standend();
}	
