#ifndef LINKED_H
#define LINKED_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct item item;

typedef struct linked{
item* start;
}linked;

void put(linked* l, int number);
void get(linked* l, int pos);
void first(linked* l);
void last(linked* l);
void remo(linked* l, int pos);
void list(linked* l);
void clear(linked* l);
void sort(linked* l);

#endif
