CC := g++

CFLAGS := --std=c++11

HDRS := AbstractBoard.h BoardArray2D.h BoardArray1D.h BoardVector.h

SRCS := test.cpp AbstractBoard.cpp BoardArray2D.cpp BoardArray1D.cpp BoardVector.cpp

OBJS := $(SRCS:.c=.o)

EXEC := output

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
