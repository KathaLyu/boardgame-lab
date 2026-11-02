CC ?= cc
CPPFLAGS ?=
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS ?=
LDLIBS ?=

BUILD_DIR := build
TARGET := $(BUILD_DIR)/main
SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst src/%.c,$(BUILD_DIR)/src/%.o,$(SOURCES))
LAB1_TARGET := $(BUILD_DIR)/lab1

.PHONY: all run lab1 lab1-demo clean

# 默认构建主程序
all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BUILD_DIR)/src/%.o: src/%.c | $(BUILD_DIR)/src
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/src:
	mkdir -p $@

# 运行主程序
run: $(TARGET)
	./$(TARGET)

# 构建 Lab 1 的井字棋
lab1: $(LAB1_TARGET)

$(LAB1_TARGET): lab1/main.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@

# 交互式运行 Lab 1
lab1-demo: $(LAB1_TARGET)
	./$(LAB1_TARGET)

# 清理构建产物
clean:
	rm -rf $(BUILD_DIR)
