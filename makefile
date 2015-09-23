OS=$(shell uname)

CC=g++
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst src/%,build/%,$(SOURCES:.cpp=.o))

ifeq ($(OS),Darwin)
OUTPUT=ichor
CFLAGS=-c -Wall -Isdl/osx/SDL2.framework/Headers
LFLAGS=-Wall -Fsdl/osx/ -framework SDL2 -framework OpenGL
else
OUTPUT=ichor.exe
CFLAGS=-c -Wall -Isdl/windows/include
LFLAGS=-Wall -Lsdl/windows/lib/x64 -lSDL -lSDLmain -lopengl32
endif

ichor: $(OBJECTS)
	$(CC) $(LFLAGS) -o $(OUTPUT) $(OBJECTS)

$(OBJECTS) : build/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm /build/*o
