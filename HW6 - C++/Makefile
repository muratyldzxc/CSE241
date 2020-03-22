CC := g++

CFLAGS := --std=c++11

HDRS := 

SRCS := test.cpp GTUIterator.cpp GTUSet.cpp GTUVector.cpp bad_pafram.cpp  GTUIteratorConst.cpp

OBJS := $(SRCS:.c=.o)

EXEC := output

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
