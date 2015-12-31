#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 255

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

	printf("Unesite matematicku formulu: ");
	char formula[MAX_SIZE];
	fgets(formula, MAX_SIZE, stdin);
	printf("Unijeli ste: %s\n",formula);

	uint8_t formula_length = 0;
	while(formula[formula_length] != '\0')
	{
		formula_length++;
	}

	uint8_t i = 0;
	for (i = 0; i < formula_length; i++)
	{
		if ('(' == formula[i])
		{
			push(i, &stack);
		}

		if (')' == formula[i])
		{
			uint8_t open_index;
			if (pop(&open_index, &stack) == 0)
			{
				printf("Par zagrada na indeksima %d i %d\n", open_index, i);
			}
			else
			{
				printf("Unijeta formula nije regularan matematicki izraz!\n");
				return 1;
			}
		}
	}

	if (is_empty(stack))
	{
		printf("Unijeta formula nije regularan matematicki izraz!\n");
		dump_stack(&stack);
		return 1;
	}

	return 0;
}