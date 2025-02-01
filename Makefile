CC = g++
CFLAGS = -std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = pentaflake.hpp
OBJECTS = main.o pentaflake.o
PROGRAM = Penta

.PHONY: all clean lint

all: $(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm -f *.o $(PROGRAM)

lint:
	cpplint *.cpp *.hpp
