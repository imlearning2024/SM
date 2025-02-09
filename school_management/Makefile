CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRCS = src/main.c src/admsn.c src/fee.c src/details.c src/var.c src/utils.c
OBJS = $(SRCS:.c=.o)

all: school_management

school_management: $(OBJS)
	$(CC) -o school_management $(OBJS)

clean:
	rm -f $(OBJS) school_management

