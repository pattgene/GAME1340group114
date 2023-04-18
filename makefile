CC=g++
CFLAGS=-pedantic-errors -std=c++11
SRC=game1.cpp game2.cpp game3.cpp main.cpp
OBJ=$(SRC:.cpp=.o)
EXEC=main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
.PHONY: clean
