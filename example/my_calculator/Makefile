CC = gcc
CFLAGS = -g
# 定义链接选项：-lm 是为了链接 math.h 库（计算器经常用到）
LDFLAGS = -lm

# 自动获取当前目录下所有的 .c 文件
SRCS = $(wildcard *.c)
# 将 .c 文件列表转换为 .o (对象文件) 列表
OBJS = $(SRCS:.c=.o)
# 定义最终生成的可执行文件名
TARGET = calculator

# 默认目标
all: $(TARGET)

# 链接步骤：将所有 .o 文件链接成最终的可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# 编译步骤：将每个 .c 文件编译成 .o 文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理命令：输入 make clean 可以删除生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean