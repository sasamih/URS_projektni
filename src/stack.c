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
	if (*top_of_stack != NULL)
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
	}	
	return 1;
}

uint8_t top(type* element, stack_element* top_of_stack)
{
	if (!is_empty(top_of_stack))
	{
		*element = top_of_stack->el;
		return 0;
	}

	return 1;
}

uint8_t dump_stack(stack_element** top_of_stack)
{
	while (*top_of_stack != NULL)
	{
		type element;
		pop(&element, top_of_stack);
	}
	return 0;
}

uint8_t is_empty(stack_element* top_of_stack)
{
	if (top_of_stack != NULL)
	{
		return 0;
	}
	return 1;
}