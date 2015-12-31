CC=gcc

all: static_lib stack

.PHONY: static_lib stack

SRCS = ./src/main.c
LIBS_PATH = -L./libs

static_lib:
	gcc -c src/stack.c -o build/stack.o
	ar rc libs/libstack.a build/stack.o
	ranlib libs/libstack.a

stack:
	$(CC) $(SRCS) $(LIBS_PATH) -lstack -o main