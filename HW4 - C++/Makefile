CC := g++

CFLAGS := --std=c++11

HDRS := NPuzzle.h

SRCS := main.cpp NPuzzle.cpp

OBJS := $(SRCS:.c=.o)

EXEC := output

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
