#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stack.h"

#define MAX_SIZE 255

#define ASSERT(x,y) if(ERROR == x){ \
						printf("\n%s\n", y); \
						return 1; \
					}

typedef enum t_Error
{
	NO_ERROR = 0,
	ERROR = 1
}t_Error;

t_Error checkFormula(char formula[]);

#endif