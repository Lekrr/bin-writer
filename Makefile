CC=gcc
CFLAGS=-g

TARGET=bin-writer
SRCS=bin-writer.c buf.c

BUILD_DIR=build
LIB_DIR=lib
BIN_DIR=bin

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)
FULL_TARGET=$(LIB_DIR)/lib$(TARGET).a

.PHONY: test

all: $(FULL_TARGET)

test: $(BUILD_DIR)/test.o $(FULL_TARGET)
	$(CC) -L$(LIB_DIR) $(BUILD_DIR)/test.o -l$(TARGET) -o $(BIN_DIR)/$@ $(CFLAGS)

$(FULL_TARGET): $(OBJS)
	ar rcs $(FULL_TARGET) $(OBJS)

$(BUILD_DIR)/%.o: %.c
	$(CC) $< -o $@ -c $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)/* $(LIB_DIR)/* $(BIN_DIR)/*
