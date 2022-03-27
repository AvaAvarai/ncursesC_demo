#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
  int y;
  int x;
  char *name;
  char rune;
} entity;

int initEntity(entity*, int, int, char*, char);
int freeEntity(entity*);

#endif
