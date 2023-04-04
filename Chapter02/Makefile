CC = g++
TARGET = 02
OBJS = Actor.o AnimSpriteComponent.o BGSpriteComponent.o Component.o Game.o Main.o Math.o Ship.o SpriteComponent.o

CXXFLAGS = -O2 -Wall `sdl2-config --cflags`
LIBS = `sdl2-config --libs` -lSDL2_image

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf *.o $(TARGET)

.PHONY: run
run:
	./$(TARGET)

$(TARGET): $(OBJS) Makefile
	$(CC) $(OBJS) $(LIBS) -o $@

%.o: %.cpp Makefile
	$(CC) $(CXXFLAGS) -c $<