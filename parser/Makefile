CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc # Isrc means search src directory 

CORE_SRCS = src/utils.c # add more source files here
CORE_OBJS = $(CORE_SRCS:.c=.o) # suffix replacement, replace .c with .o

APP_MAIN = src/main.c 
APP_TARGET = app

TEST_MAIN = src/test.c 
TEST_TARGET = run_test

.PHONY: all clean test

all: $(APP_TARGET)

# 编译应用：链接应用的 main 和核心功能
$(APP_TARGET): $(APP_MAIN) $(CORE_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# 编译测试：链接测试的 main 和核心功能
$(TEST_TARGET): $(TEST_MAIN) $(CORE_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# 自动化测试目标：编译并顺便运行测试
test: $(TEST_TARGET)
	@echo "============= 运行测试 ============="
	./$(TEST_TARGET)
	@echo "===================================="

# 通用的 .c 到 .o 编译规则
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(APP_TARGET) $(TEST_TARGET) src/*.o tests/*.o
