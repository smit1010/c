TAGART := callShareLib 
CC := gcc
LD := ld
CCFLAGS := -Wall -g
INC :=../lib
LIB := ../lib

SRC := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRC))

all:$(OBJS)
	$(CC) $(OBJS) -o $(TAGART)  -L$(LIB) -lshareLib

%.o:%.c
	$(CC) -c $(CCFLAGS) $< -o $*.o -I$(INC) 

.PHONY: clean
clean:
	rm  *.o $(TAGART) -rf
