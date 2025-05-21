CC=/usr/bin/gcc
BUILD_DIR=./build
NAME=t2b
CFLAGS=-D_XOPEN_SOURCE -g

$(NAME): $(NAME).c
	if [ ! -e $(BUILD_DIR) ]; then \
		mkdir $(BUILD_DIR); \
	fi
	$(CC) -o $(BUILD_DIR)/$@ $@.c $(CFLAGS)
