SRCS = double_list.c main.c

OBJS = $(SRCS:.c=.o)

ProgramaLD: double_list.o main.o

	gcc -Wall main.c double_list.c -o main

clean:

	rm -f main $(OBJS)

run:

	./main
