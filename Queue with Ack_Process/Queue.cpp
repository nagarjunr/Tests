//Queue.cpp

#include "Queue.h"
#include <string.h> //For strcpy

void Enqueue(char *Queue_Element);
void Dequeue();
void Display_Queue();
void Init_Queue();

Queue_Node *New, *Front, *Rear, *Temp, *Display_Node; 

void Init_Queue()
{
	Rear = NULL;
	Front = NULL;
}

void Enqueue(char *Queue_Element)
{
	New = (Queue_Node*)malloc(sizeof(Queue_Node));
	//printf("Enter the Ack Data : ");
	//scanf("%s",New->Data);
	strcpy(New->Data, Queue_Element);

	New->next = NULL;
	if(Front == NULL)
	{
		Front = New;
		Rear = New;
	}
	else
	{
		Rear->next = New;
		Rear = New;
	}
	printf("\nA Queue Element is Created : %s\n",New->Data);
}

void Dequeue()
{
	Temp = Front;
	if(Temp == NULL)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		printf("The Deleted data is : %s\n",Temp->Data);
		Front = Temp->next;
		free(Temp);
	}
}

void Display_Queue()
{
	Display_Node = Front;
	if(Display_Node == NULL)
	{
		printf("The Queue is Empty\n");
	}
	else
	{
		printf("\nOldest Data--->");
		while(Display_Node != NULL)
		{
			printf("%s--->",Display_Node->Data);
			Display_Node = Display_Node->next;
		}
		printf("Newest Data\n");
	}
}