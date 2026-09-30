CC         ?= gcc
CFLAGS     ?= -Wall -Wextra
BUILD_DIR  ?= build
TARGET     := $(BUILD_DIR)/main

OBJS := $(BUILD_DIR)/main.o \
        $(BUILD_DIR)/utils.o \
        $(BUILD_DIR)/states/rotate.o \
        $(BUILD_DIR)/states/stationary.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
