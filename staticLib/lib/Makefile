TAGART := staticLib.a
CC := gcc
LD := ld
CCFLAGS := -Wall -g
LDFLAGS := -fPIC -share

SRC := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRC))

all:$(OBJS)
	$(LD) $(LDFLAGS) -o $(TAGART) $(OBJS)

%.o:%.c
	$(CC) -c $(CCFLAGS) $< -o $*.o

.PHONY: clean
clean:
	rm *.a *.o -rf
