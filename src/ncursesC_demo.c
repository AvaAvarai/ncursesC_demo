#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "entity.h"

#define MAX_ENTITIES 64

int main()
{
  FILE *log = fopen("log.txt", "w");

  int ch;
  int row, col;
  int y, x;
  
  initscr();
  start_color();
  curs_set(0);

  getmaxyx(stdscr, row, col);

  entity* player = malloc(sizeof(entity));
  initEntity(player, (row / 2), (col / 2), "player", '@');

  raw();
  keypad(stdscr, TRUE);
  noecho();

  entity** entities = malloc(MAX_ENTITIES * sizeof(entity));
  
  int entity_count = 0;

  entity* test = malloc(sizeof(entity));
  initEntity(test, 10, 10, "test", 'q');
  
  entities[entity_count++] = test;

  while(ch != 27)
  {
     clear();
     move(0, 0);

     printw("MAX(%d:%d) SELF(%d:%d) KEY(%d) EC(%d) ESC to exit", row, col, player->y, player->x, ch, entity_count); 
     mvaddch(player->y, player->x, player->rune | A_BOLD);
     
     for (int i=0; i<MAX_ENTITIES; i++)
     {
       entity* check = entities[i];
       fprintf(log, "checking index: %d\n", i);
       if(check) {
         mvaddch(check->y, check->x, check->rune);
         fprintf(log, "printing index: %d\n", i);
       }
      }

     refresh();

     ch = wgetch(stdscr);
     switch(ch)
     {
       case 119: // w
       case 56:  // keypad 8
       case KEY_UP:
         --player->y;
         break;
       case 115: // s
       case 50:  // keypad 2
       case KEY_DOWN:
         ++player->y;
         break;
        case 97: // a
        case 52: // keypad 4
        case KEY_LEFT:
          --player->x;
          break;
        case 100: // d
        case 54:  // keypad 6 
        case KEY_RIGHT:
          ++player->x;
          break; 
     }
  }

  freeEntity(player);
  freeEntity(test);
  fclose(log);
  endwin();
  return 0;
}
