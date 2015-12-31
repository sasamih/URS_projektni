#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef char type;

struct element
{
	type el;
	struct element* next;
};

typedef struct element stack_element;

uint8_t push(type element, stack_element** top_of_stack);
uint8_t pop(type* element, stack_element** top_of_stack);
