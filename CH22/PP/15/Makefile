TARGET = justify
CC = gcc

SRCS := $(wildcard *.c)
OBJDIR = ../build
OBJS := $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra

.PHONY: clean

all: $(TARGET)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(LDLIBS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)
