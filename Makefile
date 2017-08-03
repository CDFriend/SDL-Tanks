CC = g++
CFLAGS = -g
EXEC = main

OBJS = bin/main.o bin/tanks_game.o bin/tank.o
LIBS = -lSDL2 -lSDL2_image

all: $(OBJS)
	$(CC) $(LIBS) $(CFLAGS) $(OBJS) -o $(EXEC)

bin/%.o : src/%.cpp
	mkdir -p bin
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	rm -rf bin/ $(EXEC)