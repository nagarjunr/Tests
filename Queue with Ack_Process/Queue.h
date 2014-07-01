//Queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

extern void Init_Queue();
extern void Enqueue(char *Queue_Element);
extern void Dequeue();
extern void Display_Queue();

typedef struct node
{
	char Data[1000];
	struct node *next;
}Queue_Node;

extern Queue_Node *New, *Front, *Rear, *Temp, *Display_Node;
#endif