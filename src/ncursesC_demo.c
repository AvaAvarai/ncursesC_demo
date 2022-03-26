#include <ncurses.h>
#include "entity.h"

int main()
{
  int ch;
  int row, col;
  int y, x;
  
  entity player;
  player.name = "player";
  player.rune = '@';

  initscr();
  start_color();
  curs_set(0);

  getmaxyx(stdscr, row, col);
  player.y = (row / 2);
  player.x = (col / 2);
  ch = -1;

  raw();
  keypad(stdscr, TRUE);
  noecho();

  entity test;
  test.name = "test";
  test.y = 10;
  test.x = 10;
  test.rune = 'x';
  
  while(ch != 27)
  {
     clear();
     move(0, 0);

     printw("MAX(%d:%d) SELF(%d:%d) KEY(%d) ESC to exit", row, col, player.y, player.x, ch); 
     mvaddch(player.y, player.x, player.rune | A_BOLD);
     mvaddch(test.y, test.x, test.rune);
     refresh();

     ch = wgetch(stdscr);
     switch(ch) {
       case 119: // w
       case 56:  // keypad 8
       case KEY_UP:
         --player.y;
         break;
       case 115: // s
       case 50:  // keypad 2
       case KEY_DOWN:
         ++player.y;
         break;
        case 97: // a
        case 52: // keypad 4
        case KEY_LEFT:
          --player.x;
          break;
        case 100: // d
        case 54:  // keypad 6 
        case KEY_RIGHT:
          ++player.x;
          break; 
    }
  }

  endwin();
  return 0;
}
