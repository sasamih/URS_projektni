#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(int argc, char* argv[])
{
	stack_element* stack = NULL;

	push('a', &stack);
	push('b', &stack);
	push('c', &stack);

	char letter;
	pop(&letter, &stack);
	printf("%c\n", letter);

	return 0;
}