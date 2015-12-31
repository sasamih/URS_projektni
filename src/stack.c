#include "stack.h"

uint8_t push(type element, stack_element** top_of_stack)
{
	stack_element* new_element;
	new_element = (stack_element*) malloc(sizeof(stack_element));

	if (new_element != NULL)
	{
		new_element->el = element;
		new_element->next = *top_of_stack;
		*top_of_stack = new_element;

		return 0;
	}

	return 1;
}

uint8_t pop(type* element, stack_element** top_of_stack)
{
	stack_element* top_element;
	top_element = (stack_element*) malloc(sizeof(stack_element));

	if (top_element != NULL)
	{
		top_element = *top_of_stack;
		*element = top_element->el;
		*top_of_stack = top_element->next;
		free(top_element);
		top_element = NULL;

		return 0;
	}

	return 1;
}