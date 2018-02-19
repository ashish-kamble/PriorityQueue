# build an executable named myprog from myprog.c
all: main.c 
	gcc -g -Wall -o run main.c -lpthread

clean: 
	$(RM) run