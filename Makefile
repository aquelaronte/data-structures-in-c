# Folders structure
SOURCE_FOLDER=src
BINARY_FOLDER=bin
OBJECTS_FOLDER=obj
INCLUDE_FOLDER=include

# Compiler configuration
COMPILER=gcc
INCLUDE= -I$(INCLUDE_FOLDER)
FLAGS= -Wall -Wextra -O2

# Files with code written on .c
SOURCE_FILES=$(wildcard $(SOURCE_FOLDER)/*.c) $(wildcard $(SOURCE_FOLDER)/*/*.c)

# Generated files with .o extension generated from .c code
# Takes all the files from SOURCE_FILES that matches with the pattern SOURCE_FOLDER/%.c and convert it to OBJECTS_FOLDER/%.o
# example: src/main.c -> src/main.o | obj/subdir/file.c -> obj/subdir/file.o
OBJECT_FILES=$(SOURCE_FILES:$(SOURCE_FOLDER)/%.c=$(OBJECTS_FOLDER)/%.o)

# Target file
TARGET=$(BINARY_FOLDER)/main

all: directories $(TARGET)

# Target for creating folders for generated files if this doesn't exists
directories:
	@mkdir -p $(BINARY_FOLDER)
	@mkdir -p $(OBJECTS_FOLDER)
	@mkdir -p $(OBJECTS_FOLDER)/linked_list
	@mkdir -p $(OBJECTS_FOLDER)/tests
	
# Compiles the main binary file by taking the following parameters
# $@ : target's name
# $^ : target's dependencies
# an example of this execution can be
# 
# gcc -Wall -Wextra -O2 -o bin/main obj/main.o obj/tests/linked_list.o ... (all the objects files) 
$(TARGET): $(OBJECT_FILES)
	@$(COMPILER) $(FLAGS) -o $@ $^

# Compiles the object files by taking the following parameters
# $@ : target's name
# $< : current target matching dependency
# An example of this execution can be
# 
# gcc -Wall -Wextra -O2 -o -Iinclude -c 
$(OBJECTS_FOLDER)/%.o: $(SOURCE_FOLDER)/%.c
	@mkdir -p $(@D)
	$(COMPILER) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(BINARY_FOLDER) $(OBJECTS_FOLDER)

run:
	$(BINARY_FOLDER)/main

.PHONY: clean run
