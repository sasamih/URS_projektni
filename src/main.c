#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(int argc, char* argv[])
{
	stack_element* stack = NULL;
	char letter;

	if (pop(&letter, &stack) == 1)
		printf("%s\n", "Nema elemenata na steku!");

	push('a', &stack);

	push('b', &stack);
	push('c', &stack);

	pop(&letter, &stack);
	printf("%c\n", letter);

	top(&letter, stack);
	printf("%c\n", letter);

	dump_stack(&stack);

	// pop(&letter, &stack);
	// pop(&letter, &stack);

	if (top(&letter, stack) == 1)
		printf("%s\n", "Nema elemenata na steku!");	

	return 0;
}