CC = g++
CFLAGS = -pedantic-errors -std=c++11
SRC = game1.cpp game2.cpp game3.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)
EXEC = main

# Check for Windows
ifeq ($(OS),Windows_NT)
	RM = del /F /Q
else
	UNAME_S := $(shell uname -s)
	# Check for macOS
	ifeq ($(UNAME_S),Darwin)
		RM = rm -f
	# Check for Linux
	else ifeq ($(UNAME_S),Linux)
		RM = rm -f
	endif
endif

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEP) $(EXEC)
.PHONY: clean

