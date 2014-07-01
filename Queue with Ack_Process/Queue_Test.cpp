//Queue_Test.cpp
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

int main()
{
	char test_str[] = "OK:123\0";

	Init_Queue();
	Enqueue(test_str);
	Enqueue(test_str);
	Enqueue(test_str);
	Enqueue(test_str);
	Enqueue(test_str);
	Display_Queue();
	Dequeue();
	Display_Queue();

	return 0;
}