CC = gcc
CFLAGS = -Wall -Werror -Wextra

CALC_DIR = ./task1
FORMAT_DIR = ./task2

BUILD_DIR = ./build
CALC_BUILD_DIR = $(BUILD_DIR)/$(CALC_DIR)
FORMAT_BUILD_DIR = $(BUILD_DIR)/$(FORMAT_DIR)

CALC_SRC = $(wildcard $(CALC_DIR)/*.c)
CALC_OBJ = $(patsubst $(CALC_DIR)/%.c, $(CALC_BUILD_DIR)/%.o, $(CALC_SRC))
FORMAT_SRC = $(wildcard $(FORMAT_DIR)/*.c)
FORMAT_OBJ = $(patsubst $(FORMAT_DIR)/%.c, $(FORMAT_BUILD_DIR)/%.o, $(FORMAT_SRC))

CALC_LIB = libcalc.a
FORMAT_LIB = libformat.so

CALC_EXEC = $(CALC_BUILD_DIR)/calc
FORMAT_EXEC = $(FORMAT_BUILD_DIR)/format



calc: $(CALC_BUILD_DIR) $(CALC_EXEC)
format: $(FORMAT_BUILD_DIR) $(FORMAT_EXEC)

$(CALC_BUILD_DIR) $(FORMAT_BUILD_DIR):
	mkdir -p $@

$(CALC_EXEC): $(CALC_LIB)
	$(CC) $(CALC_DIR)/main.c -l calc -o $@

$(CALC_BUILD_DIR)/%.o: $(CALC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CALC_LIB): $(CALC_OBJ)
	ar -rc $@ $^
	ranlib $@

$(FORMAT_EXEC): $(FORMAT_LIB)
	$(CC) $(FORMAT_DIR)/main.c -L . -l format -o $@

$(FORMAT_BUILD_DIR)/%.o: $(FORMAT_DIR)/%.c
	$(CC) $(CFLAGS) -fpic -c $< -o $@

$(FORMAT_LIB): $(FORMAT_OBJ)
	$(CC) -shared -o $@ $^
	cp `pwd`/$(FORMAT_LIB) /usr/lib
	chmod 0755 /usr/lib/$(FORMAT_LIB)
	unset LD_LIBRARY_PATH

clean:
	rm -rf $(BUILD_DIR) $(CALC_LIB) $(FORMAT_LIB)
