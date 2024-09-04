#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList *next;
    struct linkedList *prev;
} Node;

void addNode(Node **start, int value);
void insertNode(Node **start, int valueAfterInsert, int value);
void deleteNode(Node **start, int value);
void printList(const Node *start, int isInvert);
void freeList(Node **start);

#endif