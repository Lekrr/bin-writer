CC=gcc
CFLAGS=

TARGET=bin-writer

SRCS=bin-writer.c
OBJS=$(SRCS:.c=.o)

all: lib$(TARGET).a

test: test.o lib$(TARGET).a
	$(CC) -L. test.o -l$(TARGET) -o $@ $(CFLAGS)

lib$(TARGET).a: $(OBJS)
	ar rcs lib$(TARGET).a $(OBJS)

%.o: %.c
	$(CC) $< -o $@ -c $(CFLAGS)

clean:
	rm -rf *.o lib$(TARGET).a test
