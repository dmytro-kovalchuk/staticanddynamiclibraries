CC = gcc
CFLAGS = -Wall -Werror -Wextra

CALC_DIR = ./task1
BUILD_DIR = ./build

CALC_SRC = $(wildcard $(CALC_DIR)/*.c)
CALC_OBJ = $(patsubst $(CALC_DIR)/%.c, $(BUILD_DIR)/%.o, $(CALC_SRC))

CALC_LIB = libcalc.a

CALC_EXEC = $(BUILD_DIR)/calc



all: $(CALC_EXEC)

$(BUILD_DIR):
	mkdir -p $@

$(CALC_EXEC): $(CALC_LIB)
	$(CC) $(CALC_DIR)/main.c -L . -l calc -o $(CALC_EXEC)

$(BUILD_DIR)/%.c: $(CALC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CALC_LIB): $(CALC_OBJ)
	ar -rc $@ $^
	ranlib $@

clean:
	rm -rf $(BUILD_DIR) $(CALC_LIB)
