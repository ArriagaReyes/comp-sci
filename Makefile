NAME=executable
SRC_DIRS=./src ./questions
INCLUDE_DIR=./include
BUILD_DIR=build
BIN_DIR=bin
CC=gcc

DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -g $(foreach D, $(INCLUDE_DIR), -I$(D)) $(DEPFLAGS) 

CFILES=$(foreach D, $(SRC_DIRS), $(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c,%.o, $(CFILES))

all: $(NAME)

$(NAME): dir $(OBJECTS)
	@$(CC) -o $(BIN_DIR)/$@ $(patsubst %, build/%, $(OBJECTS))

$(OBJECTS): dir
	@mkdir -p $(BUILD_DIR)/$(@D)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ -c $*.c

dir:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
