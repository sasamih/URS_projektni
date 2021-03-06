#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t type;

struct element
{
	type el;
	struct element* next;
};

typedef struct element stack_element;

uint8_t push(type element, stack_element** top_of_stack);
uint8_t pop(type* element, stack_element** top_of_stack);
uint8_t top(type* element, stack_element* top_of_stack);
uint8_t dump_stack(stack_element** top_of_stack);
uint8_t is_empty(stack_element* top_of_stack);