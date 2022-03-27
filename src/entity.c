#include "entity.h"
#include <stdlib.h>

int initEntity(entity* ent, int b, int a, char *n, char r)
{
  if (!ent)
    return -1;
  ent->y = b;
  ent->x = a;
  ent->name = n;
  ent->rune = r;
  return 0;
}

int freeEntity(entity* ent)
{
  if(!ent)
    return -1;
  free(ent);
  return 0;
}
